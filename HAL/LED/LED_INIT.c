#include "LED_INIT.h"

void LED_INIT()
{
	INT8U u8Index ;
	for( u8Index=0; u8Index < LED_NUM ; u8Index++ )
			{
				DIO_vSetPinDir( LED_Arr[u8Index].u8Port, LED_Arr[u8Index].u8Pin, eOutput );
			}
}


void LED_vWrite( INT8U u8Index, INT8U u8Val )
{
	if ( u8Index < LED_NUM )
	{
		DIO_vWritePin( LED_Arr[u8Index].u8Port, LED_Arr[u8Index].u8Pin, u8Val  );
	}
	
}


void LED_Toggle( INT8U u8Index )
{
	if ( u8Index < LED_NUM )
	{
		DIO_u8TogglePin( LED_Arr[u8Index].u8Port, LED_Arr[u8Index].u8Pin );
	}
}


INT8U LED_u8Read( INT8U u8Index )
{
	INT8U u8Read=0 ;
	if ( u8Index < LED_NUM )
	{
	return	DIO_u8ReadPin( LED_Arr[u8Index].u8Port, LED_Arr[u8Index].u8Pin );
	}
	return u8Read ;
}