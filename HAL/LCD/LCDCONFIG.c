#include "LCDCONFIG.h"



/* Configure the OnKit Connection */
LCDonKitProps LCDonKit ={
	.sLCD_DataPort      = 'C',
	.sLCD_FirstDataPin  =  0 ,
	.sLCD_ControlPort   = 'C',
};




/* Configure Your LCD Initialization */
sInitInstructions InitInstruction ={
	.sFunctionSet		   = e4Bit_2line_5x7dots,
	.sClearMode			   = eYesClearing,
	.sCharacterEntry	   = eIncrement_ShiftOff,
	.sDisplayAndCursorMode = eLightOn_UnderLOff_BlinkOff
};