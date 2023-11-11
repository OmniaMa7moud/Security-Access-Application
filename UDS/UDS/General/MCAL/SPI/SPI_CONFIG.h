/*
 * SPI_CONFIG.h
 *
 * Created: 10/30/2023 10:31:51 AM
 *  Author: HP.SXTO10
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/*Enable SPI Interrupt Mode*/
/*
 * ENABLE_INTERRUPT
 * DISABLE_INTERRUPT
 *
 */
 
#define INTERRUPT_MODE ENABLE_INTERRUPT


/*SPI Data Order*/
/*
 * LSB_FIRST
 * MSB_FIRST
 *
 */

#define DATA_ORDER  LSB_FIRST

/*
 * Clock Polarity mode
 * IDLE_LOW >> leading edge is rising
 * IDLE_HIGH >> leading edge is falling
 *
 */
#define CLOCK_POLARITY  IDLE_LOW



/* Clock Phase Mode
 *
 * ZERO >> sample at leading and setup at trailing
 * ONE >> sample at trailing and setup at rising
 *
 */

#define CLOCK_PHASE ZERO

/* CLOCK
 *
 * PRESCALLER4
 * PRESCALLER16
 * PRESCALLER64
 * PRESCALLER128
 * 
 *
 */

#define SPI_FREQUENCY	PRESCALLER4



/*
*
*ENABLE
*DISABLE
*
*/
#define DOUBLE_SPEED_STATE ENABLE

#endif /* SPI_CONFIG_H_ */