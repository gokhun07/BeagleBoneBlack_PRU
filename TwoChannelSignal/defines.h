/*
 * defines.h
 *
 *  Created on: Sep 1, 2016
 *      Author: ihsangokhun
 */

#ifndef DEFINES_H_
#define DEFINES_H_

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdint.h>
  #include <pthread.h>
  #include <prussdrv.h>
  #include <pruss_intc_mapping.h>

   #define PROG_NAME_PR0 "SignalInput_PR0.bin"
   #define PROG_NAME_PR1 "SignalInput_PR1.bin"
    #define TRUE    1


typedef enum {
	PRU_0 = 0,
	PRU_1 = 1

}PRU_TYPE;


typedef struct {
	uint8_t Pru0Ready:1;
	uint8_t Pru1Ready:1;
 }Flag;


typedef struct
  {
   unsigned   int  duty;
   unsigned   int  lowCycle;
   unsigned   int  width;
   unsigned   int  period;
   float freq;

  }Measurament;


typedef struct {

    uint32_t  valArray[3];

  }LocalPruRam;
  Flag   flag;
  LocalPruRam *pruRam_0;
  LocalPruRam *pruRam_1;
  unsigned int *pruDataMem;
#endif /* DEFINES_H_ */
