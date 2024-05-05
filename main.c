// RFID Based Attendance System Using 8051 Microcontroller
//library description
#include<reg51.h>
#include<string.h>
#include<stdio.h>
#include "UART.h"
#include "LCD.h"
#include "Keypad.h"

#define Pass1 "1234"

unsigned char x = 0;
unsigned char Pass2[4]; 
unsigned char index ;

char i;
char rfid[9];


void AUTHORISED_PASS (void);
void UNAUTHORISED_PASS (void);

void main()
{
	
    UART_Init();
    LCD_Init();
	 // KPD_Init();
	
		lcd_clearscreen();			
    LCD_Send_String("---Door Lock---");
    LCD_Send_Command(0xc0);
    LCD_Send_String("Security System"); 
		delay(1000);
	
    while(1)
    {  
    			
			//	Door_Motion(STOP);
        lcd_clearscreen();			
			  LCD_Send_String("open by RFID : 1"); 
   			LCD_Send_Command(0xC0);
			  LCD_Send_String("open by PASS : 2");
	  	  x = keypad();
			
			if (x == '1') 
			{		 
				lcd_clearscreen();			
        LCD_Send_String("---RFID Based---");
        LCD_Send_Command(0xC0);
        LCD_Send_String("Security System"); 
        delay(500);
	
				
        lcd_clearscreen();			
        LCD_Send_String("Scan Your Card:");
        LCD_Send_Command(0xC0);
        
				
				i=0;
        for(i=0;i<8;i++)
        { 
					rfid[i]=Recieve_Data();
				}
        rfid[i]='\0';
			
        lcd_clearscreen();			
			  LCD_Send_String("Rfid No. is:");
        LCD_Send_Command(0xC0);
			
        for(i=0;i<8;i++)
        {
					LCD_Send_Data(rfid[i]);	
				}
        delay(1000);
			
        if(strncmp(rfid,"47C34ED7",8)==0)
        {   
             AUTHORISED_PASS();			
        }
        else 
        {  
            UNAUTHORISED_PASS();
        }	
							
		} 
    else if ( x == '2') 
    {   
			
        lcd_clearscreen();			
        LCD_Send_String("---PASS Based---");
        LCD_Send_Command(0xC0);
        LCD_Send_String("Security System"); 
        delay(500);
			
			
        lcd_clearscreen();			
			  LCD_Send_String("Enter The PASS"); 
			  LCD_Send_Command(0xC0);
			  LCD_Send_String("4 Digit : ");
			
       
			for (index=0; index<4; index++)
			{
				Pass2[index] = keypad();
				LCD_Send_Data(Pass2[index]);
			  delay(100);
			}
			  Pass2[index] ='\0';
			  delay(500);


			
			if(strncmp(Pass2,"1234",4)==0)
        {   
             AUTHORISED_PASS();
        }

        else 
        {  
             UNAUTHORISED_PASS();
        }		
			  
		 } 
    else 
		{
				LCD_Send_Command(1);		
        LCD_Send_String("-Invalid option-");
        LCD_Send_Command(0xc0);
        LCD_Send_String("!!!!!!!!!!!!!!!!"); 
        delay(500);
		} 
		
	}		// end of while 
	
} // end of main 



void AUTHORISED_PASS (void)
{
           LCD_Send_Command(1);
           LCD_Send_String("---AUTHORISED---");
	         LCD_Send_Command(0xC0);
           LCD_Send_String("--Door Unlocked--"); 
					 delay(1000);
}


void UNAUTHORISED_PASS (void)
{

           LCD_Send_String("--UNAUTHORISED--");
					 LCD_Send_Command(0xc0);
           LCD_Send_String("---Door locked---");
	         LCD_Send_Command(1);
           LCD_Send_Command(2);
	      if (x == '1')
				{
           LCD_Send_String("Try Another CARD");
				}
				else if (x =='2')
				{
           LCD_Send_String("Try Another PASS");
				}
					 delay(1000);
}

