
#include "LCD.h"

void LCD_WriteData(void)
{
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, RS, 1 );	         /*   Data Mode                  */
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, RW, 0 );           /*   Write Mode                 */	
}


void LCD_WriteCmd(void)
{
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, RS, 0 );           /*   Command Mode               */
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, RW, 0 );           /*   Write Mode                 */	
}


void LCD_vTrigger( void )
{
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, EN, 0 );           /*   Enable Mode                */
	_delay_ms(2);				                                 /*   Delay for complete Writing */
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, EN, 1 );           /*   Disable Mode               */	
}


void LCD_vInit( void )
{
	switch(( (InitInstruction.sFunctionSet) & (1<<4) ) >> 4 )  
	{
		case 0:
		DIO_vSetPortRangeDir( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (LCDonKit.sLCD_FirstDataPin)+3, eOutput );
		break;
		case 1:
		DIO_vSetPortDir(LCDonKit.sLCD_DataPort, OUTPUT );
		/*DIO_vSetPortRangeDir( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, 7, eOutput );*/
		break;
		default: break;
	}
	/*DIO_vSetPortRangeDir( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCDMode-1, eOutput );*/
	DIO_vSetPinDir( LCDonKit.sLCD_ControlPort, EN, eOutput );
	DIO_vSetPinDir( LCDonKit.sLCD_ControlPort, RW, eOutput );
	DIO_vSetPinDir( LCDonKit.sLCD_ControlPort, RS, eOutput );
	
	if ((( (InitInstruction.sFunctionSet) & (1<<4) ) >> 4) == 0 )
	{
		LCD_vNumericSendCmd(0x33);
		LCD_vNumericSendCmd(0x32);
	} else{}
	DIO_vWritePin( LCDonKit.sLCD_ControlPort, EN, 1 );           /*   Disable			    		        				  */
	LCD_vOptionSendCmd( InitInstruction.sFunctionSet );            /*   LCD 8/4 Bit Mode, 2/1 Line Mode and Dot Format 5 x 7/10 */
	LCD_vOptionSendCmd( InitInstruction.sClearMode );              /*   Clear Display                                           */
	LCD_vOptionSendCmd( InitInstruction.sCharacterEntry );         /*   Character entry mode                                    */
	LCD_vOptionSendCmd( InitInstruction.sDisplayAndCursorMode );   /*   Display On, Underline Cursor On and Cursor Blink Off    */
	
		
}


void LCD_vNumericSendCmd( INT8U u8Val )
{
	/* check Whether Your LCD Uses 8_Bit Mode Or 4_Bit Mode  */
	LCD_WriteCmd();
	switch(( (InitInstruction.sFunctionSet) & (1<<4) ) >> 4 )  /*  The number 4 here is the position of 8/4 bit in function set command */
	{
		case 1:
		DIO_vWriteByteOnPort( LCDonKit.sLCD_DataPort, u8Val );
		LCD_vTrigger();
		break;
		/*===========================================*/
		case 0:
		DIO_vWritePortRange( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCD_FirstDataPin+3, 0x00);
		DIO_vWriteNibbleOnPort(LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (u8Val/* & 0xF0)*/>> 4 ) /*upper*/ );
		LCD_vTrigger();
		DIO_vWritePortRange( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCD_FirstDataPin+3, 0x00);
		DIO_vWriteNibbleOnPort(LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (u8Val & 0x0F) /*lower*/ );
		LCD_vTrigger();
		break;
	}
}


void LCD_vDisplayChar( INT8U u8Val )
{
	/* check Whether Your LCD Uses 8_Bit Mode Or 4_Bit Mode  */
	LCD_WriteData();
	switch(( (InitInstruction.sFunctionSet) & (1<<4) ) >> 4 )  /*  The number 4 here is the position of 8/4 bit in function set command */
	{
		case 1:
		DIO_vWriteByteOnPort( LCDonKit.sLCD_DataPort, u8Val );
		LCD_vTrigger();
		break;
		/*=======================================*/
		case 0:
		DIO_vWritePortRange( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCD_FirstDataPin+3, 0x00);
		DIO_vWriteNibbleOnPort(LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (u8Val/* & 0xF0)*/>> 4 )/*upper*/ );
		LCD_vTrigger();
		DIO_vWritePortRange( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCD_FirstDataPin+3, 0x00);
		DIO_vWriteNibbleOnPort(LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (u8Val & 0x0F) /*lower*/ );
		LCD_vTrigger();
		break;
	}
}



