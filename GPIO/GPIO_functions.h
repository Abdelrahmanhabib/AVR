#ifndef GPIO_functions_H_
#define GPIO_functions_H_
#include "constants.h"
void port_direction(unsigned char base,char state);
void pin_direction(unsigned char base,char pin,char state);
void pin_reset(unsigned char base,char pin);
void pin_set(unsigned char base,char pin);
void port_write(unsigned char base,char value);
char port_read(unsigned char base);
char pin_read(unsigned char base,char pin);
void pin_write(unsigned char base,char pin ,char value);
#endif // GPIO_functions_H_
