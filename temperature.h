
#include"std_types.h"
#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#define temp_channelID         1 // define of the ADC channel used for the Temperature sensor
#define temp_maxVoltValue     1.5 // Max voltage value can the sensor take
#define temp_maxTemperature    150 // Max Temperature can the sensor give out

uint8 temp_getTemperature(void);



#endif /* TEMPERATURE_H_ */
