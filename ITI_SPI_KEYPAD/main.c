/*
 * main.c
 *
 *  Created on: Jan 17, 2023
 *      Author: nadin
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "SPI.h"
#include "KEYPAD.h"

#include "util/delay.h"

int main(void)
{

	uint8 u8PressedLoc;
		DIO_voidInit();
		SPI_voidInitMaster();
		DIO_enuWritePin(DIO_PIN_NUM_12,DIO_LOW);
		KEYPAD_voidInit();
		uint8 flag=0,u8TransmitLoc;
		while(1)
		{

			//_delay_ms(1000);

			u8PressedLoc = KEYPAD_u8GetPressedKey(0);


			if(u8PressedLoc != 0xFF)
			{

				if(flag == 0)
				{
					DIO_enuWritePin(DIO_PIN_NUM_16,DIO_HIGH);

					_delay_ms(100);
					u8TransmitLoc = SPI_u8MasterTransmit(u8PressedLoc);
					//_delay_ms(1000);
				  flag = 1;
				}

			}
			else
			{
				flag=0;
			}

		}
}

