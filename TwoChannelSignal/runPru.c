/*
 * runPru.c
 *
 *  Created on: Sep 1, 2016
 *      Author: ihsangokhun
 */

#include "defines.h"




unsigned int InitPru(PRU_TYPE PRU)
	{

	  tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

       	   	   prussdrv_init ();					     // Memory initialization for PRU subsystem driver
       	   	   prussdrv_open (PRU_EVTOUT_0);
               prussdrv_map_prumem (1,&pruDataMem);

       	   	   prussdrv_pruintc_init(&pruss_intc_initdata);

     switch (PRU) {
		case PRU_0:

					  prussdrv_map_prumem(PRUSS0_PRU0_DATARAM,(void **)&pruRam_0); // Local Ram  addressed  for PRU0
					  memset(pruRam_0-> valArray , 0 , sizeof(pruRam_0-> valArray));    //  clear RAM addresses
					  prussdrv_exec_program (PRU_0, PROG_NAME_PR0);  // execute PRU
						return 0;

			break;
		case PRU_1:

				      prussdrv_map_prumem(PRUSS0_PRU1_DATARAM,(void **)&pruRam_1);  // Local Ram  addressed  for PRU1
				      memset(pruRam_1-> valArray , 0 , sizeof(pruRam_1-> valArray));    //  clear RAM addresses
				      prussdrv_exec_program (PRU_1, PROG_NAME_PR1);  // execute PRU
				  	return 0;

				break;
		default:
			break;
	}

     return 1;



	}
