#!/bin/sh
pasm -b SignalInput.p
gcc main.c -o main -lpthread -lprussdrv
