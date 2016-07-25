#include "KEYPADCONFIG.h"


/* Inform the drive how your keypad implemented on your kit */
sKeypad_Props Keypad = {
	.u8RowsPort = 'D',
	.u8FirsRowPin = 0,
	.u8ClumnsPort = 'D',
	.u8FirstClumnPin = 4
	};

 INT8U kpdContents[ROWs_NUM*COLUMNs_NUM]=
{7,8,9,'/',4,5,6,'*',1,2,3,'-','o',0,'=','+'};