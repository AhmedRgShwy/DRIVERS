#include "MACROS.h"
#ifndef DIO_H_
#define DIO_H_
# define F_CPU 8000000UL
#include <avr/io.h>
#include "MyLibrary.h"

typedef enum
{
	eInput=0, eOutput=1
	} ePinDir;


void DIO_vSetPinDir ( INT8U u8Port, INT8U pin, ePinDir eDir );
void DIO_vWritePin ( INT8U u8Port, INT8U u8PinNum, INT8U u8Val );
INT8U DIO_u8ReadPin ( INT8U u8Port, INT8U u8PinNum );
void DIO_u8TogglePin ( INT8U u8Port, INT8U u8PinNum );
void DIO_vSetPortRangeDir ( INT8U u8Port, INT8U FirstPin, INT8U LastPin, ePinDir eDir );
void DIO_vWritePortRange ( INT8U u8Port, INT8U FirstPin, INT8U LastPin, INT8U u8Val );
INT8U DIO_u8ReadPortRange ( INT8U u8Port, INT8U FirstPin, INT8U LastPin );
void DIO_u8ToglePortRange ( INT8U u8Port, INT8U FirstPin, INT8U LastPin );
void DIO_vWriteByteOnPort ( INT8U u8Port, INT8U u8Val );             
void DIO_vWriteNibbleOnPort ( INT8U u8Port, INT8U FirstPin, INT8U NibbleVal );        
void DIO_vWriteBitsNumValueOnPort( INT8U u8Port, INT8U u8FirstPin, INT8U BitsNum, INT8U u8Val );


void DIO_vSetMultiPinDirOnPort( INT8U u8Port, INT8U BinaryDirSet, INT8U BinVal_1ToSelect_0ToNeglect );
void DIO_vWriteMultiPinValOnPort( INT8U u8Port, INT8U BinaryValSet, INT8U BinVal_1ToSelect_0ToNeglect );
void DIO_vToggleMultiPinValOnPort( INT8U u8Port, INT8U BinToggleSet );

#endif /* DIO_H_ */