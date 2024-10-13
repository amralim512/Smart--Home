#ifndef ADC_H_
#define ADC_H_
#include"std_types.h"

#define ADC_MAXIMUM_VALUE    1023  // Max Value of the ADC can read from the channel
#define ADC_REF_VOLT_VALUE   2.56 // Max volt value can the ADC have which is the reference voltage


void ADC_Init(void);
uint16 ADC_readChannel(uint8 chNum);




#endif /* ADC_H_ */
