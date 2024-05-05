#include <reg51.h>
#define display_port P2   //Data pins connected to port 2 on microcontroller

sbit rs =P3^2;
sbit rw =P3^3;
sbit e = P3^4; 


void delay(unsigned int time);  // Function for creating delay in milliseconds.
void LCD_Send_Command(unsigned char command);  //Function to send command instruction to LCD
void LCD_Send_Data(unsigned char disp_data);  //Function to send display data to LCD
void LCD_Init(void);    //Function to prepare the LCD  and get it ready
void LCD_Send_String(char *str);
void lcd_clearscreen(void);






