#include "LED.h"
#include"gpio.h"
//LED initialization of the pins and pots to be outputs and set them by zero in the start
void LED_init(){
	GPIO_setupPinDirection(LED_PORTID,LED_red_PINID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORTID,LED_green_PINID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORTID,LED_blue_PINID,PIN_OUTPUT);
	GPIO_writePin(LED_PORTID,LED_red_PINID,LOW);
	GPIO_writePin(LED_PORTID,LED_green_PINID,LOW);
	GPIO_writePin(LED_PORTID,LED_blue_PINID,LOW);
}
// Functions turns on the LED from the variables made taken by the user
void LED_on(LED_ID id){
	GPIO_writePin(LED_PORTID,id,HIGH);
}


// Functions turns off the LED from the variables made taken by the user
void LED_off(LED_ID id){
	GPIO_writePin(LED_PORTID,id,LOW);
}
