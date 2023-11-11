/*
 * SPI_INT.h
 *
 * Created: 10/30/2023 10:32:14 AM
 *  Author: HP.SXTO10
 */ 

#include "SPI_CONFIG.h"
#include "SPI_PRI.h"
#include "SPI_REG.h"
#include "../../LIB/std_macros.h"

#ifndef SPI_INT_H_
#define SPI_INT_H_



void SPI_MASTER_INIT(void);
void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);
u8 SPI_u8Recieve(u8 Copy_Data);

u8 SPI_u8ReadDataISR(void);
void SPI_voidSendDataISR(u8 Copy_Data);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );


#endif /* SPI_INT_H_ */