#!/bin/bash
gcc -o ex2 ex2.c

cat /proc/cpuinfo | ./ex2 -a ex2.txt