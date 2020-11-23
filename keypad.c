#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SC_OUT   PORTC
#define INPUT   (PINC>>4)
unsigned char get_number(void);
void wait(void);

int main(void)
{
	unsigned char ch;
	DDRC|=(0x0f);			// make the first four bits output to output scanning signal
	DDRC&=~(1<<4);			// input signal number 1			
	DDRC&=~(1<<5);		    // input signal number 2
	DDRC&=~(1<<6);			// input signal number 3
	DDRA=0xff;				// output number on port A
	while(1)
	{
		ch=get_number();
		if(ch==10)
		{
			PORTA=0xff;
			_delay_ms(500);
			PORTA=0x00;
			_delay_ms(500);
			
			PORTA=0xff;
			_delay_ms(500);
			PORTA=0x00;
			_delay_ms(500);
			
			ch=0;
		}
		PORTA=ch;
	}
}

unsigned char get_number(void)
{
	unsigned char i;
	while(1)
	{
		for (i=1;i<=8;i=i<<1)
		{
			SC_OUT=i;
			_delay_ms(10);
			if(i==1)
			{
				if(INPUT==1){
					return 3;
				}
				else if(INPUT==2){
					return 2;
				}
				else if(INPUT==4){
					return 1;
				}
			}
			else if(i==2)
			{
				if(INPUT==1){
					return 6;
				}
				else if(INPUT==2){
					return 5;
				}
				else if(INPUT==4){
					return 4;
				}
			}
			else if(i==4)
			{
				if(INPUT==1){
					return 9;
				}
				else if(INPUT==2){
					return 8;
				}
				else if(INPUT==4){
					return 7;
				}
			}
			else if(i==8)
			{
				if(INPUT==1){
					return 255;
				}
				else if(INPUT==2){
					return 0;
				}
				else if(INPUT==4){
					return 10;
				}
			}
		}
	}
}

void wait(void)
{
	while(INPUT>0);
}