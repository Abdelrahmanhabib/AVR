#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_driver/lcd.h"

#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2
#define LCD_PRT PORTA
#define LCD_DDR DDRA
#define LCD_CPRT PORTB
#define LCD_CDDR DDRB

void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCD_gotoxy(unsigned char x,unsigned char y);
void LCD_print(char * str);

int main(void)
{
	LCD_init();
	LCD_cmd(0x40);      //first address to store register one of customised character
	LCD_data(0x00);
	LCD_data(0x00);
	LCD_data(0x0A);
	LCD_data(0x1F);
	LCD_data(0x1F);
	LCD_data(0x0E);
	LCD_data(0x04);
	LCD_data(0x00);
	
	LCD_cmd(0x48);      //2nd address to store register one of customised character
	LCD_data(0x1F);
	LCD_data(0x1F);
	LCD_data(0x0A);
	LCD_data(0x1F);
	LCD_data(0x1F);
	LCD_data(0x0E);
	LCD_data(0x04);
	LCD_data(0x00);
	
	LCD_cmd(0x50);      //3rd address to store register one of customised character
	LCD_data(0x1F);
	LCD_data(0x1F);
	LCD_data(0x0A);
	LCD_data(0x1F);
	LCD_data(0x1F);
	LCD_data(0x0E);
	LCD_data(0x04);
	LCD_data(0x00);
	
	LCD_cmd(0x58);      //4th address to store register one of customised character
	LCD_data(0x00);
	LCD_data(0x00);
	LCD_data(0x0A);
	LCD_data(0x1F);
	LCD_data(0x1F);
	LCD_data(0x0E);
	LCD_data(0x04);
	LCD_data(0x00);
	
	LCD_cmd(0x80);
	LCD_data(0x00);
	LCD_data(0x01);
	LCD_print("zamalek");
	LCD_data(0x02);
	LCD_data(0x03);
	
	while(1)
	{
		
	}
	
}

void LCD_cmd(unsigned char cmd)
{
	LCD_PRT = cmd & (0xF0);					//write the high nibble to D4 to D7
	LCD_CPRT &=~(1<<LCD_RS);				//RS = 0 for command
	LCD_CPRT &=~(1<<LCD_RW);				//RW = 0 for write
	LCD_CPRT |=(1<<LCD_EN);					//high to low pulse
	_delay_us(1);
	LCD_CPRT &=~(1<<LCD_EN);
	_delay_us(100);
	
	LCD_PRT = cmd<<4;						//shift to write the low nibble
	LCD_CPRT |=(1<<LCD_EN);	                //high to low pulse
	_delay_us(1);
	LCD_CPRT &=~(1<<LCD_EN);
	_delay_us(100);
}

void LCD_data(unsigned char data)
{
	LCD_PRT = data & (0xF0);				//write the high nibble to D4 to D7
	LCD_CPRT |=(1<<LCD_RS);	                //RS = 1 for data
	LCD_CPRT &=~(1<<LCD_RW);			    //RW = 0 for write
	LCD_CPRT |=(1<<LCD_EN);					//high to low pulse
	_delay_us(1);
	LCD_CPRT &=~(1<<LCD_EN);
	
	LCD_PRT = (data<<4);					//shift to write the low nibble
	LCD_CPRT |=(1<<LCD_EN);				    //high to low pulse
	_delay_us(1);
	LCD_CPRT &=~(1<<LCD_EN);
	_delay_us(100);
}

void LCD_init(void)
{
	LCD_DDR|=0xff;				//LCD Data PORT
	LCD_CDDR|=0xff;				//LCD control PORT 		
	LCD_cmd(0x33);				//4 bit mode
	LCD_cmd(0x32);				//4 bit mode
	LCD_cmd(0x28);				//2 lines 5*7 matrix D4 to D7
	LCD_cmd(0x0F);				//display on cursor on
	LCD_cmd(0x01);				//clear LCD
	_delay_us(2000);			//wait 2ms after executing 0x01 and 0x02 modes
	
}

void LCD_gotoxy(unsigned char x,unsigned char y)
{
	unsigned char firstadd[]={0x80,0xc0,0x94,0xD4};
	LCD_cmd(firstadd[x-1] + y-1);
	_delay_us(100);
}

void LCD_print(char* str)
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		LCD_data(str[i]);
		i++;
	}
}

