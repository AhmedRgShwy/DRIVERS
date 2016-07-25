#include "KEYPAD.h"

INT8U Keypad_u8Scan( void )
{
	/* creating byte for rows, byte for columns, byte for button value and a byte for keypad value which will be 255 if no button value */
	INT8U row, column, u8KPdVal=0xff ;
	INT8U *u8ValSet;
	/* creating a byte which has ones beside others, their number = columns number and have their same positions */
	INT8U u8ReadCmpVal = (MyLib_u8PowerBase2(COLUMNs_NUM)-1) << Keypad.u8FirstClumnPin;
	/* set rows pins as output */
	DIO_vSetPortRangeDir( Keypad.u8RowsPort, Keypad.u8FirsRowPin, Keypad.u8FirsRowPin+ROWs_NUM-1, eOutput );
	/* set columns pins as inputs */
	DIO_vSetPortRangeDir( Keypad.u8ClumnsPort, Keypad.u8FirstClumnPin, Keypad.u8FirstClumnPin+COLUMNs_NUM-1, eInput );
	/* set pull up resistors for input columns pins */
	CLR_BIT(SFIOR,PUD);
	DIO_vWritePortRange( Keypad.u8ClumnsPort, Keypad.u8FirstClumnPin, Keypad.u8FirstClumnPin+COLUMNs_NUM-1, 1 );
	
	/* two loops to check which button is pressed on the keypad and generates value for each button */
	for( u8ValSet=&kpdContents[0], row=Keypad.u8FirsRowPin ; row < Keypad.u8FirsRowPin+ROWs_NUM ; row++ )
	{
		/* shutdown the rows pins as inputs to defeat conflicting 2 pins with opposite voltages(0&1) causing by 
		pressing 2 columns buttons at the same time */
		DIO_vSetPortRangeDir( Keypad.u8RowsPort, Keypad.u8FirsRowPin, Keypad.u8FirsRowPin+ROWs_NUM-1, eInput );
		/* setting the row pin with output which is the ground of all row buttons */
		DIO_vSetPinDir( Keypad.u8RowsPort, row, eOutput );
		/* clear the row pin to be ground of all row buttons*/
		DIO_vWritePin( Keypad.u8RowsPort, row, 0 );
		
		for( column=Keypad.u8FirstClumnPin ; column < Keypad.u8FirstClumnPin+COLUMNs_NUM ; u8ValSet++, column++ )
			{
				/* check the read on the whole columns if it match a value of dedicated button */
				if ( DIO_u8ReadPortRange( Keypad.u8ClumnsPort, Keypad.u8FirstClumnPin, Keypad.u8FirstClumnPin+COLUMNs_NUM-1 )
					==  (u8ReadCmpVal&(~(1<<column))) )
				{	u8KPdVal = *u8ValSet;	} /* set the generating value of the pressed button to the keypad value to return it */
			}
	}
	return u8KPdVal ;
}