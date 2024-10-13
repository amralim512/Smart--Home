#include"flame.h"
#include"gpio.h"
#include"LCD.h"
#include"buzzer.h"
#include<util/delay.h>


/*
 * The driver will help us to initialize the flame pin and port
 * and also get the value from the pin and store in a variable
 * to be able to determine the logic state of the pin
 */
void flame_init(){
	// driver initialization to set the pin as an input
	GPIO_setupPinDirection(flame_PORTID,flame_PINID,PIN_INPUT);
	// initial value of the zero to the state in the pin
	GPIO_writePin(flame_PORTID,flame_PINID,LOGIC_LOW);

}

uint8 flame_getValue(void){
	// reading the pin value and determine either its 1,0 to detect flame
	uint8 value=0;
	value=GPIO_readPin(flame_PORTID,flame_PINID);
return value;
}