void LCD_vOptionSendCmd( eLCDOptions Option )
{
	/* check Whether Your LCD Uses 8_Bit Mode Or 4_Bit Mode  */
	LCD_WriteCmd();
	switch(( (InitInstruction.sFunctionSet) & (1<<4) ) >> 4 )  /*  The number 4 here is the position of 8/4 bit in function set command */
	{     
		case 1: 
		DIO_vWriteByteOnPort( LCDonKit.sLCD_DataPort, Option );	
		LCD_vTrigger();	
		break;
		/*========================================*/
		case 0:
		DIO_vWritePortRange( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCD_FirstDataPin+3, 0x00);
		DIO_vWriteNibbleOnPort(LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (Option/* & 0xF0)*/>> 4 ) /*upper*/ );
		LCD_vTrigger();
		DIO_vWritePortRange( LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, LCDonKit.sLCD_FirstDataPin+3, 0x00);
		DIO_vWriteNibbleOnPort(LCDonKit.sLCD_DataPort, LCDonKit.sLCD_FirstDataPin, (Option & 0x0F) /*Lower*/ );
		LCD_vTrigger();
		break;
	}
}



void LCD_vDisplayIntegerMax10D(INT32U u8Val )
{
	INT8U u8DigitsNum ;
	u8DigitsNum = MyLib_u8CountDigitsNum(u8Val);
	INT8U u8DigitsNumArr[u8DigitsNum+1];
	MyLib_vTrimDigitsNumMax10D( u8Val, &u8DigitsNumArr[1], u8DigitsNum+1 );
	for(  ; u8DigitsNum>0 ; u8DigitsNum--)
	{
		LCD_vDisplayChar( u8DigitsNumArr[u8DigitsNum]+48 );
	}
}



void LCD_vDisplayString( INT8U* String )
{
	INT8U *Pstr ;
	Pstr = String;
	for(  ; *Pstr != '\0' ; Pstr++ )
	{
		LCD_vDisplayChar( *Pstr );
	}	
}


void LCD_GoToXY( INT8U x, INT8U y )
{
	INT8U position= 0, rows= LCD_ROWsNUM, clmuns= LCD_CLUMNsNUM ;
	
/*=========================================================================================*/
	if( rows== 1 )
	{
		if( x <= 7 ){	position= 0x80+x;	}
		else if( x > 7 ){	position= 0xC0- 8+ x;	}
		else{}
	}
	
/*==========================================================================================*/
	else if( (rows== 2 || rows== 4) && (clmuns== 16 || clmuns== 40) )
	{
		if     ( (y== 0 && clmuns== 16) || ((y== 2 || y== 0) && clmuns== 40) ){	position= 0x80+ x;	}
		else if( (y== 1 && clmuns== 16) || ((y== 1 || y== 3) && clmuns== 40) ){	position= 0xC0+ x;	}
		else if( y== 2 && clmuns== 16 )	 {	position= 0x90+ x;	}
		else if( y== 3 && clmuns== 16 )	 {	position= 0xD0+ x;	}
		else{}
	}

/*============================================================================================*/
	else if( (rows== 2 || rows== 4) && clmuns== 20 )
	{
		if     ( y== 0 && x<= 15 )	{	position= 0x80+ x;	}
		else if( y== 0 && x > 15 )	{	position= 0x90- 16+ x;	}
		
		else if( y== 1 && x<= 15 )	{	position= 0xC0+ x;	}
		else if( y== 1 && x > 15 )	{	position= 0xD0- 16+ x;	}
			
		else if( y== 2 && x<= 15 )	{	position= 0x94+ x;	}
		else if( y== 2 && x > 15 )	{	position= 0xA4- 16+ x;	}
		
		else if( y== 3 && x<= 15 )	{	position= 0xD4+ x;	}
		else if( y== 3 && x > 15 )	{	position= 0xE4- 16+ x;	}
		else{}
	}
	else{}
/*===============================================================*/
	LCD_vNumericSendCmd(position);
}