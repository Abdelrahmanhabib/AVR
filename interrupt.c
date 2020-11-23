#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB&=~(1<<2);
	PORTB|=(1<<2);
	DDRD&=~(1<<2);
	PORTD|=(1<<2);
	DDRD&=~(1<<3);
	PORTD|=(1<<3);
	DDRA|=(7<<0);
	
	////////////////////////////////////////////////////////////////////////
	//generating square waves using interrupt T0 and T1
	TCCR0|=(1<<3);		//CTC mode
	OCR0=124;			//match every 125 clock cycle
	TCCR0|=(1<<1);      //prescaler = 8
	TCCR1B|=(1<<3);		//CTC mode of timer1
	TCCR1B|=(1<<0);		//no prescaler
	OCR1A=99;			//compare match every 100 clock cycle
	TIMSK|=(1<<1);		//enable interrupt of Timer0 compare match
	//TIMSK|=(1<<4);      //enable interrupt of compare match channel A
	DDRB|=(1<<1);		//pin 1 of port B output to generate through it square wave using timer 0(2K)
	DDRB|=(1<<7);		//pin 7 of port B output to generate through it square wave using timer 1(5K)
	
	////////////////////////////////////////////////////////////////////////////////////////////
	//external interrupt
	GICR|=(1<<5);		//enable external interrupt 2
	GICR|=(1<<6);		//enable external interrupt 0
	GICR|=(1<<7);		//enable external interrupt 1
	//MCUCR|=(3<<0);		//rising edge interrupt INT 0
	MCUCR|=(3<<2);		//rising edge interrupt INT 1
	MCUSR|=(1<<6);		//rising edge interrupt INT 2
	sei();
    while(1)
    {
		 //using polling
         /*
		 if((PINB & (1<<2))==0 )
		 {
			 PORTA^=(1<<2);
			 while((PINB & (1<<2))==0);
		 }
			
		
		if((PIND & (1<<2))==0 )
		{
			PORTA^=(1<<0);
			while((PIND & (1<<2))==0);
		}
		
		
		if((PIND & (1<<3))==0 )
		{
			PORTA^=(1<<1);
			while((PIND & (1<<3))==0);
		}
		*/
		
		 PORTA|=(1<<2);
		
		
		
    }
}

ISR(TIMER0_COMP_vect)
{
	PORTB^=(1<<1);
}

ISR(TIMER1_COMPA_vect)
{
	PORTB^=(1<<7);
}

ISR(INT0_vect)
{
	//sei();
	int i;
	for(i=0;i<10;i++)
	{
		PORTA|=(1<<2);
		_delay_ms(250);
		PORTA&=~(1<<2);
		_delay_ms(250);
	}
	//PORTA^=(1<<2);
	
}
	

ISR(INT1_vect)
{
	PORTA^=(1<<0);
}

ISR(INT2_vect)
{
	PORTA^=(1<<1);
}