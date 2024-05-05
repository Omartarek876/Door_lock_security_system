
//library description
#include<reg51.h>
#include "UART.h"

char ch=0;

void UART_Init(void)
{
 TMOD=0xA0; // to enable OR gate and use timer mode 2 which use in serial mode 1 
 SCON=0x50; // to use serial mode 1 
 TH1=0xfd;  // to use baud rate 9600
 TR1=1; // to enable timer 1 to count
	
}
char Recieve_Data(void)
{
  while(!RI); // polling until receive the data 
    ch=SBUF;  // set the recieved data in the var ch  
    RI=0;
    return ch; // return the data 
}
