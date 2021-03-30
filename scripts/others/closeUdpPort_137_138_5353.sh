#!/bin/sh
set -e
sudo iptables -A INPUT -p  udp --dport 138  -j DROP
sudo iptables -A OUTPUT -p udp --dport 138  -j DROP
sudo iptables -A INPUT -p  udp --dport 137  -j DROP
sudo iptables -A OUTPUT -p udp --dport 137  -j DROP
sudo iptables -A INPUT -p  udp --dport 5353 -j DROP
sudo iptables -A OUTPUT -p udp --dport 5353 -j DROP

sudo ip6tables -A INPUT -p  udp --dport 138  -j DROP
sudo ip6tables -A OUTPUT -p udp --dport 138  -j DROP
sudo ip6tables -A INPUT -p  udp --dport 137  -j DROP
sudo ip6tables -A OUTPUT -p udp --dport 137  -j DROP
sudo ip6tables -A INPUT -p  udp --dport 5353 -j DROP
sudo ip6tables -A OUTPUT -p udp --dport 5353 -j DROP
