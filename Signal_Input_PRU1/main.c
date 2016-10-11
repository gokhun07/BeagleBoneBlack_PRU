/*


28/08/2016   

ihsan Gökhun Önel

onel.gokhun@gmail.com
 

Input channel is P8_45. Signal measuring this channel calculated as period and freq.

first it must be enabled  PRU1 and than p31.0 pin activated in overlay.After that overlay must be 
added to device tree
 
 
PRU and Main CPU communicate  eachother with  shared memory .
ARM cortex can reach ram area whose belongs to PRU.This area can
be used as shared memory.If any update made by PRU , main cortex can realize it
 by pooling this area.


 


*/

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdint.h>
  #include <prussdrv.h>
  #include <pruss_intc_mapping.h>

  #define PRU_NUM 1
  #define PROG_NAME "SignalInput.bin"   // binary file name from asm
  #define TRUE    1
   
  unsigned int ComputeMicroSecond(unsigned int sec)  ;  
  


  typedef struct 
  {
   unsigned   int  duty;
   unsigned   int  lowCycle;
   unsigned   int  width;
   unsigned   int  period;
   float freq;
     
  }Measurament;  // ölçüm değerleri

  Measurament  measure;

typedef struct {

    uint32_t  valArray[3];

  }LocalPruRam;   // PRU local ram initialized here 

  LocalPruRam *pruRam;

int main(void)
  {
         
         tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;



 
     if(getuid()!=0){
        printf(" Programi root yetkisi ile calistirmalisiniz \n");
        exit(EXIT_FAILURE);
     }


 

       prussdrv_init (); 
   
       prussdrv_open (PRU_EVTOUT_0);   
       prussdrv_pruintc_init(&pruss_intc_initdata);
       
       prussdrv_map_prumem(PRUSS0_PRU1_DATARAM,(void **)&pruRam); // Local Ram 
      
       memset(pruRam-> valArray , 0 , sizeof(pruRam-> valArray));    //  Clear Ram 
     
       prussdrv_exec_program (PRU_NUM, PROG_NAME);  // PRU start 
		
 
 

    while(TRUE)
    {
  


      while(pruRam-> valArray[1]==0);   
      
 
      
         measure.width =  ComputeMicroSecond(pruRam-> valArray[0]) +  1 ;  
         measure.lowCycle = ComputeMicroSecond(pruRam-> valArray[1])    ;
         measure.period  =  measure.width + measure.lowCycle ; 
         measure.freq   = (float)(  1.0  /  (measure.period )) *1000 ; 
         measure.duty   =  ((100 *  measure.width) / (measure.period ));
        
         printf(" Period  =   %d us   |   Width  = %d us   |   Frekans  =  %f kHz    | Duty : %d % \n", measure.period ,  measure.width   ,
                                                                                                       measure.freq , measure.duty);
       
         sleep(1);  
        
        pruRam-> valArray[0] = 0 ;  
        pruRam-> valArray[1] = 0 ;  
        pruRam-> valArray[2] = 0xFFFFFFFF ;         
}
    
     prussdrv_pru_disable(PRU_NUM);  // Never come here
     prussdrv_exit ();


     return EXIT_SUCCESS;
  }

unsigned int ComputeMicroSecond(unsigned int sec)  
   { 

      unsigned int res;
      res = ( (sec * 15 )/1000 );
        
           return  res ;
      

  }
