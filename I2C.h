#define read 1
#define write 0
#define F_CPU 1000000
#define F_I2C 50000

#ifndef I2C_H_
#define I2C_H_

void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2c_address(unsigned char address,char state );
void I2c_write(unsigned char data );
unsigned char I2C_read(void);
///////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C_init(void)
{
	*((volatile char *)0x21)=0x00;
	*((volatile char*)0x20)=(F_CPU/(2*F_I2C))-8;
	*((volatile char*)0x56)=0x04;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C_start(void)
{
	*((volatile char*)0x56)|=(1<<7)|(1<<5);
	while( ( (*((volatile char*)0x56))&(1<<7) )==0 );
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C_stop(void)
{
	*((volatile char*)0x56)|=(1<<7)|(1<<4);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void I2c_address(unsigned char address,char state )
{
	if(state==write)
	{
		*((volatile char*)0x23)=(address<<1);
		*((volatile char*)0x56)|=(1<<7);
		while(((*((volatile char*)0x56))&(1<<7))==0);
	}
	else
	{
		*((volatile char*)0x23)=((address<<1)|(0x01));
		*((volatile char*)0x56)|=(1<<7);
		while(((*((volatile char*)0x56))&(1<<7))==0);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void I2c_write(unsigned char data )
{
	*((volatile char*)0x23)=data;
	*((volatile char*)0x56)|=(1<<7);
	while(((*((volatile char*)0x56))&(1<<7))==0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned char I2C_read(void)
{
	*((volatile char*)0x56)|=(1<<7)|(1<<6);
	while(((*((volatile char*)0x56))&(1<<7))==0);
	return *((volatile char*)0x23);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

