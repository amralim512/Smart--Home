#include"common_macros.h"
#include"gpio.h"
#include"motor.h"
#include<avr/io.h>

// initialization of the PWM timer to be active with pre-scalar 1024 and taking the needed PWM from the user to be set as compare value
void pwm_timer0init(uint8 duty_cycle){

	TCNT0=0;
	OCR0=duty_cycle;
	GPIO_setupPinDirection(motor_EN_PORTID,motor_EN_PINID,PIN_OUTPUT);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS02)| (1<<CS00);
	SET_BIT(SREG,7);
}
