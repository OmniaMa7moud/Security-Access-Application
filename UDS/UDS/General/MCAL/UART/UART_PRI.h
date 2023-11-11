/*
 * UART_PRI.h
 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */

#ifndef UART_PRI_H_
#define UART_PRI_H_

#define UART_5BITS_CHAR 0
#define UART_6BITS_CHAR 1
#define UART_7BITS_CHAR 2
#define UART_8BITS_CHAR 3
#define UART_9BITS_CHAR 4

#define Asynchronous_Operation 0
#define Synchronous_Operation 1

#define Disabled    0
#define Even_Parity 1
#define Odd_Parity  2


#define ONE_BIT 0
#define TWO_BIT 1

#define RISING_TX 0
#define FALLING_TX 1

#define RISING_RX 1
#define FALLING_RX 0

#define NORMAL_MODE 0
#define DOUBLE_MODE 1
#endif /* UART_PRI_H_ */
