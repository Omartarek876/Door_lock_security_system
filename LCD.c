#include "lcd.h"

void LCD_Send_Command(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    delay(1);
    e=0;
}
 void LCD_Init()    //Function to prepare the LCD  and get it ready

{
    LCD_Send_Command(0x38);  // for using 2 lines and 5X7 matrix of LCD
    delay(10);
    LCD_Send_Command(0x0F);  // turn display ON, cursor blinking
    delay(10);
    LCD_Send_Command(0x01);  //clear screen
    delay(10);
    LCD_Send_Command(0x81);  // bring cursor to position 1 of line 1
    delay(10);

}

void LCD_Send_Data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    delay(1);
    e=0;
}

void lcd_clearscreen(void) {
    LCD_Send_Command(0x01); // Clear display
    delay(1);
}

void LCD_Send_String(char *str) {
    while (*str != '\0') {
        LCD_Send_Data(*str++);
    }
}
void delay(unsigned int time)
{
	int i,j;
	for(i=0;i< time;i++)
	{
		for(j=0;j<500;j++);
	}
}


