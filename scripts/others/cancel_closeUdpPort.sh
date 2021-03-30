#!/bin/sh
set -e
sudo iptables -D INPUT -p  udp --dport 138  -j DROP
sudo iptables -D OUTPUT -p udp --dport 138  -j DROP
sudo iptables -D INPUT -p  udp --dport 137  -j DROP
sudo iptables -D OUTPUT -p udp --dport 137  -j DROP
sudo iptables -D INPUT -p  udp --dport 5353 -j DROP
sudo iptables -D OUTPUT -p udp --dport 5353 -j DROP

sudo ip6tables -D INPUT -p  udp --dport 138  -j DROP
sudo ip6tables -D OUTPUT -p udp --dport 138  -j DROP
sudo ip6tables -D INPUT -p  udp --dport 137  -j DROP
sudo ip6tables -D OUTPUT -p udp --dport 137  -j DROP
sudo ip6tables -D INPUT -p  udp --dport 5353 -j DROP
sudo ip6tables -D OUTPUT -p udp --dport 5353 -j DROP
