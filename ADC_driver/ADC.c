///////ADC.c file///////
#include"ADC.h"
#include <avr/io.h> 
unsigned int Convert_single(unsigned char ch)
{
	union data data;
	if(ch>7)
	{
		return 0;
	}
	ADMUX|=ch;
	ADCSRA|=(1<<6);   //start conversion
	while( ( ADCSRA&(0x10) )==0 );   //keep looping until conversion completes
	if(precision)
	{
		return ADCH;
	}
    data.data[0]=ADCL;
	data.data[1]=ADCH;
	return data.da;
}

void ADC_enable(void)
{
	ADMUX=( (ADMUX&~(precision_field))|precision );
	ADCSRA=( (ADCSRA&~(prescalar_field))|prescalar );
	ADMUX=( (ADMUX&~(reference_field))|reference );
	ADCSRA|=(1<<7);  //enable ADC module
}