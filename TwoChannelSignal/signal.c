/*
 * signal.c
 *
 *  Created on: Sep 2, 2016
 *      Author: ihsangokhun
 */
#include "defines.h"

  unsigned int ComputeMicroSecond(unsigned int sec );



uint8_t GetSignal(PRU_TYPE pru)
{
	 Measurament  measure,measure_1;


 switch (pru) {
	case PRU_0:

		     measure.width    =  ComputeMicroSecond(pruRam_0-> valArray[0]) +  1 ;
			 measure.lowCycle =  ComputeMicroSecond(pruRam_0-> valArray[1])    ;
			 measure.period   =  measure.width + measure.lowCycle ;
			 measure.freq     =  (float)(  1.0  /  (measure.period )) *1000 ;
			 measure.duty     =  ((100 *  measure.width) / (measure.period ));
			 printf("\n\n------------------------------ Channel - 1 ----------------------------------------- \n\n");
			 printf(" Period  =   %d us   |   Width  = %d us   |   Frekans  =  %f kHz    | Duty : %d % \n", measure.period ,
							 measure.width   ,measure.freq,measure.duty);
			  usleep(500000);

			 pruRam_0-> valArray[0] = 0 ;
			 pruRam_0-> valArray[1] = 0 ;
			 pruRam_0-> valArray[2] = 0xFFFFFFFF ;

			 while(pruRam_0-> valArray[1] == 0)
			 {
			 	 flag.Pru0Ready=1;

			 }
			break;

		case PRU_1:

			measure_1.width     =  ComputeMicroSecond(pruRam_1-> valArray[0]) +  1 ;
			measure_1.lowCycle  =  ComputeMicroSecond(pruRam_1-> valArray[1])    ;
			measure_1.period    =  measure_1.width + measure_1.lowCycle ;
			measure_1.freq      =  (float)(  1.0  /  (measure_1.period )) *1000 ;
			measure_1.duty      =  ((100 *  measure_1.width) / (measure_1.period ));
			 printf("\n\n------------------------------ Channel - 2 ----------------------------------------- \n\n");

			 printf(" Period  =   %d us   |   Width  = %d us   |   Frekans  =  %f kHz    | Duty : %d % \n", measure_1.period ,
						 measure_1.width   ,measure_1.freq,measure_1.duty);

				usleep(500000);

				 pruRam_1-> valArray[0] = 0 ;
				 pruRam_1-> valArray[1] = 0 ;
				 pruRam_1-> valArray[2] = 0xFFFFFFFF ;

				 while(pruRam_1-> valArray[1]==0);
							 	 flag.Pru1Ready=1;
			break;

	default:
		break;
}



return 0;

}
unsigned int ComputeMicroSecond(unsigned int sec)
   {

      unsigned int res;
      res = ( (sec * 15 )/1000 );

           return  res ;


  }
