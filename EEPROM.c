

#include <avr/io.h>

void eeprom_write(unsigned char data,unsigned int address);
unsigned char eeprom_read(unsigned int address);

int main(void)
{
	DDRA=0xff;
	//eeprom_write(0x44,10);
	PORTA=eeprom_read(10);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

void eeprom_write(unsigned char data,unsigned int address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<1));
	
	/* Set up address and data registers */
	EEAR = address;
	EEDR = data;
	
	/* Write logical one to EEMWE to enable writing by setting EEWE bit */
	EECR |= (1<<2);
	
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<1);
}

unsigned char eeprom_read(unsigned int address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<1));
	
	/* Set up address register */
	EEAR = address;
	
	/* Start eeprom read by writing EERE */
	EECR |= (1<<0);
	
	/* Return data from data register */
	return EEDR;
}