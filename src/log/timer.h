/*
 * Software Development Kit for Fisilink
 * @file: timer.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __TIME_H_
#define __TIME_H_


#define MULTITHREAD

#define TIMEKEEPER_NUM    100

#ifdef __cplusplus
extern "C" {
#endif

/** start timer manually */
int timekeeper_start_man(int n);

/** start timer automatically */
int timekeeper_start_auto();

/** pause timer */
int timekeeper_pause(int thnd, double* time);

/** shutdown timer */
int timekeeper_shutoff(int thnd, double* time);

/** destory timer */
void timekeeper_destory();

#ifdef __cplusplus
}
#endif


#endif   
