#include"temperature.h"
#include"ADC.h"


/* Function Will help to determine the values of the Temperature sensor
 * so that we can convert the Analog value to digital one to be able to interface
 * with with the micro-controller
 * Rule driven from calculation and data sheet of the sensor
 */
uint8 temp_getTemperature(void)
{
	// variables that will help us to do the calculations on the rule
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(temp_channelID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*temp_maxTemperature*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*temp_maxVoltValue));

	return temp_value;
}
