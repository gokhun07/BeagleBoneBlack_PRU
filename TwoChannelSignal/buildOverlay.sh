#!/bin/bash
rm /lib/firmware/Two-Channel-PRU0-00A0.dtbo
rm /lib/firmware/Two-Channel-PRU1-00A0.dtbo
rm /lib/firmware/Two-Channel-00A0.dtbo

dtc -O dtb -o /lib/firmware/Two-Channel-PRU0-00A0.dtbo -b 0 -@  Two-Channel-PRU0.dts
dtc -O dtb -o /lib/firmware/Two-Channel-PRU1-00A0.dtbo -b 0 -@  Two-Channel-PRU1.dts
dtc -O dtb -o /lib/firmware/Two-Channel-00A0.dtbo -b 0 -@  Two-Channel.dts
