#include "STD_Types.h"
#include "BIT_Math.h"

#include "SPI.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"

static uint8 SPI_u8ReceiveBuffer =0;
static tSpiStatus SPI_enuStatus = NOT_INIT  ;
#if SPI_CHIP_REL == MASTER 
void SPI_voidInitMaster(void)
{
uint8 u8SPCR = 0b01010000;
uint8 u8SPSR = 0;
#if SPI_DATA_ORDER ==LSB
SET_BIT(u8SPCR , 5);
#else
CLR_BIT(u8SPCR , 5);	
#endif
#if SPI_CLK_IDLE_STATE == CLK_IDLE_LOW 
CLR_BIT(u8SPCR , 3);
#else
SET_BIT(u8SPCR , 3);	
#endif
	
#if   SPI_CLK_PRESCALLER == SPI_PRE_2
CLR_BIT(u8SPCR , 0);
CLR_BIT(u8SPCR , 1);
SET_BIT(u8SPSR , 0);
#elif SPI_CLK_PRESCALLER == SPI_PRE_4 
CLR_BIT(u8SPCR , 0);
CLR_BIT(u8SPCR , 1);
CLR_BIT(u8SPSR , 0);     
#elif SPI_CLK_PRESCALLER == SPI_PRE_8 
SET_BIT(u8SPCR , 0);
CLR_BIT(u8SPCR , 1);
SET_BIT(u8SPSR , 0);     
#elif SPI_CLK_PRESCALLER == SPI_PRE_16 
SET_BIT(u8SPCR , 0);
CLR_BIT(u8SPCR , 1);
CLR_BIT(u8SPSR , 0);    
#elif SPI_CLK_PRESCALLER == SPI_PRE_32 
CLR_BIT(u8SPCR , 0);
SET_BIT(u8SPCR , 1);
SET_BIT(u8SPSR , 0);     
#elif SPI_CLK_PRESCALLER == SPI_PRE_64  
CLR_BIT(u8SPCR , 0);
SET_BIT(u8SPCR , 1);
CLR_BIT(u8SPSR , 0);     
#else 
SET_BIT(u8SPCR , 0);
SET_BIT(u8SPCR , 1);
CLR_BIT(u8SPSR , 0); 
#endif	

#if SPI_CLK_PHASE == SETUP_TRL
CLR_BIT(u8SPCR , 2);
#else
SET_BIT(u8SPCR , 2);
#endif
SPCR = u8SPCR ;
SPSR = u8SPSR ;
SPDR = 0;
	
}
uint8 SPI_u8MasterTransmit(uint8 u8DataCpy)
{
	SPDR = u8DataCpy ;
	while(GET_BIT(SPSR,7)==0);
	return SPDR ;
}

#else
void SPI_voidInitSlave(void)
{
	uint8 u8SPCR = 0b01000000;
	uint8 u8SPSR = 0;
	#if SPI_DATA_ORDER ==LSB
	SET_BIT(u8SPCR , 5);
	#else
	CLR_BIT(u8SPCR , 5);	
	#endif
	#if SPI_CLK_IDLE_STATE == CLK_IDLE_LOW 
	CLR_BIT(u8SPCR , 3);
	#else
	SET_BIT(u8SPCR , 3);	
	#endif
	
	#if SPI_CLK_PHASE == SETUP_TRL
	CLR_BIT(u8SPCR , 2);
	#else
	SET_BIT(u8SPCR , 2);
	#endif
	
SPCR = u8SPCR ;
SPSR = u8SPSR ;
	

	
}

void SPI_u8SlaveSend(uint8 u8DataCpy)
{
	if (SPI_enuStatus == IDLE)
	{
		SPDR  = u8DataCpy ;
		SPI_enuStatus = IN_PROGRESS ;
	}
	else
	{
		/*DoNothing*/
	}
}

tSpiStatus SPI_u8SlaveReceive(uint8 *pu8DataCpy)
{
	if (GET_BIT(SPSR,7)==1)
	{
		*pu8DataCpy = SPDR ;
		SPI_enuStatus = IDLE ;
	}
	else 
	{
		/*DoNothing*/
	}
	return SPI_enuStatus ;
}

#endif

void SPI_voidEnableInt(void)
{
	SET_BIT(SPCR,7);
}
void SPI_voidDisableInt(void)
{
	CLR_BIT(SPCR,7);
}
void SPI_voidSendAsync(uint8 u8DataCpy)
{
	if (SPI_enuStatus == IDLE)
	{
		SPDR  = u8DataCpy ;
		SPI_enuStatus = IN_PROGRESS ;
	}
	else
	{
		/*DoNothing*/
	}
}
tSpiStatus SPI_u8ReceiveAsync(uint8 *pu8ReciveDataCpy)
{
	*pu8ReciveDataCpy =  SPI_u8ReceiveBuffer ;
	return SPI_enuStatus ;
}
void __vector_12 (void) __attribute__ ((signal ,used));
void __vector_12 (void)
{
	SPI_u8ReceiveBuffer = SPDR ;
	SPI_enuStatus = IDLE ;
}
