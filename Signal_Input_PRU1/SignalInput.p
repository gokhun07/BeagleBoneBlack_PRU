  // ihsan gökhun önel
 // onel.gokhun@gmail.com
 //  gelen sinyalin yüksek kenar ve low kenarını hesaplayıp RAM de  belirlenen alana yazma yazılır
 
// input  PRRU 0 -> r31.3 (P9_28)  
 

.origin 0                    // start program
.entrypoint MyMain           //  programın başlangıç noktası

#define PRU0_R31_VEC_VALID 32
#define EVENTOUT0 3

#define RAM_LOCAL  0x00000000      // local RAM başlangıc adresi
#define SHRED_MEMO 0x00000008      // Shared Memory de PRU işlemi tekrar yapmak için buraya bakacak

MyMain:
	
	MOV		 R0,  RAM_LOCAL        // R0 =   0x00000000  adersi 
	MOV 	 R2 , SHRED_MEMO       // R1 =   0x00000008  adresi 
 	MOV      R1 , #0x00000000      // Registerlar sıfırlandı
 	MOV      R3 , #0x00000000
 	MOV      R4 , #0x00000000
 	MOV      R5 , #0x00000000
WaitLine:
	QBBC	 WaitSignal, r31.t3        // hattın düşmesini bekle  bit clear 
    QBA      WaitLine    			   // Hat low olmadıysa burda dön		
WaitSignal:
 	MOV      R3 , #0x00000000		 	// R3 sıfırla 
	SBBO     R3 , R2 , 0 , 4  			// tekrar  shared memo alanı 0 lanır
    QBBS     FirstEdge, r31.t3          // hattan sinyal bekle
    QBA      WaitSignal   

FirstEdge:
	ADD		 R1 ,R1 , #1               // R1=R1+1   işlemi sinyal düşene kadar yapılır width hesabı için
	QBBC	 LowEdge, r31.t3           // hattan sinyal bekle
    QBA      FirstEdge    
LowEdge:
    ADD		 R5 ,R5 , #1				// R5=R5+1 hesabı yapılır  low kenar için 
	QBBS	 SecondEdge, r31.t3        // hattan sinyal bekle
    QBA      LowEdge   

SecondEdge:
    SBBO     R1 , R0 , 0 , 4 		// r1 register icerisinde olan degeri (r0 + 0 ) ofset ten baslayarak 4 byte sakla
    SBBO     R5 , R0 , 4 , 4 		// period içerisindeki low kısım     (r0+4) içine kaydet
	MOV      R1 , #0x00000000
    MOV      R5 , #0x00000000
 WaitEvet:   
    LBBO    R3, R2 ,0, 4              // r2 nin gösterdiği adresten başla 4byte r3 içine al                   
  	QBGT    WaitLine	 , R4 , R3    // if R3  > R4 
  	QBA	    WaitEvet                  // sonsuza kadar bu işlem devam edecek

 
