
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include"I2C.h"

int main(void)
{
	char i=0;
	DDRA=0xff;
	I2C_init();
	I2C_start();
	I2c_address(0x60,write);
	I2c_write(0xC0);
	_delay_ms(1000);
	//I2C_stop();
	while(i<32)
    {
		//avr 2 avr
		//I2C_start();
		I2c_write(i);
        i++;
		_delay_ms(1000);
    }
	I2C_stop();
}



