#ifndef LCD_H_
#define LCD_H_
#include "LCDCONFIG.h"
#include <util/delay.h>



typedef enum{
	eClearDisplay                 = 0x01,
	eDisplayAndCursorHome         = 0x02,
	eIncrementWhenCharEntry       = 0x06,
	eDecrementWhenCharIntry       = 0x04,
	eIncrementWhenEntry_ShiftOn   = 0x07,
	eDecrementWhenIntry_ShiftOn   = 0x05,
	eDisplayOfforLightOff         = 0x08,
	eDisplayOn_UnderLOff_BlinkOff = 0x0C,
	eDisplayOn_UnderLOff_BlinkOn  = 0x0D,
	eDisplayOn_UnderLOn_BlinkOff  = 0x0E,
	eDisplayOn_UnderLOn_BlinkOn   = 0x0F,
	eShiftEntireDisplayLeft       = 0x18,
	eShiftEntireDisplayRight      = 0x1C,
	eMoveCursorLeft               = 0x10,
	eMoveCursorRight              = 0x14
} eLCDOptions;


void LCD_WriteData(void);
void LCD_WriteCmd(void);
void LCD_vTrigger( void );
void LCD_vInit( void );
void LCD_vNumericSendCmd( INT8U u8Val );
void LCD_vDisplayChar( INT8U u8Val );
void LCD_vDisplayIntegerMax10D(INT32U u8Val );
void LCD_vOptionSendCmd( eLCDOptions Opption );
void LCD_vDisplayString( INT8U* String );
void LCD_GoToXY( INT8U x, INT8U y );

#endif /* LCD_H_ */