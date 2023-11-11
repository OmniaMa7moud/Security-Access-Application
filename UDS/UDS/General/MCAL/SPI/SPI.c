/*
 * SPI.c
 *
 * Created: 10/30/2023 10:31:36 AM
 *  Author: HP.SXTO10
 */ 
#include "SPI_INT.h"

void (*SPICallbackFunc)(void) = NULL;

void SPI_MASTER_INIT(void)
{
	SET_BIT(SPCR, MSTR);
	
	switch(INTERRUPT_MODE)
	{
		case 0:
			CLR_BIT(SPCR, SPIE);
			break;
		
		case 1:
			SET_BIT(SPCR, SPIE);
			break;
		default:
			break;
	}
	switch(DATA_ORDER)
	{
		case 0:
			CLR_BIT(SPCR, DORD);
			break;
		
		case 1:
			SET_BIT(SPCR, DORD);
			break;
		default:
		break;
	}

	switch(CLOCK_POLARITY)
	{
		case 0:
			CLR_BIT(SPCR, CPOL);
			break;
		
		case 1:
			SET_BIT(SPCR, CPOL);
			break;
		default:
			break;
	}
	switch(CLOCK_PHASE)
	{
		case 0:
			CLR_BIT(SPCR, CPHA);
			break;
		
		case 1:
			SET_BIT(SPCR, CPHA);
			break;
		default:
			break;
	}
	switch(SPI_FREQUENCY)
	{
		case 0:
			CLR_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;
		
		case 1:
			SET_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;
		case 2:
			CLR_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			break;
		case 3:
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			break;
		default:
			break;
	}
	switch(DOUBLE_SPEED_STATE)
	{
		case 0:
			CLR_BIT(SPSR, SPI2X);
			break;
		
		case 1:
			SET_BIT(SPSR, SPI2X);
			break;
		default:
			break;
	}
	SET_BIT(SPCR,SPE);
}

void SPI_voidSlaveInit(void)
{
	CLR_BIT(SPCR, MSTR);
	
	switch(INTERRUPT_MODE)
	{
		case 0:
			CLR_BIT(SPCR, SPIE);
			break;
		
		case 1:
			SET_BIT(SPCR, SPIE);
			break;
		default:
			break;
	}
	switch(DATA_ORDER)
	{
		case 0:
			CLR_BIT(SPCR, DORD);
			break;
		
		case 1:
			SET_BIT(SPCR, DORD);
			break;
		default:
		break;
	}

	switch(CLOCK_POLARITY)
	{
		case 0:
			CLR_BIT(SPCR, CPOL);
			break;
		
		case 1:
			SET_BIT(SPCR, CPOL);
			break;
		default:
			break;
	}
	switch(CLOCK_PHASE)
	{
		case 0:
			CLR_BIT(SPCR, CPHA);
			break;
		
		case 1:
			SET_BIT(SPCR, CPHA);
			break;
		default:
			break;
	}
	switch(SPI_FREQUENCY)
	{
		case 0:
			CLR_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;
		
		case 1:
			SET_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;
		case 2:
			CLR_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			break;
		case 3:
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			break;
		default:
			break;
	}
	switch(DOUBLE_SPEED_STATE)
	{
		case 0:
			CLR_BIT(SPSR, SPI2X);
			break;
		
		case 1:
			SET_BIT(SPSR, SPI2X);
			break;
		default:
			break;
	}
	SET_BIT(SPCR,SPE);
}

u8 SPI_u8Transfer(u8 Copy_Data)
{
	SPDR = Copy_Data;
	while(!READ_BIT(SPSR, SPIF));
	return SPDR;
}

u8 SPI_u8Recieve(u8 Copy_Data)
{
	SPDR = Copy_Data;
	while(!READ_BIT(SPSR, SPIF));
	return SPDR;
}

u8 SPI_u8ReadDataISR(void)
{
	return SPDR;
}

void SPI_voidSendDataISR(u8 Copy_Data)
{
	SPDR = Copy_Data;
}

void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
	SPICallbackFunc = PtrToFunc;
}

void __vector_12 (void) __attribute__ ((signal,used, externally_visible));
void __vector_12 (void) { if(SPICallbackFunc != NULL){ SPICallbackFunc();}  }