#!/bin/bash
rm /lib/firmware/PRU-ONE-HZ-OUTPU-00A0.dtbo
dtc -O dtb -o /lib/firmware/SignalInput_PRU1-00A0.dtbo -b 0 -@  SignalInput_PRU1.dts

