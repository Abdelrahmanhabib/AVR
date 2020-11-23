#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
void T0delay(void);

int main(void)
{
	//event external counter using timer 1 assignment 
	/*DDRB&=~(1<<1);		// make pin 1 of port B input (T1)
	PORTB|=(1<<1);		// enable pull up resistor of pin 1 of port B 
	TCCR1B|=(6<<0);		// external event counter, normal mode timer 1
	DDRC=0xff;			// make port C output to display the content of TCNT1L
	DDRD=0xff;			// make port D output to display the content of TCNT1H
	DDRA=0xff;*/
	
	////////////////////////////////////////////////////////////////////////////
	//generating 50 HZ 0.45 duty cycle
	DDRD|=(1<<5);
	ICR1=20000;
	OCR1A=15000;
	TCCR1A=0x82;
	TCCR1B=0x19;
	////////////////////////////////////////////////////////////////////////////////
	//continuously glowing led
	/*DDRB|=(1<<3);
	TCCR0=0x69;	
	OCR0=255;
	unsigned char n=0;*/
	/////////////////////////////////////////////////////////////////////////////
	//generating square waves using normal and ctc modes
	/*DDRB|=(1<<3);
	TCCR0=0x31;
	OCR0=128;*/
			
	while(1)
	{
		/*PORTA=0x00;
		T0delay();
		PORTA=0xff;
		T0delay();
		PORTC=TCNT1L;
		PORTD=TCNT1H;*/
		////////////////////////////////////////////////////
		//continuously glowing
		
		/*if (n==0)
		{
			OCR0--;
			_delay_ms(50);
			if(OCR0==0)
				n=1;
		}
		else
		{
			OCR0++;
			_delay_ms(50);
			if(OCR0==0)
				n=0;
		}*/
		//////////////////////////////////////////////////////
		
	}
}

void T0delay()
{
	TCNT0 =0;
	OCR0=100;
	TCCR0 = 0x09;			
	while((TIFR&(1<<1))==0);  
	TCCR0 = 0;
	TIFR |= (1<<1);				
}