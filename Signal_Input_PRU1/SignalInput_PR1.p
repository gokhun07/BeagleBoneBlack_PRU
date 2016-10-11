   // ihsan gökhun önel
 // onel.gokhun@gmail.com
 //  signal calculated  as low and high edge  and saved dedicated RAM area
 // input  PRU1 -> r31.0 (P8_45)  
 

.origin 0                    // start program
.entrypoint MyMain           

#define PRU0_R31_VEC_VALID 32
#define EVENTOUT0 3

#define RAM_LOCAL  0x00000000      // local RAM Begining adress
#define SHRED_MEMO 0x00000008      // Shared Memory for PRU and Master Cortex a8

MyMain:
	
	MOV	 R0,  RAM_LOCAL        // R0  = Ram  Local Adress  
	MOV 	 R2 , SHRED_MEMO       // R1 =   0x00000008  adresi 
 	MOV      R1 , #0x00000000      // Clear registers 
 	MOV      R3 , #0x00000000
 	MOV      R4 , #0x00000000
 	MOV      R5 , #0x00000000
WaitLine:
 	QBBC	 WaitSignal, r31.t0        //  wait line to low  
        QBA      WaitLine    			   // wait untill line low 		
WaitSignal:
 	MOV      R3 , #0x00000000		 	// R3 clear  
	SBBO     R3 , R2 , 0 , 4  			// Shared Memo address clear 
        QBBS     FirstEdge, r31.t0          // wait signa from line 
        QBA      WaitSignal   

FirstEdge:
	ADD      R1 ,R1 , #1            // R1=R1+1   calculation untill line low for Width 
	QBBC	 LowEdge, r31.t0        // wait signal from line 
        QBA      FirstEdge    
LowEdge:
       ADD	 R5 ,R5 , #1		   // R5=R5+1 calculation  for low edge  
       QBBS	 SecondEdge, r31.t0        // wait signal from line 
       QBA       LowEdge   

SecondEdge:
       SBBO     R1 , R0 , 0 , 4 		//Value in R1 register saved ind adress of (R0 + 0 )  as 4 byte 
       SBBO     R5 , R0 , 4 , 4 		// low part (r0 + 4 ) saved 
       MOV      R1 , #0x00000000
       MOV      R5 , #0x00000000
 WaitEvet:   
       LBBO    R3, R2 ,0, 4                                 
       QBGT    WaitLine	 , R4 , R3         // if R3  > R4 
       QBA     WaitEvet                  // infinite loop 

 
