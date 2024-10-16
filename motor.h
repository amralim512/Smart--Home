#ifndef MOTOR_H_
#define MOTOR_H_
/* variable used to state the rotation of the motor direction how it will rotate */
typedef enum{
	CW,ACW,STOP
} motor_state;

#define motor_IN1_PORTID PORTB_ID  // define motor port for input 1
#define motor_IN1_PINID PIN0_ID // define motor pin for input 1

#define motor_IN2_PORTID PORTB_ID  // define motor port for input 2
#define motor_IN2_PINID PIN1_ID  // define motor pin for input 2

#define motor_EN_PORTID PORTB_ID  // define motor port for enable
#define motor_EN_PINID PIN3_ID    // define motor pin for enable

/*Motor Function Prototype to initialize the motor and give the speed and rotation direction*/
void motor_init();
void motor_rotate(motor_state status,uint8 speed);


#endif /* MOTOR_H_ */
