
#include <avr/io.h>

int main(void)
{
	//generating signal with frequency of 978 and duty cycle 20 or 85%
	TCCR1B|=(2<<0);			//prescaler = 8
	TCCR1A|=(2<<0);			//mode 2 of timer1
	TCCR1A|=(2<<6);			//non inverted mode of channel A
	TCCR1A|=(3<<4);			//inverted mode of channel B
	OCR1B=256;			    //50% duty cycle of channel B
	DDRA&=~(1<<0);			//pin 0 of port A input
	PORTA|=(1<<0);			//enable pull up resistor of pin 0 port A
	DDRD|=(1<<5);			//pin 5 of port D output (OC1A)
	DDRD|=(1<<4);			//pin 4 of port D output (OC1B)
	
	//generating square wave with frequency of 100 HZ using timer2
	TCCR2|=(6<<0);			//prescaler = 256
	TCCR2|=(1<<4);			//toggle output compare mode
	TCCR2|=(1<<3);			//CTC mode
	DDRD|=(1<<7);			//pin 7 of port D output (OC2)
	OCR2=155;				//correspond to 100 HZ at 8M
	
	//toggle led after 4 external clocks using timer0
	DDRB&=~(1<<0);		//
	PORTB|=(1<<0);
	DDRB|=(1<<3);		//pin 3 of port B output (OC0)
	OCR0=3;
	TCNT0=0;				
	TCCR0|=(6<<0);		//external clock
	TCCR0|=(1<<3);		//CTC mode
	TCCR0|=(1<<4);		//toggle OC0 on match
	
	//generating square wave using CTC mode
	/*TCCR0|=(5<<0);			//prescaler = 1024
	TCCR0|=(1<<4);			//toggle output compare mode
	TCCR0|=(1<<3);			//CTC mode
	DDRB|=(1<<3);			//pin 3 of port B output (OC0)
	OCR0=77;				//correspond to 50 HZ at 8M*/
	
    while(1)
    {
		
        if( PINA & (1<<0) )
			OCR1A=435;		//duty cycle = 85%
	
		else
			OCR1A=102;		//duty cycle = 20% 
			
    }
	
}