#ifndef LDR_H_
#define LDR_H_
#include"std_types.h"
#define LDR_PORTID PORTA_ID // define LDR port ID
#define LDR_PinID PIN0_ID  // define LDR pin ID

#define LDR_channelID 0  // define the ADC channel of the LDR sensor
#define LDR_maxVoltValue 2.56 // Max volt value of the LDR
#define LDR_maxLightIntensity 100  //Max LDR value can measure

// Function Declaration of getting the value from ADC channel of the LDR
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
