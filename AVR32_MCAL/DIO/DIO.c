#include "DIO.h"
void DIO_vSetPinDir ( INT8U u8Port, INT8U pin, ePinDir eDir )
{
	switch(u8Port)
	{
			/*======== port A =========*/
			case 'A':
			if( eDir == eOutput )
			SET_BIT(DDRA,pin);
			else if( eDir == eInput)
			CLR_BIT(DDRA,pin);
			break ;
			/*======== port B =========*/
			case 'B':
			if( eDir == eOutput )
			SET_BIT(DDRB,pin);
			else if( eDir == eInput)
			CLR_BIT(DDRB,pin);
			break ;
			/*======== port C =========*/
			case'C':
			if( eDir == eOutput )
			SET_BIT(DDRC,pin);
			else if( eDir == eInput)
			CLR_BIT(DDRC,pin);
			break;
			/*======== port D =========*/
			case'D':
			if( eDir == eOutput )
			SET_BIT(DDRD,pin);
			else if( eDir == eInput)
			CLR_BIT(DDRD,pin);
			break ;

	}
}


void DIO_vWritePin ( INT8U u8Port, INT8U u8PinNum, INT8U u8Val )
{
	switch( u8Port )
	{
		/*======== port A =========*/
		case 'A':
		if( u8Val==1 )
		SET_BIT( PORTA, u8PinNum);
		else if( u8Val==0 ) 
		CLR_BIT( PORTA, u8PinNum);
		break ;
		/*======== port B =========*/
		case 'B':
		if( u8Val==1)
		SET_BIT( PORTB, u8PinNum);
		else if( u8Val==0 )
		CLR_BIT( PORTB, u8PinNum);
		break ;
		/*======== port C =========*/
		case'C':
		if( u8Val==1 )
		SET_BIT( PORTC, u8PinNum);
		else if( u8Val==0 )
		CLR_BIT( PORTC, u8PinNum);
		break ;
		/*======== port D =========*/
		case'D':
		if( u8Val==1 )
		SET_BIT( PORTD, u8PinNum);
		else if( u8Val==0 )
		CLR_BIT( PORTD, u8PinNum);
		break ;
		
		default: break;
	}
			
}


INT8U DIO_u8ReadPin ( INT8U u8Port, INT8U u8PinNum )
{
		uint8_t state=0 ;
		switch( u8Port )
		{
			/*======== port A =========*/
			case 'A':
			READ_BIT(state,PINA,u8PinNum,u8PinNum) ;
			break ;
			/*======== port B =========*/
			case 'B':
			READ_BIT(state,PINB,u8PinNum,u8PinNum) ;
			break ;
			/*======== port C =========*/
			case'C':
			READ_BIT(state,PINC,u8PinNum,u8PinNum) ;
			break;
			/*======== port D =========*/
			case'D':
			READ_BIT(state,PIND,u8PinNum,u8PinNum) ;
			break ;
			default: break;
		}
		return state  ;
}


void DIO_u8TogglePin ( INT8U u8Port, INT8U u8PinNum )
{
		switch( u8Port )
		{
			/*======== port A =========*/
			case 'A':
			TOGGLE_BIT(PORTA,u8PinNum);
			break ;
			/*======== port B =========*/
			case 'B':
			TOGGLE_BIT(PORTB,u8PinNum);
			break ;
					
			/*======== port C =========*/
			case'C':
			TOGGLE_BIT(PORTC,u8PinNum);
			break ;
					
			/*======== port D =========*/
			case'D':
			TOGGLE_BIT(PORTD,u8PinNum);
			break ;
			/*===========*/
			default: break;
		}
}


void DIO_vWriteByteOnPort ( INT8U u8Port, INT8U u8Val )
{
	switch( u8Port )
	{
		/*======== port A =========*/
		case 'A':
		PORTA = u8Val;
		break ;
		/*======== port B =========*/
		case 'B':
		PORTB = u8Val;
		break ;
		/*======== port C =========*/
		case'C':
		PORTC = u8Val;
		break ;			
		/*======== port D =========*/
		case'D':
		PORTD = u8Val;
		break ;
		/*===========*/
		default: break;
		}
}



void DIO_vWriteNibbleOnPort ( INT8U u8Port, INT8U u8FirstPin, INT8U u4Val )
{
	if ( u4Val < 16 && u4Val >= 0 && u8FirstPin < 5 )
	{
		switch( u8Port )
		{
			/*======== port A =========*/
			case 'A':
			PORTA |= ( u4Val << u8FirstPin );
			break ;
			/*======== port B =========*/
			case 'B':
			PORTB |= ( u4Val << u8FirstPin );
			break ;
			/*======== port C =========*/
			case'C':
			PORTC |= ( u4Val << u8FirstPin );
			break ;
			/*======== port D =========*/
			case'D':
			PORTD |= ( u4Val << u8FirstPin );
			break ;
			/*===========*/
			default: break;
			}
	}
	else{ }
}



