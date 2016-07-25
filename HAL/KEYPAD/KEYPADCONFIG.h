#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_
#include "MACROS.h"

typedef struct{
	INT8U u8RowsPort;
	INT8U u8FirsRowPin;
	INT8U u8ClumnsPort;
	INT8U u8FirstClumnPin;
	}sKeypad_Props;
	
	
#define  ROWs_NUM     4
#define  COLUMNs_NUM  4

extern sKeypad_Props Keypad;
extern INT8U kpdContents[ROWs_NUM*COLUMNs_NUM];

#endif /* KEYPADCONFIG_H_ */