#include "ADC.h"

#include "common_macros.h"
#include"gpio.h"
#include"LCD.h"
#include<avr/io.h>

void ADC_Init(void){
	/* ADC initialization to be making the driver of prescalar 128
	 * enabling the registered bits to our configurations
	 * internal ref volt =2.56v
	 */
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}
uint16 ADC_readChannel(uint8 chNum){
	/* setting the channel to read from the 1st 7 bits in the channels
	 * of the micro-contorller and set them in the ADMUX register of the
	 *  bits responsible for it
	 */
	chNum&=0x07;
	ADMUX&= 0xE0;
	ADMUX|=chNum;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){ // polling to wait until the flag gets cleared and break for the interrupt of ADC
	}
	SET_BIT(ADCSRA,ADIF);


	return ADC; // return the ADC value read from channel we give
}
