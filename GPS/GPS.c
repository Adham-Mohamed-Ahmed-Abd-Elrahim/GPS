/*
 * GPS.c
 *
 * Created: 18/07/2020 21:13:11
 *  Author: ADHM
 */ 
#include "GPS.h"
char Latitude[15],Longitude[15],Time[15],Altitude[8];
char mess[7];
 char NS_indicator[2];
  char EW_indicator[2];
  char SAT_NUM[3];
  char F_pos[4];
  char hr[3];
  char min[3];
  char sec [6];
  char degree[15];
 double res;
 void GET_LONG(char *data)
 {res=0;
	 char deg[4];
	 volatile uint8_t i;
	 for(  i=0;i<3;i++)
	 {deg[i]=data[i];}
	 char m[6];
	 for( i=0;i<6;i++)
	 {m[i]=data[i+3];}
	 

	 res=((atof(m))/60)+atof(deg);

	 //res+=(atof(min)-(int)atof(min))/3600;
	 dtostrf(res,6,4,degree);
	 print(degree);
	 USART_TRASMIT('\r');

 }
void GET_LAT(char *data)
  {res=0;
	  char deg[3];
	  volatile uint8_t i;
	  	for(  i=0;i<2;i++)
	  	{deg[i]=data[i];}
			char m[6];  
	for( i=0;i<6;i++)
	{m[i]=data[i+2];}
	

	res=((atof(m))/60)+atof(deg);

	//res+=(atof(min)-(int)atof(min))/3600;
 dtostrf(res,6,4,degree);
print(degree);
USART_TRASMIT('\r');

  }
void GET_TIME(char*data)
{
	/*min[0]=data[2];
	min[1]=data[3];*/
	
	for( uint8_t i=0;i<2;i++)
	{hr[i]=data[i];}
		/*uint8_t hrs=atoi(hr);
		USART_TRASMIT(hrs);*/
		//USART_TRASMIT(hrs);
	//	USART_TRASMIT('a');
		for(uint8_t j=0;j<2;j++)
		{min[j]=data[(j+2)];
			
	}	
			/*uint8_t mins=atoi(min);
				USART_TRASMIT(mins);*/
					
			for( uint8_t k =0;k<5;k++)
			{sec[k]=data[(k+4)];
			}
	//	float secs=atof(sec);
		//USART_TRASMIT(secs);

	
	

	/*while (! (UCSRA & (1<<UDRE)));
	//while(!(READ_BIT(UCSRA,UDRE)));
	UDR=hrs;
	while (! (UCSRA & (1<<UDRE)));
	//while(!(READ_BIT(UCSRA,UDRE)));
	UDR=mins;
		while (! (UCSRA & (1<<UDRE)));
		//while(!(READ_BIT(UCSRA,UDRE)));
		UDR=mins;*/
			
	
	
	}
void GPS_INI()
{
		USART_INI(  NORMAL,9600);
		USART_MOOD(  ASYNC,   NO_CLK);
		USART_DATA_SETTING(  EIGHT,NO_PARITY,ONE);
			/*USART_INI(  NORMAL,9600);
			USART_MOOD(  ASYNC,   NO_CLK);
			USART_DATA_SETTING(  EIGHT,NO_PARITY,ONE);*/
			//MAKING TX as output 
		SET_BIT(DDRD,1);
	
}

/*char * FIND()
{char data='a';
	static char buffer[20];
	for(uint8_t i=0;data!=',';i++)
	{buffer[i]=USART_RECIVE();
	}
	return buffer;
}*/
//**********************************
void GET(char *buffer)
{uint8_t i=0;
	while(1)
	{buffer[i]=USART_RECIVE();
		if(buffer[i]==','){break;}
		i++;
	}
	buffer[i]='\r';
	i=0;
	
	}
	//*****************************
/*void copy(char *a,char*b)
{for(uint8_t i=0;i<strlen(b);i++)
	{a[i]=b[i];
		
	}
	
}*/

void GPS_PROCESS()
{
	if(USART_RECIVE()=='$')
	{GET(mess);
		if((mess[2]=='G')&&(mess[3]=='G')&&(mess[4]=='A'))
		{   
			GET(Time);
	        GET(Latitude);
			GET(NS_indicator);
			GET(Longitude);
			GET(EW_indicator);
			GET(SAT_NUM);
			GET(F_pos);
			GET(Altitude);
			
			GET_TIME(Time);
			
		GPS_PRINT();
//print(Longitude);
		}
	}
}
	/*print("t/r");
	print(Time);*/
//GPS_PRINT();

	
	//************************

	void print(char * buffer)
	{{for(uint8_t i=0 ;i<strlen(buffer);i++)
		{USART_TRASMIT(buffer[i]);
		}
	}
}
//***************************
		void GPS_PRINT()
		{	 //   print("Time:\r");
			print("time[]\r");
				print("HRS:");
				print(hr);
				print("mins:");
				print(min);
				print("sec:");
				print(sec);
				USART_TRASMIT('\r');
			//print(Time);
			//_delay_ms(8);
			print("Lat:");
		GET_LAT(Latitude);
			//	_delay_ms(8);
			print("N/S:");
			print(NS_indicator);
				//_delay_ms(8);
			print("long:");
			GET_LONG(Longitude);
				//_delay_ms(8);
			print("E/W:");
			print(EW_indicator);
				//_delay_ms(8);
				
				print("SAT:");
				print(SAT_NUM);
				//_delay_ms(8);
				
				print("Fix_P:");
				print(F_pos);
				//_delay_ms(8);
				
				print("Altitude:");
				print(Altitude);
				//_delay_ms(8);
			
				
				
	
		}
	
	
	
