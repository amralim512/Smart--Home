#include"LED.h"
#include"LCD.h"
#include"LDR.h"
#include"motor.h"
#include"temperature.h"
#include"gpio.h"
#include"ADC.h"
#include"flame.h"
#include"buzzer.h"
#include"common_macros.h"
#include"pwm.h"
#include<avr/io.h>
#include<util/delay.h>


int main(void){
	/*Function Initialization of all the drivers to be enabling them at the start*/
	LCD_Init();
	ADC_Init();
	LED_init();
	buzzer_init();
	motor_init();
	flame_init();
	/*Initialization of the LCD display to be of stable values in stable positions*/
	LCD_displayStringRowColumn(0,4,"Fan is ");
	LCD_displayStringRowColumn(1,0,"Temp=");
	LCD_displayStringRowColumn(1,8,"LDR=   %");
	/*Variables used to store the ADC values read from the functions*/
	uint8 TEMP_value=0;
	uint16 LDR_value=0;

	while(1){
		/* will start by getting the values of the ADC one by one and store them in the while 1*/
		TEMP_value=temp_getTemperature();
		LDR_value=LDR_getLightIntensity();
		// testing to see in case of flame the system shuts down all of it
		if (flame_getValue()==1){
			LCD_clearScreen();
			LCD_moveCursor(0,0);
			LCD_displayString("CRITICAL ALERT!!"); // display an alert for the user
			buzzer_on(); // turn on the buzzer to alert the user
			//keep shutting the system down and wait till the flame returns a different value
			while(flame_getValue()==1){
				_delay_ms(100);
				//shut the whole system down while the flame is detected
				motor_rotate(STOP,0);
				LED_off(LED_RED);
				LED_off(LED_GREEN);
				LED_off(LED_BLUE);

			}
			// restore the system back and get the same LCD display back on with same values
			buzzer_off();
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,4,"Fan is ");
			LCD_displayStringRowColumn(1,0,"Temp=");
			LCD_displayStringRowColumn(1,8,"LDR=   %");

		}
		// when the flame is one keep acting normally and make the system run and display readings to the user he needs
		else{
           // Display conditions to be user-friendly to display the numbers properly on the screen
			if(LDR_value==100){
				LCD_moveCursor(1,12);
				LCD_integerToString(LDR_value);
			}
			else{
				LCD_moveCursor(1,12);
				LCD_integerToString(LDR_value);
				LCD_displayChar(' ');
			}
			if(TEMP_value>=100){
				LCD_moveCursor(1,5);
				LCD_integerToString(TEMP_value);
			}
			else{
				LCD_moveCursor(1,5);
				LCD_integerToString(TEMP_value);
				LCD_displayChar(' ');
			}
             // Stating the states and cases of LDR sensor to enable the home lighting for the user
			if(LDR_value<=15){
				LED_on(LED_RED);
				LED_on(LED_GREEN);
				LED_on(LED_BLUE);
			}
			else if(LDR_value>15&&LDR_value<=50){
				LED_on(LED_RED);
				LED_on(LED_GREEN);
				LED_off(LED_BLUE);
			}

			else if(LDR_value>50&&LDR_value<=70){
				LED_on(LED_RED);
				LED_off(LED_GREEN);
				LED_off(LED_BLUE);
			}
			else{
				LED_off(LED_RED);
				LED_off(LED_GREEN);
				LED_off(LED_BLUE);
			}
			// Stating the states and cases of temperature sensor to enable the home fan for the user
			if(TEMP_value>=40){
				LCD_moveCursor(0,11);
				LCD_displayString("ON ");
				motor_rotate(CW,255);
			}
			else if(TEMP_value>=35 &&TEMP_value<40){
				LCD_moveCursor(0,11);
				LCD_displayString("ON ");
				motor_rotate(CW,192);
			}
			else if(TEMP_value>=30 &&TEMP_value<35){
				LCD_moveCursor(0,11);
				LCD_displayString("ON ");
				motor_rotate(CW,128);
			}
			else if(TEMP_value>=25 &&TEMP_value<30){
				LCD_moveCursor(0,11);
				LCD_displayString("ON ");
				motor_rotate(CW,64);
			}
			else{
				LCD_moveCursor(0,11);
				LCD_displayString("OFF");
				motor_rotate(STOP,0);
			}
		}
	}
}

