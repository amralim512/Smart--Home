#ifndef FLAME_H_
#define FLAME_H_
#include"std_types.h"
#include"common_macros.h"

#define flame_PORTID PORTD_ID // Define the Port ID for the flame sensor
#define flame_PINID  PIN2_ID // Define the Port ID for the flame sensor

/* Function Declaration of the flame sensor to initiate it */
void flame_init(void);
uint8 flame_getValue(void);


#endif /* FLAME_H_ */
