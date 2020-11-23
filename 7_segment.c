// 7_segment display
// by pressing a bush button , increment the number displayed on two 7_segment displays between 0 to 99

#include <avr/io.h>
int main()
{
	//LUT for 7_segment for mapping between the decimal numbers and the required commands to the 7_segments LEDs
	// PORTx = 0bgfedcba  // pin 0 is connected to led A,pin 1 is connected to led b, and so on
	unsigned char LUT[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};      //common cathode
	unsigned char LUT2[]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000}; 	//common anode
	
	DDRA&=!(1<<0);       //make pin 0 port A input to be attached to the pushbutton
	PORTA|=(1<<0);       // setting the first two bits of port A to activate the pull up resistor of pin 0 
	DDRC=0xff;           // make port C output to be connected to the 7_segment display of units
	DDRD=0xff;           //make port D output to be connected to the 7_segment display of tens
	unsigned char num=0; // the variable to displayed number
	PORTD=LUT2[0];	     
	PORTC=LUT2[0];
	while(1)
	{
		while( ( PINA & (0x01) ) ==1 );
		num=(num+1)%100;
		PORTD=LUT2[num/10];
		PORTC=LUT2[num%10];
		while( ( PINA & (0x01) ) ==0 );
		PORTA&=~(1<<1);
	}

}