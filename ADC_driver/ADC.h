///////ADC.h file////////
/////functions declaration
unsigned int Convert_single(unsigned char ch);
void ADC_enable(void);
union data{
	unsigned char data[2];
	unsigned int da;
};

//prescalar configuration : pre_2, pre_4, pre_8, pre_16, pre_32, pre_64, pre_128
#define prescalar pre_128  //configure here
#define pre_2   1
#define pre_4   2
#define pre_8   3
#define pre_16  4
#define pre_32  5
#define pre_64  6
#define pre_128 7
#define prescalar_field 0x03

//precision configuration : bit_8, bit_10
#define precision bit_8   //configure here
#define bit_8  (1<<5)
#define bit_10 (0<<5)
#define precision_field  0x20

//reference configuration : internal_REFV ,AVCC, external_AREF
#define reference AVCC    //configure here
#define external_AREF (0<<6)
#define AVCC (1<<6)
#define internal_REF  (3<<6)
#define reference_field 0xc0
  
