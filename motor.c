#include"common_macros.h"
#include"gpio.h"
#include"motor.h"
#include "pwm.h"

// Motor Pin initialization to be outputs
void motor_init(void){
	GPIO_setupPinDirection(motor_IN1_PORTID,motor_IN1_PINID,PIN_OUTPUT);
	GPIO_setupPinDirection(motor_IN2_PORTID,motor_IN2_PINID,PIN_OUTPUT);
	GPIO_setupPinDirection(motor_EN_PORTID,motor_EN_PINID,PIN_OUTPUT);
}


// Function used to state the motor direction and speed from the user
void motor_rotate(motor_state status,uint8 speed){
	pwm_timer0init(speed);
	switch (status){
	case CW:
		GPIO_writePin(motor_IN1_PORTID,motor_IN1_PINID,LOGIC_HIGH);
		GPIO_writePin(motor_IN2_PORTID,motor_IN2_PINID,LOGIC_LOW);
		break;
	case ACW:
		GPIO_writePin(motor_IN1_PORTID,motor_IN1_PINID,LOGIC_LOW);
		GPIO_writePin(motor_IN2_PORTID,motor_IN2_PINID,LOGIC_HIGH);
		break;
	default:
		GPIO_writePin(motor_IN1_PORTID,motor_IN1_PINID,LOGIC_LOW);
		GPIO_writePin(motor_IN2_PORTID,motor_IN2_PINID,LOGIC_LOW);
		break;
	}
}
