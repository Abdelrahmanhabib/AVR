
#ifndef USART_H_
#define USART_H_
/////////////////////////////////////////////////////////////////
#define F_CPU 1000000		    //clock frequency 
#define RXC   7		            //USART receive complete ->this flag is set when there are new data in the receive buffer that are not read
#define TXC   6		            //USART transmit complete ->this flag is set when the entire frame in the transmit shift register has been transmitted and there are no new data in the transmit buffer
#define UDRE  5		            //USART data register empty ->this flag is set when the transmit data buffer is empty and ready to receive new data
#define RXCIE 7		            // receive complete interrupt enable
#define TXCIE 6		            //transmit complete interrupt enable
#define UDRIE 5		            //USART data register empty interrupt enable
#define RXEN  4		            //receive enable
#define TXEN  3		            //transmit enable
#define URSEL 7		            //register select -> one for writing in the UCSRC
#define UMSEL 6		            //USART mode select -> zero for asynchronous operation
#define UPM1  5		            //parity mode 0
#define UPM0  4		            //parity mode 1
#define USBS  3		            //stop bit -> zero for one stop bit, otherwise two stop bits

////////////////////////////////////////////////////////////////////////////////////////////////////
//Baud rate configuration :1200 , 2400 , 4800 , 9600 , 19200 , 38400 bps
#define Baud_rate 4800   //configure here
//////////////////////////////////////////////////////////////////////////////////////////////////
//character size configuration : five_bits , six_bits , seven_bits , eight_bits
#define caracter_size   eight_bits //configure here
#define five_bits  (0<<1)
#define six_bits   (1<<1)
#define seven_bits (2<<1)
#define eight_bits (3<<1)
#define size_field (0x06)
////////////////////////////////////////////////////////////////////////////////////////////////
//parity configuration : NO_PARITY , ODD_PARITY , EVEN_PARITY
#define parity NO_PARITY
#define NO_PARITY     (0<<4)
#define ODD_PARITY    (2<<4)
#define EVEN_PARITY   (3<<4)
#define parity_field  (0x30)
/////////////////////////////////////////////////////////////////////////////////////////////// 
//stop bits configuration : one_bit , two_bits
#define stop_bits one_bit
#define one_bit     (0<<3)
#define two_bits    (1<<3)
#define stop_field  (0x08) 
/////////////////////////////////////////////////////////////////////////////////////////////

unsigned char UART_data_available(void);
void UART_Baud_rate(unsigned int Baud);
void UART_TX_enable(void);
void UART_RX_enable(void);
void UART_init(void);
void UART_transmit(unsigned char data);
unsigned char UART_receive(void);

#endif
