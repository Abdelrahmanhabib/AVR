#include"GPIO_functions.h"

////////////////////////////////////////////////////////////////////////

void port_direction(unsigned char base,char state)
{
	if(state==output)
	{
		*((volatile unsigned char *)base)=0xff;
	}
	else
	{
		*((volatile char *)base)=0x00;
	}
}
/////////////////////////////////////////////////////////////////////////////

void pin_direction(unsigned char base,char pin,char state)
{
	if(state==output)
	{
		*((volatile char*)(base))|=(1<<pin);
	}
	else
	{
		*((volatile char*)(base))&=~(1<<pin);
	}
}
/////////////////////////////////////////////////////////////////////
void pin_reset(unsigned char base,char pin)
{
	*((volatile char*)(base+1))&=~(1<<pin);
}
/////////////////////////////////////////////////////////////////////
void pin_set(unsigned char base,char pin)
{
	*((volatile char*)(base+1))|=(1<<pin);
}
//////////////////////////////////////////////////////////
void port_write(unsigned char base,char value)
{
	*((volatile char*)(base+1))=value;
}
/////////////////////////////////////////////////////////////////
char port_read(unsigned char base)
{
	char value;
	value=*((volatile char*)(base-1));
	return value;
}
////////////////////////////////////////////////////////////////
char pin_read(unsigned char base,char pin)
{
	char value=0;
	value=*(( volatile char *)(base-1))&(1<<pin);
	if(value)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
///////////////////////////////////////////////////////////////////////////
void pin_write(unsigned char base,char pin ,char value)
{
	if(value)
	{
		*((volatile char*)(base+1))|=(1<<pin);
	}
	else
	{
		*((volatile char*)(base+1))&=~(1<<pin);
	}
}
