/*
 * LCD_config.h
 *
 * Created: 10/20/2023 2:34:18 PM
 *  Author: omnia
 */ 
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/std_macros.h"


/*
LCD_instruction(0x80); //Write on 1st line
LCD_instruction(0xC0); //Write on 2nd line
LCD_instruction(0x94); //Write on 3rd line
LCD_instruction(0xD4); //Write on 4th line
*/
	
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RSPORT PD
#define RSPIN PIN4

#define ENPORT PD
#define ENPIN PIN6

#define LCD_PORT PC

#define LCD_D4 PIN4
#define LCD_D5 PIN5
#define LCD_D6 PIN6
#define LCD_D7 PIN7


//NOTE: set pin directions in DIO_config.h
#endif /* LCD_CONFIG_H_ */