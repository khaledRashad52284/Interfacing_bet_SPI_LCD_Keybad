

#ifndef SPI_H
#define SPI_H
typedef enum {
	NOT_INIT,
	IDLE,
	IN_PROGRESS
}tSpiStatus;



void SPI_voidInitMaster(void);
uint8 SPI_u8MasterTransmit(uint8 u8DataCpy);

void SPI_voidInitSlave(void);
void SPI_u8SlaveSend(uint8 u8DataCpy);
uint8 SPI_u8SlaveReceive(void);
//tSpiStatus SPI_u8SlaveReceive(uint8 *pu8DataCpy);


void SPI_voidEnableInt(void);
void SPI_voidDisableInt(void);
void SPI_voidSendAsync(uint8 u8DataCpy);
tSpiStatus SPI_u8ReceiveAsync(uint8 *pu8ReciveDataCpy);



#endif
