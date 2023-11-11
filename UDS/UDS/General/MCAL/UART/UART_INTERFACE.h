/*
 * UART_INTERFACE.h
 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */



#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#include "UART_CONFIG.h"
#include "UART_PRI.h"
#include "UART_REG.h"
#include "../../LIB/std_macros.h"

void UART_init( u16 baud );
void UART_TX_ENABLE(void);
void UART_RX_DISABLE(void);
void UART_RX_ENABLE(void);
void UART_TX_DISABLE(void);
void USART_Transmit( u8 data );
u8 USART_Receive( );
void UART_String_Transmit( u8* data );
void UART_receiveString(u8 *Str);

#endif /* UART_INTERFACE_H_ */
