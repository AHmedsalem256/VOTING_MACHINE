/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"EXIT0.h"
#include"LCDinterfaceV5.h"
#include"avr/delay.h"


void User_1(void);
void User_2(void);
void User_3(void);

#define MAX 5

u8 user_1Counter = 0 ;
u8 user_2Counter = 0 ;
u8 user_3Counter = 0 ;

u8 WINNER = 0;

void main()
{

	/* SETTING  PULL_UP RESISTORS */

	/* PB2 */

	DIO_VidSetPinDirection(1,2,0);
	DIO_VidSetPinValue(1,2,1);

	/* PD2 */
	DIO_VidSetPinDirection(3,2,0);
	DIO_VidSetPinValue(3,2,1);

	/* PD3 */

	DIO_VidSetPinDirection(3,3,0);
	DIO_VidSetPinValue(3,3,1);


	/* EXIT_FUNCS */

	Exit0_init();


	Exit1_init();
	Exit2_init();


	/* Call_BackFUNCS */

	Call_back_EXIT0(User_1);

	Call_back_EXIT1(User_2);

	Call_back_EXIT2(User_3);

	LCD_VidIntialize();



	while(1)
	{

		LCD_VidGOTOPOS(0,0);
		LCD_VidSendNum(user_1Counter);


		LCD_VidGOTOPOS(0,5);
		LCD_VidSendNum(user_2Counter);


		LCD_VidGOTOPOS(1,0);
		LCD_VidSendNum(user_3Counter);


		/*
		if( user_1Counter || user_2Counter || user_3Counter == MAX )
		{
			LCD_VidSendCommand(0x01);

			LCD_VidSendString("WINNER IS ");
			LCD_VidSendNum(WINNER);

			break;
		}
*/


	}



}

void User_1(void)
{
	user_1Counter ++;

	if(user_1Counter  == MAX )
	{
		WINNER = user_1Counter;
	}

}


void User_2(void)
{
	user_2Counter ++;

	if(user_2Counter  == MAX )
	{
			WINNER = user_2Counter;
	}

}


void User_3(void)
{
	user_3Counter ++;

	if(user_3Counter  == MAX )
	{
		WINNER = user_3Counter;
	}


}

