

#ifndef SPI_PRIV_H
#define SPI_PRIV_H

#define MASTER    0
#define SLAVE     1

#define LSB      0
#define MSB      1

#define CLK_IDLE_LOW    0
#define CLK_IDLE_HIGH   1

#define SETUP_TRL     0
#define SETUP_LEAD    1

#define SPI_PRE_2      0
#define SPI_PRE_4      1
#define SPI_PRE_8      2
#define SPI_PRE_16     3
#define SPI_PRE_32     4
#define SPI_PRE_64     5 
#define SPI_PRE_128    6


#define SPDR *((volatile uint8 * ) 0x2F)
#define SPCR *((volatile uint8 * ) 0x2D)
#define SPSR *((volatile uint8 * ) 0x2E)
#endif