#include "USART.h"
#include <avr/io.h>
extern unsigned char fl;
extern unsigned char mailbox;
// there is a problem in the baud rate calculation because the results are not int values in some cases 
void UART_Baud_rate(unsigned int Baud)
{
	UBRRL=(F_CPU/( (long)16*Baud ))-1;
}

unsigned char UART_data_available(void)
{
	return fl;
	//return (UCSRA & (1<<7) );    //polling methode
}
void UART_TX_enable(void)
{
	UCSRB|=(1<<3);
}
void UART_RX_enable(void)
{
	UCSRB|=(1<<4);
}
void UART_init(void)
{
	UCSRC|=(1<<7);
	UCSRC=( (UCSRC&~(size_field))|(caracter_size) );
	UCSRC=( (UCSRC&~(parity_field))|parity );
	UCSRC=( (UCSRC&~(stop_field))|stop_bits );
	UBRRL=(F_CPU/( (long)16*Baud_rate ))-1;                                                                              
}

///////////////////////////////////////////////////////////////
void UART_transmit(unsigned char data)
{
	while( ( UCSRA & (1<<5) )==0 );                                  //polling data register empty flag in(UCSRA) before writing to UDR register
	UDR=data;                                                      //writing to data register to be transmitted
}
///////////////////////////////////////////////////////////////
unsigned char UART_receive(void)
{
	//while(  (UCSRA & (1<<7) )==0 );                                  //polling UART receive flag in(UCSRA) before reading the data register
	//return UDR;						
	fl=0;
	return mailbox;
}