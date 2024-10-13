#ifndef LED_H_
#define LED_H_
/* Define the logic of the LED connection type */
#define postive_logic
#ifdef postive_logic
#define LOW 0
#define HIGH 1
#elif negative_logic
#define LOW 1
#define HIGH 0
#endif

// Variable used to initiate which led will be use in the functions
typedef enum{
	LED_RED=5,LED_GREEN=6,LED_BLUE=7
}LED_ID;


#define LED_PORTID PORTB_ID // Define LED Port ID for all LEDs

// Define LEDs Pin IDs for all 3 led
#define LED_red_PINID PIN5_ID
#define LED_green_PINID PIN6_ID
#define LED_blue_PINID PIN7_ID
/*Function Declaration for the LED driver to initiate
* direction and which LED to turn on or off*/
void LED_init();
void LED_on (LED_ID id);
void LED_off(LED_ID id);


#endif /* LED_H_ */
