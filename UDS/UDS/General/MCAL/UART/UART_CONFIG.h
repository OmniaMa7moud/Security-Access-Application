/*
 * UART_CONFIG.h
 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "UART_PRI.h"

#define UART_CHAR_SIZE 		UART_8BITS_CHAR
#define USART_Mode_Select 	Synchronous_Operation
#define PARITY_MODE 		Disabled
#define STOP_BIT_SELECT	 	ONE_BIT
#define CLOCK_POLARITY		RISING_TX
#define SPEED_MODE 			NORMAL_MODE
#endif /* UART_CONFIG_H_ */
