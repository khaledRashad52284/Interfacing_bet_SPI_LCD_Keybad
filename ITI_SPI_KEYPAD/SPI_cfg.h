
#ifndef SPI_CFG_H
#define SPI_CFG_H


#define SPI_CHIP_REL         MASTER
#define SPI_DATA_ORDER       LSB

#define SPI_CLK_IDLE_STATE   CLK_IDLE_LOW 
#define SPI_CLK_PHASE        SETUP_TRL

#if SPI_CHIP_REL ==  MASTER
#define SPI_CLK_PRESCALLER   SPI_PRE_4
#endif

#endif
