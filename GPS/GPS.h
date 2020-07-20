/*
 * GPS.h
 *
 * Created: 18/07/2020 21:13:20
 *  Author: ADHM
 */ 


#ifndef GPS_H_
#define GPS_H_
#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "USART.h"
void GPS_INI();
void GPS_PROCESS();
char * FIND();
void GET(char *buffer);
void print(char * buffer);
	void GPS_PRINT();
//void TO_DEC(char * data);
void GET_TIME(char*data);
void GET_LAT(char *data);
 void GET_LONG(char *data);
#endif /* GPS_H_ */