/*
 * GPS.c
 *
 * Created: 18/07/2020 19:07:07
 * Author : ADHM
 */ 

#include <avr/io.h>
#include "USART.h"
#include "GPS.h"

	//char buffer [30];
	uint8_t i;
	char x;
int main(void)
{GPS_INI();

i=0;
    /* Replace with your application code */
    while (1) 
    {	GPS_PROCESS();
       // GPS_PRINT();
	
	/*x=USART_RECIVE();
	USART_TRASMIT(x);*/
	}
}
	