void DIO_vWriteBitsNumValueOnPort( INT8U u8Port, INT8U u8FirstPin, INT8U BitsNum, INT8U u8Val )
{
	if ( u8Val < MyLib_u8PowerBase2(BitsNum) && u8Val > 0x00 )
	{
	INT8U PinPosition, CompVal= 0x01;
	switch( u8Port )
	{
		/*======== port A =========*/
		case 'A':
		for( PinPosition=0 ; PinPosition < BitsNum ;u8FirstPin++, PinPosition++, CompVal<<=1 )
		{
			if( (u8Val & CompVal)>> PinPosition == 0x01 )
			SET_BIT( PORTA, u8FirstPin);
			else if( (u8Val & CompVal)>> PinPosition == 0x00 )
			CLR_BIT( PORTA, u8FirstPin);
		}
		break ;
		/*======== port B =========*/
		case 'B':
		for( PinPosition=0 ; PinPosition < BitsNum ;u8FirstPin++, PinPosition++, CompVal<<=1 )
		{
			if( (u8Val & CompVal)>> PinPosition == 0x01 )
			SET_BIT( PORTB, u8FirstPin);
			else if( (u8Val & CompVal)>> PinPosition == 0x00 )
			CLR_BIT( PORTB, u8FirstPin);
		}
		break ;
		/*======== port C =========*/
		case'C':
		for( PinPosition=0 ; PinPosition < BitsNum ;u8FirstPin++, PinPosition++, CompVal<<=1 )
		{
			if( (u8Val & CompVal)>> PinPosition == 0x01 )
			SET_BIT( PORTC, u8FirstPin);
			else if( (u8Val & CompVal)>> PinPosition == 0x00 )
			CLR_BIT( PORTC, u8FirstPin);
		}
		break ;
		/*======== port D =========*/
		case'D':
		for( PinPosition=0 ; PinPosition < BitsNum ;u8FirstPin++, PinPosition++, CompVal<<=1 )
		{
			if( (u8Val & CompVal)>> PinPosition == 0x01 )
			SET_BIT( PORTD, u8FirstPin);
			else if( (u8Val & CompVal)>> PinPosition == 0x00 )
			CLR_BIT( PORTD, u8FirstPin);
		}
		break ;
		
		default: break;
	}/*end switch*/
	} /*end if*/
	else{}
}


