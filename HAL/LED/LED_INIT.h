#ifndef LED_INIT_H_
#define LED_INIT_H_
# define F_CPU 8000000UL
#include "DIO.h"
#include "LED_CONFIG.h"


void LED_INIT();
void LED_vWrite( INT8U u8Index, INT8U u8Val );
void LED_Toggle( INT8U u8Index );
INT8U LED_u8Read( INT8U u8Index );


#endif /* LED_INIT_H_ */