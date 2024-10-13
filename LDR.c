#include"LDR.h"
#include "ADC.h"



/*Function over here will help us to get the value
 * from the LDR Sensor to measure it and based on the datasheet
 * the same rule will measure the value of the sensor and return the light
 * intensity
 * */
uint16 LDR_getLightIntensity(void)
{
	// variables to help us make the calculations
    float voltage = 0;
    float light_intensity = 0;
    uint16 adc_value = 0;

    adc_value = ADC_readChannel(LDR_channelID); // read the channel value of the LDR sensor
    // Convert ADC value to voltage
    voltage = (adc_value * LDR_maxVoltValue) / ADC_MAXIMUM_VALUE;
    // Convert voltage to light intensity
    light_intensity = ((voltage / LDR_maxVoltValue)) * LDR_maxLightIntensity;

    return (uint16)light_intensity;
}
