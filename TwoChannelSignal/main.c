  /*


28/08/2016

ihsan Gökhun Önel

onel.gokhun@gmail.com


P9_28 den aldığı sinyalleri genişlik periyod  ve frekans olarak
ekranda gösteren fonksiyon.

Sistemin çalışabilir olması için PR0 aktif edilip doğru overlay üzerinden
p31.3  input olarak ayarlanmış olmak zorundadır.


Not : Değişkenlerin isimlerini ve Fonksiyonların ismi inglizce oldu   alışkanlık
      gereken büütün satırlarda yorum atmaya özen gösterdim


burada PRU ve merkez CPU nun haberleşmesi Shared memeory tekniğine dayanmaktadır.
PRU ait olan local Ram adresine Merkez çekirdek olan ARM cortex erişebilmektedir
bu sayede bu adresi sürekli gidip okuyarak PRU tarafından güncellendiğinde  değerin geldiği anlaşılır.


*/

#include "defines.h"


extern uint8_t GetSignal(PRU_TYPE pru);

int main(void)
  {
	pthread_t pru0 ;
	void * res;
	unsigned int bytes_available;

    // Run  program as root !!
  if(getuid()!=0){
       printf(" You  must run the program as  root \n");
       exit(EXIT_FAILURE);
    }

  if(InitPru(PRU_0) != 0)
  	  {
	  	  printf("Failed to initialize PRU0 \n ");
	  	  exit(EXIT_FAILURE);
	  }

  if(InitPru(PRU_1) != 0)
    	  {
  	  	  printf("Failed to initialize PRU1\n ");
  	  	  exit(EXIT_FAILURE);
  	  }



  while(1)
			{



        flag.Pru0Ready =0;
        flag.Pru1Ready =0;


        	if(   pthread_create(&pru0,NULL,GetSignal,PRU_0)!=0)
				{
					printf("PRU0 GetSignal Thread creation \n");
					exit(EXIT_FAILURE);
				}


        	if(pthread_join(pru0,&res) != 0 )
        				{
        					printf("PRU0 GetSignal Thread creation \n");
        					exit(EXIT_FAILURE);
        				}


        	if( pthread_create(&pru0,NULL,GetSignal,PRU_1)!=0)
				{
					printf("PRU	 GetSignal Thread creation \n");
					exit(EXIT_FAILURE);
				}

          	if(pthread_join(pru0,&res) != 0 )
                				{
                					printf("PRU1 GetSignal Thread creation \n");
                					exit(EXIT_FAILURE);
                				}

            while( !flag.Pru0Ready && !flag.Pru1Ready  ); // Wait until PRUs ready
            sleep(1);

			}

  //    prussdrv_pru_disable(PRU_NUM);  // never come here
  //   prussdrv_exit ();


     return EXIT_SUCCESS;
  }


