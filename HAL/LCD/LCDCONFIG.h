
#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#include "DIO.h"

/*configure your LCD types supported( 1x16, 2x16, 4x16, 2x20, 4x20, 2x40, 4x40 )*/
#define LCD_ROWsNUM		2
#define LCD_CLUMNsNUM	16

/* Configure your OnKit Control pins */
#define EN  4
#define RW  5
#define RS  6


typedef enum{
	e4Bit_1line_5x7dots  = 0x20,
	e4Bit_1line_5x10dots = 0x24,
	e4Bit_2line_5x7dots  = 0x28,
	e4Bit_2line_5x10dots = 0x2C,
	e8Bit_1line_5x7dots  = 0x30,
	e8Bit_1line_5x10dots = 0x34,
	e8Bit_2line_5x7dots  = 0x38,
	e8Bit_2line_5x10dots = 0x3C
	} eFunctionSet;



typedef enum{
	eLCDLightOffOrDisplayOff    = 0x08,
	eLightOn_UnderLOff_BlinkOff = 0x0C,
	eLightOn_UnderLOff_BlinkOn  = 0x0D,
	eLightOn_UnderLOn_BlinkOff  = 0x0E,
	eLightOn_UnderLOn_BlinkOn   = 0x0F
	} eDisplayAndCursorMode;


typedef enum{
	eNoClearing,
	eYesClearing
	} eCleraingMode;
	

typedef enum{
	eDecrement_ShiftOff = 0x04,
	eDecrement_ShiftOn  = 0x05,
	eIncrement_ShiftOff = 0x06,
	eIncrement_ShiftOn  = 0x07
	} eCharacterEntryMode;



typedef struct{
	eFunctionSet			sFunctionSet;
	eCleraingMode			sClearMode;
	eCharacterEntryMode		sCharacterEntry;
	eDisplayAndCursorMode	sDisplayAndCursorMode;
} sInitInstructions;


typedef struct {
	INT8U			sLCD_DataPort;
	INT8U			sLCD_FirstDataPin;
	INT8U			sLCD_ControlPort;
} LCDonKitProps;


extern LCDonKitProps LCDonKit ;
extern sInitInstructions InitInstruction;

#endif /* LCDCONFIG_H_ */