#ifndef LCD_H_
#define LCD_H_
#include"gpio.h"

#define LCD_RS_PORTID PORTD_ID // define the RS port in the LCD driver
#define LCD_RS_PINID  PIN0_ID  // define the RS pin in the LCD driver

#define LCD_Enable_PORTID  PORTD_ID // define the EN port in the LCD driver
#define LCD_Enable_PINID   PIN1_ID  // define the EN pin in the LCD driver
#define LCD_dataPath_PORTID PORTC_ID // define the data path port in the LCD driver

// set of commands used by the LCD driver can help in ease of sending the command
#define twoLine8bit_mode 0x38  // define the mode to two line and 8 bits
#define cursor_off 0x0c    // turns off the cursor from the LCD screen
#define clear_command 0x01  // clear all the screen
#define set_cursorLocation 0x80 // define the location of the cursor

/*Functions Initialization for the used by the driver */
void LCD_sendCommand(uint8 command);
void LCD_Init(void);
void LCD_displayChar(uint8 character);
void LCD_displayString(const char *str);
void LCD_clearScreen(void);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col, const char *str);
void LCD_integerToString(int data);




#endif