void DIO_vSetPortRangeDir ( INT8U u8Port, INT8U FirstPin, INT8U LastPin, ePinDir eDir )
{
		/*====== end must be greater than start ======*/
		if( FirstPin > LastPin )
		{
			FirstPin = FirstPin + LastPin ;  /*swapping*/
			LastPin = FirstPin - LastPin ;
			FirstPin = FirstPin - LastPin ;
		}
			switch ( u8Port )
			{
				/*======== port A =========*/
				case 'A' :
				if( eDir == eOutput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				SET_BIT(DDRA,FirstPin) ;
				else if( eDir == eInput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(DDRA,FirstPin) ;
				break ;


				/*======== port B ===========*/
				case 'B' :
				if( eDir == eOutput )
				for(  ; FirstPin< LastPin+1 ; FirstPin++ )
				SET_BIT(DDRB,FirstPin) ;
				else if( eDir == eInput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(DDRB,FirstPin);
				break ;

				/*========= port C ==========*/
				case 'C' :
				if( eDir == eOutput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				SET_BIT(DDRC,FirstPin) ;
				else if( eDir == eInput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(DDRC,FirstPin) ;
				break ;

				/*========= port D ===========*/
				case 'D' :
				if( eDir == eOutput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				SET_BIT(DDRD,FirstPin) ;
				else if( eDir == eInput )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(DDRD,FirstPin) ;
				break ;


				default: break;
			}
}

void DIO_vWritePortRange ( INT8U u8Port, INT8U FirstPin, INT8U LastPin, INT8U u8Val )
{
			/*====== end must be greater than start ======*/
			if( FirstPin > LastPin )
			{
				FirstPin = FirstPin + LastPin ;  /*swapping*/
				LastPin = FirstPin - LastPin ;
				FirstPin = FirstPin - LastPin ;
			}
			switch ( u8Port )
			{
				/*======== port A =========*/
				case 'A' :
				if( u8Val == 1 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				SET_BIT(PORTA,FirstPin) ;
				else if( u8Val == 0 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(PORTA,FirstPin) ;
				break ;


				/*======== port B ===========*/
				case 'B' :
				if( u8Val == 1 )
				for(  ; FirstPin< LastPin+1 ; FirstPin++ )
				SET_BIT(PORTB,FirstPin) ;
				else if( u8Val == 0 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(PORTB,FirstPin) ;
				break ;

				/*========= port C ==========*/
				case 'C' :
				if( u8Val == 1 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				SET_BIT(PORTC,FirstPin) ;
				else if( u8Val == 0 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(PORTC,FirstPin) ;
				break ;

				/*========= port D ===========*/
				case 'D' :
				if( u8Val == 1 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				SET_BIT(PORTD,FirstPin) ;
				else if( u8Val == 0 )
				for(  ; FirstPin < LastPin+1 ; FirstPin++ )
				CLR_BIT(PORTD,FirstPin) ;
				break ;


				default: break;
			}
}


INT8U DIO_u8ReadPortRange ( INT8U u8Port, INT8U FirstPin, INT8U LastPin )
{
		INT8U u8Val = 0 ;
		/*====== end must be greater than start ======*/
		if( FirstPin > LastPin )
		{
			FirstPin = FirstPin + LastPin ;  /*swapping*/
			LastPin = FirstPin - LastPin ;
			FirstPin = FirstPin - LastPin ;
		}
		switch ( u8Port )
		{
			/*======== port A =========*/
			case 'A' :
			for(  ; FirstPin < LastPin+1 ; FirstPin++ )
			READ_BIT_NoSHFIT(u8Val,PINA,FirstPin) ;
			break ;

			/*======== port B ===========*/
			case 'B' :
			for(  ; FirstPin < LastPin+1 ; FirstPin++ )
			READ_BIT_NoSHFIT(u8Val,PINB,FirstPin) ;
			break ;

			/*========= port C ==========*/
			case 'C' :
			for(  ; FirstPin < LastPin+1 ; FirstPin++ )
			READ_BIT_NoSHFIT(u8Val,PINC,FirstPin);
			break ;
			/*========= port D ===========*/
			case 'D' :
			for(  ; FirstPin < LastPin+1 ; FirstPin++ )
			READ_BIT_NoSHFIT(u8Val,PIND,FirstPin) ;
			break ;


			default: break;
		}
		return u8Val ;
}




void DIO_vSetMultiPinDironPort( INT8U u8Port, INT8U BinaryDirSet, INT8U _1Select_0Neglect )
{
INT8U PinPosition, CompareVal= 0x01;
switch(u8Port)	{
	case 'A':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
		if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 1 )
		{	SET_BIT(DDRA,PinPosition);	}
					
		else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 0 )
		{	CLR_BIT(DDRA,PinPosition);	}
					
		else{}
				
	}	break;
			
	case 'B':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(DDRB,PinPosition);	}
			
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(DDRB,PinPosition);	}
				
	else{}
				
	}	break;
	case 'C':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(DDRC,PinPosition);	}
				
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(DDRC,PinPosition);	}
				
	else{}
				
	}	break;
	case 'D':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(DDRD,PinPosition);	}
				
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryDirSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(DDRD,PinPosition);	}
				
	else{}
				
	}	break;
}
}



void DIO_vWriteMultiPinValonPort( INT8U u8Port, INT8U BinaryValSet, INT8U _1Select_0Neglect )
{
INT8U PinPosition, CompareVal= 0x00;
switch(u8Port)	{
	case 'A':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(PORTA,PinPosition);	}
			
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(PORTA,PinPosition);	}
			
	else{}
			
	}	break;
		
	case 'B':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(PORTB,PinPosition);	}
			
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(PORTB,PinPosition);	}
			
	else{}
			
	}	break;
	case 'C':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(PORTC,PinPosition);	}
			
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(PORTC,PinPosition);	}
			
	else{}
			
	}	break;
	case 'D':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 1 )
	{	SET_BIT(PORTD,PinPosition);	}
			
	else if( ((_1Select_0Neglect & CompareVal) >> PinPosition) == 1 && ((BinaryValSet & CompareVal) >> PinPosition) == 0 )
	{	CLR_BIT(PORTD,PinPosition);	}
			
	else{}
			
	}	break;
}
}


void DIO_vToggleMultiPinValonPort( INT8U u8Port, INT8U BinToggleSet )
{
INT8U PinPosition, CompareVal= 0x01;
switch(u8Port)
{
case 'A':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((BinToggleSet & CompareVal) >> PinPosition) == 1 )
	{	TOGGLE_BIT(PORTA,PinPosition);	}
				
	else{}
				
	}	break;
case 'B':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((BinToggleSet & CompareVal) >> PinPosition) == 1 )
	{	TOGGLE_BIT(PORTB,PinPosition);	}
				
	else{}
				
	}	break;
case 'C':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((BinToggleSet & CompareVal) >> PinPosition) == 1 )
	{	TOGGLE_BIT(PORTC,PinPosition);	}
				
	else{}
				
	}	break;
case 'D':
	for( PinPosition= 0 ; PinPosition< 8 ; PinPosition++, CompareVal<<= 1 )
	{
	if( ((BinToggleSet & CompareVal) >> PinPosition) == 1 )
	{	TOGGLE_BIT(PORTD,PinPosition);	}
				
	else{}
				
	}	break;
}
}