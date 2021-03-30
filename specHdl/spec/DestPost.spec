
function DestPost(PI, MsgIgr2Adm) {
    // Ingress Vlan Filtering
    DsMemVlanPortMaskVal        = DsMemVlanPortMask[ PI.vlanId ];
    if( PI.ingressFilteringEn && !DsMemVlanPortMaskVal.portMask[ PI.srcPort:PI.srcPort ] ) {
        PI.discard              = PI.discard | 1;
        PI.vlanDiscard   = 1;
    }
    // Egress Vlan Filtering
    DsMemSrcPortEgressMaskVal   = DsMemSrcPortEgressMask[ PI.srcPort ];
    if( ((PI.vlanId < CtlFwdPortIsolate.vlanId) || CtlFwdPortIsolate.forcePortEgressMask)
        && !PI.routingEn ) {
        PI.fwdBitmap   = DsMemSrcPortEgressMaskVal.portEgressMask;
    } else {
        PI.fwdBitmap   = 8'hff;
    }
    PI.egrPortFilted  = PI.fwdBitmap == 0;
    // Intial FwdBitmap
    tmpVlanPortMask = DsMemVlanPortMaskVal.portMask | (~CtlFwdEgressFilter.egrFilteringEn);
    if( (PI.opCode != OP_CODE_MCAST) && !PI.routingEn ) {
        PI.fwdBitmap = PI.fwdBitmap & tmpVlanPortMask;
    }
    PI.egrVlanFilted = PI.fwdBitmap == 0;
    
    // Get tmpFwdingBmp
    tmpFwdingBmp       = 0;
    if( PI.opCode == OP_CODE_UCAST || PI.opCode == OP_CODE_NAT ) {
        if( PI.destMap[10:10] == 1 ) {             // Dest is LAG
            tmpIsUcastLinkAgg      = 1;
            tmpDestLinkAggId  = PI.destMap;
            tmpFwdingBmp     = 0;
        } else {
            tmpFwdingBmp     = 1 << PI.destMap;
        }
    } else if( PI.opCode == OP_CODE_MCAST ) {
        tmpGid          = PI.destMap;
        DsMemMcastPortVal    = DsMemMcastPort[ tmpGid ];
        tmpFwdingBmp         = DsMemMcastPortVal.portMask;
        if( DsMemMcastPortVal.applyVlanMask ) {
            tmpFwdingBmp     = ( (~CtlFwdMcast.mcFilteringEn | tmpVlanPortMask) & tmpFwdingBmp );
        }
        if( CtlFwdMcast.mcastExcludeSrc ) 
            tmpFwdingBmp[ PI.srcPort:PI.srcPort ] = 0;
    
        // For TSN split stream, the process table shall config as MCAST
        if( PI.isTsn ) {
            DsMemTsnSplitVal  = DsMemTsnSplit[ PI.tsnStreamId ];
            tmpFwdingBmp     = DsMemTsnSplitVal.destBmp;
        }
    
    } else {    // Broadcast
        tmpFwdingBmp         = 8'hff;
    }
    
        tmpLagFwdBmp0      = tmpFwdingBmp;
        DsRegLagGrp0Val    = DsRegLagGrp[ 0 ];      // read LAG group table
        if ( ((tmpLagFwdBmp0 & DsRegLagGrp0Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (0 == tmpDestLinkAggId)) ) && DsRegLagGrp0Val.linkNumber > 0 ) {
            tmpLagFwdBmp0 &= (~DsRegLagGrp0Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp0Val.linkNumber;
            tmpAggPtr = {0, tmpSelectIdx};
            DsRegLagPort0Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort0Val.destPort;
            tmpLagFwdBmp0[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (0 == PI.linkAggId) && DsRegLagGrp0Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp0 &= ~DsRegLagGrp0Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (0 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp0;
        }
        tmpFwdBmp &= tmpLagFwdBmp0;
    
        tmpLagFwdBmp1      = tmpFwdingBmp;
        DsRegLagGrp1Val    = DsRegLagGrp[ 1 ];      // read LAG group table
        if ( ((tmpLagFwdBmp1 & DsRegLagGrp1Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (1 == tmpDestLinkAggId)) ) && DsRegLagGrp1Val.linkNumber > 0 ) {
            tmpLagFwdBmp1 &= (~DsRegLagGrp1Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp1Val.linkNumber;
            tmpAggPtr = {1, tmpSelectIdx};
            DsRegLagPort1Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort1Val.destPort;
            tmpLagFwdBmp1[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (1 == PI.linkAggId) && DsRegLagGrp1Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp1 &= ~DsRegLagGrp1Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (1 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp1;
        }
        tmpFwdBmp &= tmpLagFwdBmp1;
    
        tmpLagFwdBmp2      = tmpFwdingBmp;
        DsRegLagGrp2Val    = DsRegLagGrp[ 2 ];      // read LAG group table
        if ( ((tmpLagFwdBmp2 & DsRegLagGrp2Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (2 == tmpDestLinkAggId)) ) && DsRegLagGrp2Val.linkNumber > 0 ) {
            tmpLagFwdBmp2 &= (~DsRegLagGrp2Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp2Val.linkNumber;
            tmpAggPtr = {2, tmpSelectIdx};
            DsRegLagPort2Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort2Val.destPort;
            tmpLagFwdBmp2[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (2 == PI.linkAggId) && DsRegLagGrp2Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp2 &= ~DsRegLagGrp2Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (2 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp2;
        }
        tmpFwdBmp &= tmpLagFwdBmp2;
    
        tmpLagFwdBmp3      = tmpFwdingBmp;
        DsRegLagGrp3Val    = DsRegLagGrp[ 3 ];      // read LAG group table
        if ( ((tmpLagFwdBmp3 & DsRegLagGrp3Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (3 == tmpDestLinkAggId)) ) && DsRegLagGrp3Val.linkNumber > 0 ) {
            tmpLagFwdBmp3 &= (~DsRegLagGrp3Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp3Val.linkNumber;
            tmpAggPtr = {3, tmpSelectIdx};
            DsRegLagPort3Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort3Val.destPort;
            tmpLagFwdBmp3[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (3 == PI.linkAggId) && DsRegLagGrp3Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp3 &= ~DsRegLagGrp3Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (3 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp3;
        }
        tmpFwdBmp &= tmpLagFwdBmp3;
    
        tmpLagFwdBmp4      = tmpFwdingBmp;
        DsRegLagGrp4Val    = DsRegLagGrp[ 4 ];      // read LAG group table
        if ( ((tmpLagFwdBmp4 & DsRegLagGrp4Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (4 == tmpDestLinkAggId)) ) && DsRegLagGrp4Val.linkNumber > 0 ) {
            tmpLagFwdBmp4 &= (~DsRegLagGrp4Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp4Val.linkNumber;
            tmpAggPtr = {4, tmpSelectIdx};
            DsRegLagPort4Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort4Val.destPort;
            tmpLagFwdBmp4[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (4 == PI.linkAggId) && DsRegLagGrp4Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp4 &= ~DsRegLagGrp4Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (4 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp4;
        }
        tmpFwdBmp &= tmpLagFwdBmp4;
    
        tmpLagFwdBmp5      = tmpFwdingBmp;
        DsRegLagGrp5Val    = DsRegLagGrp[ 5 ];      // read LAG group table
        if ( ((tmpLagFwdBmp5 & DsRegLagGrp5Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (5 == tmpDestLinkAggId)) ) && DsRegLagGrp5Val.linkNumber > 0 ) {
            tmpLagFwdBmp5 &= (~DsRegLagGrp5Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp5Val.linkNumber;
            tmpAggPtr = {5, tmpSelectIdx};
            DsRegLagPort5Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort5Val.destPort;
            tmpLagFwdBmp5[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (5 == PI.linkAggId) && DsRegLagGrp5Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp5 &= ~DsRegLagGrp5Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (5 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp5;
        }
        tmpFwdBmp &= tmpLagFwdBmp5;
    
        tmpLagFwdBmp6      = tmpFwdingBmp;
        DsRegLagGrp6Val    = DsRegLagGrp[ 6 ];      // read LAG group table
        if ( ((tmpLagFwdBmp6 & DsRegLagGrp6Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (6 == tmpDestLinkAggId)) ) && DsRegLagGrp6Val.linkNumber > 0 ) {
            tmpLagFwdBmp6 &= (~DsRegLagGrp6Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp6Val.linkNumber;
            tmpAggPtr = {6, tmpSelectIdx};
            DsRegLagPort6Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort6Val.destPort;
            tmpLagFwdBmp6[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (6 == PI.linkAggId) && DsRegLagGrp6Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp6 &= ~DsRegLagGrp6Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (6 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp6;
        }
        tmpFwdBmp &= tmpLagFwdBmp6;
    
        tmpLagFwdBmp7      = tmpFwdingBmp;
        DsRegLagGrp7Val    = DsRegLagGrp[ 7 ];      // read LAG group table
        if ( ((tmpLagFwdBmp7 & DsRegLagGrp7Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (7 == tmpDestLinkAggId)) ) && DsRegLagGrp7Val.linkNumber > 0 ) {
            tmpLagFwdBmp7 &= (~DsRegLagGrp7Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp7Val.linkNumber;
            tmpAggPtr = {7, tmpSelectIdx};
            DsRegLagPort7Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort7Val.destPort;
            tmpLagFwdBmp7[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (7 == PI.linkAggId) && DsRegLagGrp7Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp7 &= ~DsRegLagGrp7Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (7 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp7;
        }
        tmpFwdBmp &= tmpLagFwdBmp7;
    
        tmpLagFwdBmp8      = tmpFwdingBmp;
        DsRegLagGrp8Val    = DsRegLagGrp[ 8 ];      // read LAG group table
        if ( ((tmpLagFwdBmp8 & DsRegLagGrp8Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (8 == tmpDestLinkAggId)) ) && DsRegLagGrp8Val.linkNumber > 0 ) {
            tmpLagFwdBmp8 &= (~DsRegLagGrp8Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp8Val.linkNumber;
            tmpAggPtr = {8, tmpSelectIdx};
            DsRegLagPort8Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort8Val.destPort;
            tmpLagFwdBmp8[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (8 == PI.linkAggId) && DsRegLagGrp8Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp8 &= ~DsRegLagGrp8Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (8 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp8;
        }
        tmpFwdBmp &= tmpLagFwdBmp8;
    
        tmpLagFwdBmp9      = tmpFwdingBmp;
        DsRegLagGrp9Val    = DsRegLagGrp[ 9 ];      // read LAG group table
        if ( ((tmpLagFwdBmp9 & DsRegLagGrp9Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (9 == tmpDestLinkAggId)) ) && DsRegLagGrp9Val.linkNumber > 0 ) {
            tmpLagFwdBmp9 &= (~DsRegLagGrp9Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp9Val.linkNumber;
            tmpAggPtr = {9, tmpSelectIdx};
            DsRegLagPort9Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort9Val.destPort;
            tmpLagFwdBmp9[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (9 == PI.linkAggId) && DsRegLagGrp9Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp9 &= ~DsRegLagGrp9Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (9 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp9;
        }
        tmpFwdBmp &= tmpLagFwdBmp9;
    
        tmpLagFwdBmp10      = tmpFwdingBmp;
        DsRegLagGrp10Val    = DsRegLagGrp[ 10 ];      // read LAG group table
        if ( ((tmpLagFwdBmp10 & DsRegLagGrp10Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (10 == tmpDestLinkAggId)) ) && DsRegLagGrp10Val.linkNumber > 0 ) {
            tmpLagFwdBmp10 &= (~DsRegLagGrp10Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp10Val.linkNumber;
            tmpAggPtr = {10, tmpSelectIdx};
            DsRegLagPort10Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort10Val.destPort;
            tmpLagFwdBmp10[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (10 == PI.linkAggId) && DsRegLagGrp10Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp10 &= ~DsRegLagGrp10Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (10 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp10;
        }
        tmpFwdBmp &= tmpLagFwdBmp10;
    
        tmpLagFwdBmp11      = tmpFwdingBmp;
        DsRegLagGrp11Val    = DsRegLagGrp[ 11 ];      // read LAG group table
        if ( ((tmpLagFwdBmp11 & DsRegLagGrp11Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (11 == tmpDestLinkAggId)) ) && DsRegLagGrp11Val.linkNumber > 0 ) {
            tmpLagFwdBmp11 &= (~DsRegLagGrp11Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp11Val.linkNumber;
            tmpAggPtr = {11, tmpSelectIdx};
            DsRegLagPort11Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort11Val.destPort;
            tmpLagFwdBmp11[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (11 == PI.linkAggId) && DsRegLagGrp11Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp11 &= ~DsRegLagGrp11Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (11 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp11;
        }
        tmpFwdBmp &= tmpLagFwdBmp11;
    
        tmpLagFwdBmp12      = tmpFwdingBmp;
        DsRegLagGrp12Val    = DsRegLagGrp[ 12 ];      // read LAG group table
        if ( ((tmpLagFwdBmp12 & DsRegLagGrp12Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (12 == tmpDestLinkAggId)) ) && DsRegLagGrp12Val.linkNumber > 0 ) {
            tmpLagFwdBmp12 &= (~DsRegLagGrp12Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp12Val.linkNumber;
            tmpAggPtr = {12, tmpSelectIdx};
            DsRegLagPort12Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort12Val.destPort;
            tmpLagFwdBmp12[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (12 == PI.linkAggId) && DsRegLagGrp12Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp12 &= ~DsRegLagGrp12Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (12 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp12;
        }
        tmpFwdBmp &= tmpLagFwdBmp12;
    
        tmpLagFwdBmp13      = tmpFwdingBmp;
        DsRegLagGrp13Val    = DsRegLagGrp[ 13 ];      // read LAG group table
        if ( ((tmpLagFwdBmp13 & DsRegLagGrp13Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (13 == tmpDestLinkAggId)) ) && DsRegLagGrp13Val.linkNumber > 0 ) {
            tmpLagFwdBmp13 &= (~DsRegLagGrp13Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp13Val.linkNumber;
            tmpAggPtr = {13, tmpSelectIdx};
            DsRegLagPort13Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort13Val.destPort;
            tmpLagFwdBmp13[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (13 == PI.linkAggId) && DsRegLagGrp13Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp13 &= ~DsRegLagGrp13Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (13 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp13;
        }
        tmpFwdBmp &= tmpLagFwdBmp13;
    
        tmpLagFwdBmp14      = tmpFwdingBmp;
        DsRegLagGrp14Val    = DsRegLagGrp[ 14 ];      // read LAG group table
        if ( ((tmpLagFwdBmp14 & DsRegLagGrp14Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (14 == tmpDestLinkAggId)) ) && DsRegLagGrp14Val.linkNumber > 0 ) {
            tmpLagFwdBmp14 &= (~DsRegLagGrp14Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp14Val.linkNumber;
            tmpAggPtr = {14, tmpSelectIdx};
            DsRegLagPort14Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort14Val.destPort;
            tmpLagFwdBmp14[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (14 == PI.linkAggId) && DsRegLagGrp14Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp14 &= ~DsRegLagGrp14Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (14 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp14;
        }
        tmpFwdBmp &= tmpLagFwdBmp14;
    
        tmpLagFwdBmp15      = tmpFwdingBmp;
        DsRegLagGrp15Val    = DsRegLagGrp[ 15 ];      // read LAG group table
        if ( ((tmpLagFwdBmp15 & DsRegLagGrp15Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (15 == tmpDestLinkAggId)) ) && DsRegLagGrp15Val.linkNumber > 0 ) {
            tmpLagFwdBmp15 &= (~DsRegLagGrp15Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp15Val.linkNumber;
            tmpAggPtr = {15, tmpSelectIdx};
            DsRegLagPort15Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort15Val.destPort;
            tmpLagFwdBmp15[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (15 == PI.linkAggId) && DsRegLagGrp15Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp15 &= ~DsRegLagGrp15Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (15 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp15;
        }
        tmpFwdBmp &= tmpLagFwdBmp15;
    
        tmpLagFwdBmp16      = tmpFwdingBmp;
        DsRegLagGrp16Val    = DsRegLagGrp[ 16 ];      // read LAG group table
        if ( ((tmpLagFwdBmp16 & DsRegLagGrp16Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (16 == tmpDestLinkAggId)) ) && DsRegLagGrp16Val.linkNumber > 0 ) {
            tmpLagFwdBmp16 &= (~DsRegLagGrp16Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp16Val.linkNumber;
            tmpAggPtr = {16, tmpSelectIdx};
            DsRegLagPort16Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort16Val.destPort;
            tmpLagFwdBmp16[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (16 == PI.linkAggId) && DsRegLagGrp16Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp16 &= ~DsRegLagGrp16Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (16 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp16;
        }
        tmpFwdBmp &= tmpLagFwdBmp16;
    
        tmpLagFwdBmp17      = tmpFwdingBmp;
        DsRegLagGrp17Val    = DsRegLagGrp[ 17 ];      // read LAG group table
        if ( ((tmpLagFwdBmp17 & DsRegLagGrp17Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (17 == tmpDestLinkAggId)) ) && DsRegLagGrp17Val.linkNumber > 0 ) {
            tmpLagFwdBmp17 &= (~DsRegLagGrp17Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp17Val.linkNumber;
            tmpAggPtr = {17, tmpSelectIdx};
            DsRegLagPort17Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort17Val.destPort;
            tmpLagFwdBmp17[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (17 == PI.linkAggId) && DsRegLagGrp17Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp17 &= ~DsRegLagGrp17Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (17 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp17;
        }
        tmpFwdBmp &= tmpLagFwdBmp17;
    
        tmpLagFwdBmp18      = tmpFwdingBmp;
        DsRegLagGrp18Val    = DsRegLagGrp[ 18 ];      // read LAG group table
        if ( ((tmpLagFwdBmp18 & DsRegLagGrp18Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (18 == tmpDestLinkAggId)) ) && DsRegLagGrp18Val.linkNumber > 0 ) {
            tmpLagFwdBmp18 &= (~DsRegLagGrp18Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp18Val.linkNumber;
            tmpAggPtr = {18, tmpSelectIdx};
            DsRegLagPort18Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort18Val.destPort;
            tmpLagFwdBmp18[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (18 == PI.linkAggId) && DsRegLagGrp18Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp18 &= ~DsRegLagGrp18Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (18 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp18;
        }
        tmpFwdBmp &= tmpLagFwdBmp18;
    
        tmpLagFwdBmp19      = tmpFwdingBmp;
        DsRegLagGrp19Val    = DsRegLagGrp[ 19 ];      // read LAG group table
        if ( ((tmpLagFwdBmp19 & DsRegLagGrp19Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (19 == tmpDestLinkAggId)) ) && DsRegLagGrp19Val.linkNumber > 0 ) {
            tmpLagFwdBmp19 &= (~DsRegLagGrp19Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp19Val.linkNumber;
            tmpAggPtr = {19, tmpSelectIdx};
            DsRegLagPort19Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort19Val.destPort;
            tmpLagFwdBmp19[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (19 == PI.linkAggId) && DsRegLagGrp19Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp19 &= ~DsRegLagGrp19Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (19 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp19;
        }
        tmpFwdBmp &= tmpLagFwdBmp19;
    
        tmpLagFwdBmp20      = tmpFwdingBmp;
        DsRegLagGrp20Val    = DsRegLagGrp[ 20 ];      // read LAG group table
        if ( ((tmpLagFwdBmp20 & DsRegLagGrp20Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (20 == tmpDestLinkAggId)) ) && DsRegLagGrp20Val.linkNumber > 0 ) {
            tmpLagFwdBmp20 &= (~DsRegLagGrp20Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp20Val.linkNumber;
            tmpAggPtr = {20, tmpSelectIdx};
            DsRegLagPort20Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort20Val.destPort;
            tmpLagFwdBmp20[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (20 == PI.linkAggId) && DsRegLagGrp20Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp20 &= ~DsRegLagGrp20Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (20 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp20;
        }
        tmpFwdBmp &= tmpLagFwdBmp20;
    
        tmpLagFwdBmp21      = tmpFwdingBmp;
        DsRegLagGrp21Val    = DsRegLagGrp[ 21 ];      // read LAG group table
        if ( ((tmpLagFwdBmp21 & DsRegLagGrp21Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (21 == tmpDestLinkAggId)) ) && DsRegLagGrp21Val.linkNumber > 0 ) {
            tmpLagFwdBmp21 &= (~DsRegLagGrp21Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp21Val.linkNumber;
            tmpAggPtr = {21, tmpSelectIdx};
            DsRegLagPort21Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort21Val.destPort;
            tmpLagFwdBmp21[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (21 == PI.linkAggId) && DsRegLagGrp21Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp21 &= ~DsRegLagGrp21Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (21 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp21;
        }
        tmpFwdBmp &= tmpLagFwdBmp21;
    
        tmpLagFwdBmp22      = tmpFwdingBmp;
        DsRegLagGrp22Val    = DsRegLagGrp[ 22 ];      // read LAG group table
        if ( ((tmpLagFwdBmp22 & DsRegLagGrp22Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (22 == tmpDestLinkAggId)) ) && DsRegLagGrp22Val.linkNumber > 0 ) {
            tmpLagFwdBmp22 &= (~DsRegLagGrp22Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp22Val.linkNumber;
            tmpAggPtr = {22, tmpSelectIdx};
            DsRegLagPort22Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort22Val.destPort;
            tmpLagFwdBmp22[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (22 == PI.linkAggId) && DsRegLagGrp22Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp22 &= ~DsRegLagGrp22Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (22 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp22;
        }
        tmpFwdBmp &= tmpLagFwdBmp22;
    
        tmpLagFwdBmp23      = tmpFwdingBmp;
        DsRegLagGrp23Val    = DsRegLagGrp[ 23 ];      // read LAG group table
        if ( ((tmpLagFwdBmp23 & DsRegLagGrp23Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (23 == tmpDestLinkAggId)) ) && DsRegLagGrp23Val.linkNumber > 0 ) {
            tmpLagFwdBmp23 &= (~DsRegLagGrp23Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp23Val.linkNumber;
            tmpAggPtr = {23, tmpSelectIdx};
            DsRegLagPort23Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort23Val.destPort;
            tmpLagFwdBmp23[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (23 == PI.linkAggId) && DsRegLagGrp23Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp23 &= ~DsRegLagGrp23Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (23 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp23;
        }
        tmpFwdBmp &= tmpLagFwdBmp23;
    
        tmpLagFwdBmp24      = tmpFwdingBmp;
        DsRegLagGrp24Val    = DsRegLagGrp[ 24 ];      // read LAG group table
        if ( ((tmpLagFwdBmp24 & DsRegLagGrp24Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (24 == tmpDestLinkAggId)) ) && DsRegLagGrp24Val.linkNumber > 0 ) {
            tmpLagFwdBmp24 &= (~DsRegLagGrp24Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp24Val.linkNumber;
            tmpAggPtr = {24, tmpSelectIdx};
            DsRegLagPort24Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort24Val.destPort;
            tmpLagFwdBmp24[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (24 == PI.linkAggId) && DsRegLagGrp24Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp24 &= ~DsRegLagGrp24Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (24 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp24;
        }
        tmpFwdBmp &= tmpLagFwdBmp24;
    
        tmpLagFwdBmp25      = tmpFwdingBmp;
        DsRegLagGrp25Val    = DsRegLagGrp[ 25 ];      // read LAG group table
        if ( ((tmpLagFwdBmp25 & DsRegLagGrp25Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (25 == tmpDestLinkAggId)) ) && DsRegLagGrp25Val.linkNumber > 0 ) {
            tmpLagFwdBmp25 &= (~DsRegLagGrp25Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp25Val.linkNumber;
            tmpAggPtr = {25, tmpSelectIdx};
            DsRegLagPort25Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort25Val.destPort;
            tmpLagFwdBmp25[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (25 == PI.linkAggId) && DsRegLagGrp25Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp25 &= ~DsRegLagGrp25Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (25 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp25;
        }
        tmpFwdBmp &= tmpLagFwdBmp25;
    
        tmpLagFwdBmp26      = tmpFwdingBmp;
        DsRegLagGrp26Val    = DsRegLagGrp[ 26 ];      // read LAG group table[ tmpLagDestPort:tmpLagDestPort ] 
        if ( ((tmpLagFwdBmp26 & DsRegLagGrp26Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (26 == tmpDestLinkAggId)) ) && DsRegLagGrp26Val.linkNumber > 0 ) {
            tmpLagFwdBmp26 &= (~DsRegLagGrp26Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp26Val.linkNumber;
            tmpAggPtr = {26, tmpSelectIdx};
            DsRegLagPort26Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort26Val.destPort;
            tmpLagFwdBmp26[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (26 == PI.linkAggId) && DsRegLagGrp26Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp26 &= ~DsRegLagGrp26Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (26 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp26;
        }
        tmpFwdBmp &= tmpLagFwdBmp26;
    
        tmpLagFwdBmp27      = tmpFwdingBmp;
        DsRegLagGrp27Val    = DsRegLagGrp[ 27 ];      // read LAG group table
        if ( ((tmpLagFwdBmp27 & DsRegLagGrp27Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (27 == tmpDestLinkAggId)) ) && DsRegLagGrp27Val.linkNumber > 0 ) {
            tmpLagFwdBmp27 &= (~DsRegLagGrp27Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp27Val.linkNumber;
            tmpAggPtr = {27, tmpSelectIdx};
            DsRegLagPort27Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort27Val.destPort;
            tmpLagFwdBmp27[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (27 == PI.linkAggId) && DsRegLagGrp27Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp27 &= ~DsRegLagGrp27Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (27 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp27;
        }
        tmpFwdBmp &= tmpLagFwdBmp27;
    
        tmpLagFwdBmp28      = tmpFwdingBmp;
        DsRegLagGrp28Val    = DsRegLagGrp[ 28 ];      // read LAG group table
        if ( ((tmpLagFwdBmp28 & DsRegLagGrp28Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (28 == tmpDestLinkAggId)) ) && DsRegLagGrp28Val.linkNumber > 0 ) {
            tmpLagFwdBmp28 &= (~DsRegLagGrp28Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp28Val.linkNumber;
            tmpAggPtr = {28, tmpSelectIdx};
            DsRegLagPort28Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort28Val.destPort;
            tmpLagFwdBmp28[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (28 == PI.linkAggId) && DsRegLagGrp28Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp28 &= ~DsRegLagGrp28Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (28 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp28;
        }
        tmpFwdBmp &= tmpLagFwdBmp28;
    
        tmpLagFwdBmp29      = tmpFwdingBmp;
        DsRegLagGrp29Val    = DsRegLagGrp[ 29 ];      // read LAG group table
        if ( ((tmpLagFwdBmp29 & DsRegLagGrp29Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (29 == tmpDestLinkAggId)) ) && DsRegLagGrp29Val.linkNumber > 0 ) {
            tmpLagFwdBmp29 &= (~DsRegLagGrp29Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp29Val.linkNumber;
            tmpAggPtr = {29, tmpSelectIdx};
            DsRegLagPort29Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort29Val.destPort;
            tmpLagFwdBmp29[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (29 == PI.linkAggId) && DsRegLagGrp29Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp29 &= ~DsRegLagGrp29Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (29 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp29;
        }
        tmpFwdBmp &= tmpLagFwdBmp29;
    
        tmpLagFwdBmp30      = tmpFwdingBmp;
        DsRegLagGrp30Val    = DsRegLagGrp[ 30 ];      // read LAG group table
        if ( ((tmpLagFwdBmp30 & DsRegLagGrp30Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (30 == tmpDestLinkAggId)) ) && DsRegLagGrp30Val.linkNumber > 0 ) {
            tmpLagFwdBmp30 &= (~DsRegLagGrp30Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp30Val.linkNumber;
            tmpAggPtr = {30, tmpSelectIdx};
            DsRegLagPort30Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort30Val.destPort;
            tmpLagFwdBmp30 |= (1 << tmpLagDestPort);
        }
        if ( PI.isLinkAggMbr && (30 == PI.linkAggId) && DsRegLagGrp30Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp30 &= ~DsRegLagGrp30Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (30 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp30;
        }
        tmpFwdBmp &= tmpLagFwdBmp30;
    
        tmpLagFwdBmp31      = tmpFwdingBmp;
        DsRegLagGrp31Val    = DsRegLagGrp[ 31 ];      // read LAG group table
        if ( ((tmpLagFwdBmp31 & DsRegLagGrp31Val.memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (31 == tmpDestLinkAggId)) ) && DsRegLagGrp31Val.linkNumber > 0 ) {
            tmpLagFwdBmp31 &= (~DsRegLagGrp31Val.memberBitmap);
            tmpSelectIdx = PI.linkAggHash % DsRegLagGrp31Val.linkNumber;
            tmpAggPtr = {31, tmpSelectIdx};
            DsRegLagPort31Val = DsRegLagPort[ tmpAggPtr ];
            tmpLagDestPort = DsRegLagPort31Val.destPort;
            tmpLagFwdBmp31[ tmpLagDestPort:tmpLagDestPort ] = 1;
        }
        if ( PI.isLinkAggMbr && (31 == PI.linkAggId) && DsRegLagGrp31Val.srcMatchDiscard &&
        !PI.routingEn && !PI.forceDest ) {
            tmpLagFwdBmp31 &= ~DsRegLagGrp31Val.memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (31 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp31;
        }
        tmpFwdBmp &= tmpLagFwdBmp31;
    
    if ( !tmpIsUcastLinkAgg ) {
        tmpFwdingBmp &= tmpFwdBmp;
    } else {
        tmpFwdingBmp  = tmpUcastLagFwdBmp;
    }
    
    PI.lagFilted  = tmpFwdingBmp == 0;
        
    // Discard and force destination
    if( PI.forceDest ) {
        PI.fwdBitmap   = tmpFwdingBmp;
    } else {
        if( PI.discard && !PI.fromRemoteSpan ) {
            PI.fwdBitmap = 0;
        } else {
            PI.fwdBitmap = PI.fwdBitmap & tmpFwdingBmp;
        }
    }
    PI.destLostInCfg = PI.fwdBitmap == 0;
    // Unknown egress Filtering
    if( (PI.opCode == OP_CODE_BCAST) && !PI.routingEn ) {
        if( PI.isBcastMac ) {
            PI.fwdBitmap = PI.fwdBitmap & (~CtlFwdUnknownFilter.bcastFilter);
        } else if( PI.isMcastMac ) {
            PI.fwdBitmap = PI.fwdBitmap & (~CtlFwdUnknownFilter.unknownMcastFilter);
            PI.mcastFlood = 1;
        } else {
            PI.fwdBitmap = PI.fwdBitmap & (~CtlFwdUnknownFilter.unknownUcastFilter);
            PI.ucastFlood = 1;
        }
    }
    // To CPU packet
    tmpExcpToCpuFlag    = PI.exception && (CtlFwdExcp.excepToCpu & (1 << PI.excpType));
    if( (tmpExcpToCpuFlag || PI.copyToCpu) && !PI.fromRemoteSpan ) {
        PI.fwdBitmap[CtlCommon.cpuPortNo:CtlCommon.cpuPortNo]     = 1;
        PI.criticalPacket          = 1;
        PI.firstDecideToCpu          = 1;
    }
    
    PI.ptpValid = PI.isPtp && PI.ptpEn;
    if(PI.ptpValid && PI.srcPort != CtlCommon.cpuPortNo && PI.srcPort != 6 ) {
        if( (CtlFwdDest.redirPtpType & (1 << PI.ptpType)) != 0 ) {
            PI.fwdBitmap     = 0;
            PI.redirPtp      = 1;
        }
        if((CtlFwdDest.ptpSnifferType & (1 << PI.ptpType)) != 0) {
            PI.fwdBitmap[CtlCommon.cpuPortNo:CtlCommon.cpuPortNo] = 1;
            PI.criticalPacket    = 1;
            PI.firstDecideToCpu  = 1;
            PI.ptp2Cpu           = 1;
        }
    } 
    
    // SPAN bitmap
    PI.fwdBitmapW1[0:0]        = PI.ingressL2SpanEn;
    PI.fwdBitmapW1[1:1]        = (PI.fwdBitmap & CtlFwdEgressSpan.l2EgrSpanEn) != 0;
    PI.fwdBitmapW1[2:2]        = PI.l3SpanEn;
    PI.fwdBitmapW1[3:3]        = PI.aclQosLogEn;
    PI.fwdBitmapW1[4:4]        = PI.igrFlowSpan;
    // Event logger and Stats
    tmpCpuPktStatsEn  = CtlCpuStats.statsEn[ PI.cpuPktType:PI.cpuPktType ] && PI.copyToCpu && !PI.fromRemoteSpan;
    tmpExcpType[4:0] = 5'h10 + PI.excpType;
    tmpExcpPktStatsEn = CtlCpuStats.statsEn[ tmpExcpType:tmpExcpType ] && PI.exception && !PI.fromRemoteSpan;
    tmpFlowStatsPtr     = PI.flowStatsPtr;
    tmpFlowStatsValid         = PI.flowStatsValid;
    if( !PI.flowStatsValid && (tmpCpuPktStatsEn || tmpExcpPktStatsEn) ) {
        tmpTypeIdx[4:0] = tmpCpuPktStatsEn ? {0, PI.cpuPktType} : tmpExcpType;
        tmpIndex = {PI.srcPort, tmpTypeIdx[4:0]};
        DsMemCpuStatsVal = DsMemCpuStats[ tmpIndex ];
        DsMemCpuStatsVal.pktCnt += 1;
        tmpByteCnt[63:0] = {DsMemCpuStatsVal.byteCntHi, DsMemCpuStatsVal.byteCnt};
        tmpByteCnt += PI.pktLength;
        DsMemCpuStatsVal.byteCnt = tmpByteCnt;
        DsMemCpuStatsVal.byteCntHi = tmpByteCnt >> 32;
        DsMemCpuStats[ tmpIndex ] = DsMemCpuStatsVal;
    }
    
    // Remap destPort to channel ID
    tmpBitmap           = 0;
    
        if( PI.fwdBitmap[0:0] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 0 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[1:1] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 1 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[2:2] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 2 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[3:3] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 3 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[4:4] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 4 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[5:5] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 5 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[6:6] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 6 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
        if( PI.fwdBitmap[7:7] ) {
            DsRegDestPortChnlMapVal  = DsRegDestPortChnlMap[ 7 ]; 
            tmpChnlId = DsRegDestPortChnlMapVal.channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    
    PI.fwdBitmap        = tmpBitmap & 8'hff;
    
    
    if( PI.isTsn ) {
        DsMemTsnSpecVal        = DsMemTsnSpec[ PI.tsnStreamId ];
        PI.tsnGateId           = DsMemTsnSpecVal.gateId;
        PI.tsnCycleSel         = DsMemTsnSpecVal.cycleSel;
        PI.tsnPrior       = DsMemTsnSpecVal.prior;
        DsMemTsnEditVal        = DsMemTsnEdit[ PI.tsnStreamId ];
        PI.addRtag             = !PI.forbidEdit && !PI.rtagValid && DsMemTsnSpecVal.addRtag;
        if (PI.addRtag) {   
            PI.rtagSeq   = DsMemTsnEditVal.genSeqNum;
            DsMemTsnEditVal.genSeqNum  += 1;
            DsMemTsnEdit[ PI.tsnStreamId ] = DsMemTsnEditVal;
        }
    }
    PI.prior  = PI.isTsn ? PI.tsnPrior : PI.prior;
    
    CtlFwdLog.fwdBitmap = PI.fwdBitmap;
    CtlFwdLog.fwdBitmapW1 = PI.fwdBitmapW1;
    CtlFwdLog.vlanDiscard = PI.vlanDiscard;
    CtlFwdLog.mcastFlood = PI.mcastFlood;
    CtlFwdLog.destMap = PI.destMap;
    CtlFwdLog.opCode = PI.opCode;
    CtlFwdLog.ucastFlood = PI.ucastFlood;
    CtlFwdLog.criticalPacket = PI.criticalPacket;
    CtlFwdLog.forbidEdit = PI.forbidEdit;
    CtlFwdLog.redirPtp = PI.redirPtp;
    CtlFwdLog.egrPortFilted = PI.egrPortFilted;
    CtlFwdLog.egrVlanFilted = PI.egrVlanFilted;
    CtlFwdLog.lagFilted = PI.lagFilted;
    CtlFwdLog.ptpValid = PI.ptpValid;
    CtlFwdLog.ptp2Cpu = PI.ptp2Cpu;
    CtlFwdLog.addRtag = PI.addRtag;
    CtlFwdLog.tsnGateId = PI.tsnGateId;
    CtlFwdLog.tsnCycle = PI.tsnCycle;
    CtlFwdLog.cpuPktType = PI.cpuPktType;
    CtlFwdLog.destLostInCfg = PI.destLostInCfg;

    // Generate MsIgr2Adm
    //MsgIgr2Adm.fwdBitmap[7:0] = PI.fwdBitmap[7:0];
    //MsgIgr2Adm.fwdBitmapW1[5:0] = PI.fwdBitmapW1[5:0];
    //MsgIgr2Adm.pktLength[13:0] = PI.pktLength[13:0];
    //MsgIgr2Adm.nexthopIdx[5:0] = PI.nexthopIdx[5:0];
    //MsgIgr2Adm.firstDecideToCpu = PI.firstDecideToCpu;
    //MsgIgr2Adm.criticalPacket = PI.criticalPacket;
    //MsgIgr2Adm.forceDest = PI.forceDest;
    //MsgIgr2Adm.forbidEdit = PI.forbidEdit;
    //MsgIgr2Adm.removeVlanTag = PI.removeVlanTag;
    //MsgIgr2Adm.replaceCos = PI.replaceCos;
    //MsgIgr2Adm.replaceDscp = PI.replaceDscp;
    //MsgIgr2Adm.excpType[2:0] = PI.excpType[2:0];
    //MsgIgr2Adm.cpuPktType[3:0] = PI.cpuPktType[3:0];
    //MsgIgr2Adm.opCode[2:0] = PI.opCode[2:0];
    //MsgIgr2Adm.stpId[4:0] = PI.stpId[4:0];
    //MsgIgr2Adm.vlanId[11:0] = PI.vlanId[11:0];
    //MsgIgr2Adm.srcPort[2:0] = PI.srcPort[2:0];
    //MsgIgr2Adm.prior[5:0] = PI.prior[5:0];
    //MsgIgr2Adm.routingEn = PI.routingEn;
    //MsgIgr2Adm.l3Offset[5:0] = PI.l3Offset[5:0];
    //MsgIgr2Adm.l4Offset[6:0] = PI.l4Offset[6:0];
    //MsgIgr2Adm.l3Type[3:0] = PI.l3Type[3:0];
    //MsgIgr2Adm.l4Type[3:0] = PI.l4Type[3:0];
    //MsgIgr2Adm.hasInnerHdr = PI.hasInnerHdr;
    //MsgIgr2Adm.isTsn = PI.isTsn;
    //MsgIgr2Adm.tsnGateId[4:0] = PI.tsnGateId[4:0];
    //MsgIgr2Adm.tsnCycleSel[2:0] = PI.tsnCycleSel[2:0];
    //MsgIgr2Adm.addRtag = PI.addRtag;
    //MsgIgr2Adm.rtagSeq[15:0] = PI.rtagSeq[15:0];
    //MsgIgr2Adm.stagValid = PI.stagValid;
    //MsgIgr2Adm.ctagValid = PI.ctagValid;
    //MsgIgr2Adm.ptpValid = PI.ptpValid;
    //MsgIgr2Adm.ethTypeLen[3:0] = PI.ethTypeLen[3:0];
}

