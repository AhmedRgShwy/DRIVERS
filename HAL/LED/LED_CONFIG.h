#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define  LED_NUM	2


#include "DIO.h"

typedef struct
{
	INT8U u8Port ;
	INT8U u8Pin ;
	
	}LED_PROP;
	
extern LED_PROP LED_Arr[LED_NUM] ;



#endif /* LED_CONFIG_H_ */