/*
 * main.c
 *
 * Created: 10/20/2023 11:49:57 AM
 *  Author: omnia
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/SPI/SPI_INT.h"
#include "../MCAL/UART/UART_INTERFACE.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../HAL/LCD/LCD.h"

	u8 request[5];
	u8 randNum[9];
	u8 inputArr[9];
    u8 securityFlag = 0;

void AccessSecurity(void)
{
	
	UART_receiveString(inputArr);
	if( !strcmp( inputArr,  "2701" ) )
	{
		LCD_instruction(CLEAR_DISPLAY);
		 LCD_MOVE_CURSOR(1,1);
		 LCD_SEND_STRING("6701 ");
		for(u8 i=0; i<8; i++) { randNum[i] =  (random() % 10); randNum[i] += 48;}
		for(u8 i=0; i<8; i++) { LCD_write_char(randNum[i]);}
		for(u8 i=0; i<8; i++) {   if(randNum[i] == '9'){randNum[i] = '0'; continue;} randNum[i]++; }
		randNum[8] = '\0';
		for(u8 i=0; i<8; i++) { inputArr[i] = 0;}
		UART_receiveString(request);
		UART_receiveString(inputArr);
		if( /* (!strcmp( request, "2702 ")) && */(!strcmp( inputArr, randNum)) ) 
		{   securityFlag = 1;
			LCD_instruction(CLEAR_DISPLAY); 
			LCD_MOVE_CURSOR(1,1);
			LCD_SEND_STRING("6701 ");
		}
		else
		{   securityFlag = 0;
			LCD_instruction(CLEAR_DISPLAY);
			LCD_MOVE_CURSOR(1,1);
			LCD_SEND_STRING("7F 27 35 ");
		}
	}
}


int main()
{
	DIO_init();
	KEYPAD_INIT();
	LCD_INIT();
	_delay_ms(500);
	UART_init(9600);
	UART_RX_ENABLE();
	UART_TX_ENABLE();
	

	while(1)
	{
		UART_receiveString(inputArr);
		if( !strcmp( inputArr,  "3101AA00" ) )
		{
			if(securityFlag == 0)
			{
			 LCD_instruction(CLEAR_DISPLAY); 
			 LCD_MOVE_CURSOR(1,1);
			 LCD_SEND_STRING("NRC 7F 31 35"); 
			  AccessSecurity();
			 //UART_String_Transmit("NRC 7F 31 35");
			 }
			 else if(securityFlag == 1)
			 {
				  LCD_instruction(CLEAR_DISPLAY);
				  LCD_MOVE_CURSOR(1,1);
				  LCD_SEND_STRING("7101AA00");
				 // UART_String_Transmit("7101AA00");
				 DIO_SetPinVal(PC, 0, 1);
			 }
		}
	}
		
}
