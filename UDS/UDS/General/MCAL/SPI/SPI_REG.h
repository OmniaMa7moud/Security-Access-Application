/*
 * SPI_REG.h
 *
 * Created: 10/30/2023 10:33:10 AM
 *  Author: HP.SXTO10
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPDR *((volatile u8*) 0x2f)
#define SPSR *((volatile u8*) 0x2e)
#define SPCR *((volatile u8*) 0x2d)

#define SPR0 0 
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE  6
#define SPIE 7



#define SPI2X 0
#define WCOL  6
#define SPIF  7

#endif /* SPI_REG_H_ */