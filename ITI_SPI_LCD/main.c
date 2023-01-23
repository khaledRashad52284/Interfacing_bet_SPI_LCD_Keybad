/*
 * main.c
 *
 *  Created on: Jan 14, 2023
 *      Author: AA
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "SPI.h"
#include "LCD.h"
#include "util/delay.h"

int main(void)
{
	uint8 Local_u16Receive ;
    DIO_voidInit();
	SPI_voidInitSlave();
    LCD_voidInit();

	while(1)
	{


		Local_u16Receive = SPI_u8SlaveReceive();
	//	if(Local_u16Receive==5)
	//	LCD_voidDisplayChar(0,Local_u16Receive);
	//	else
		LCD_voidDisplayChar(0,(Local_u16Receive/2));



		 /* switch(Local_u16Receive)
		  {
		  case '0':
			  LCD_voidDisplayChar(0,'0');
			  break;
		  case '1':
			  LCD_voidDisplayChar(0,'1');
			  break;
		  case '2':
			  LCD_voidDisplayChar(0,'2');
			  break;
		  case '3':
			  LCD_voidDisplayChar(0,'3');
			  break;
		  case '4':
			  LCD_voidDisplayChar(0,'4');
			  break;
		  case '5':
			  LCD_voidDisplayChar(0,'5');
			  break;

		  }*/



		  }

	}



