

#include "MyLibrary.h"

 INT32U MyLib_U32DecimalToBinary( INT8U u8Val )
{
	INT8U Remender = 0;
	INT32U BitPosition = 1, BinaryVal = 0;
	while( u8Val != 0 )
	{
		Remender = u8Val % 2 ;
		u8Val /= 2 ;
		BinaryVal += Remender*BitPosition ;
		BitPosition *= 10 ;   
	}
	return BinaryVal ;
}


 void MyLib_vTrimDigitsNumMax10D( INT32U u32Value, INT8U DigitsNumArr[], INT8U u8DArrSizeUsed )
{
	INT8U count ;
	for( count=0 ; (u32Value != 0) || count	< u8DArrSizeUsed ;  count++ )
	{
		DigitsNumArr[count] = u32Value % 10;
		u32Value /= 10;
	}
}

 INT16U MyLib_u8PowerBase2( INT8U u8PowerVal )
{
	INT8U i, result=1;
	if( u8PowerVal<=8 && u8PowerVal > 0 )
	{
		for( i=0 ; i<u8PowerVal ; i++ )
		{	result *= 2;	}
	}
	else{}
	return result;
}


INT16U MLb_u8Power( INT8U u8Base, INT8U u8PowerVal )
{
		INT8U i, result=1;
		if( u8PowerVal<=8 && u8PowerVal > 0 )
		{
			for( i=0 ; i<u8PowerVal ; i++ )
			{	result *= u8Base;	}
		}
		else{}
		return result;
}


 INT8U MyLib_u8CountDigitsNum( INT32U u32NumVal )
{
	INT8U count;
	for( count=0 ; u32NumVal != 0 ; count++ )
	{
		u32NumVal /= 10 ;
	}
	return count;
}


 INT8U MyLib_u8CountStringchars( INT8U *PString )
{
	INT8U *Ptr ;
	INT8U count ;
	Ptr = PString ;
	for ( count=0 ; *Ptr != '\0' ; count++, Ptr++ );
	return count;
}


 s16Bit2Departs MyLib_u16sDepart16Bit( INT16U u16Value )// it must get test !!!.
{
	s16Bit2Departs s16Bit2parts ;
	 s16Bit2parts.Lower8Bits = u16Value&0x00ff;
	 s16Bit2parts.Upper8Bits = u16Value>>8;
	return s16Bit2parts;
}
