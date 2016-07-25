

#ifndef MYLIBRARY_H_
#define MYLIBRARY_H_
#include "MACROS.h"

#define SET_VALUE(acceptor,val,position)	   	acceptor|=(val<<position)
#define SET_4VALUE(acceptorv1,p1,v2,p2,v3,p3,v4,p4)	acceptor|=(v1<<p1)|(v2<<p2)|(v3<<p3)|(v4<<p4)
#define CLR_VALUE(acceptor,v,p)				acceptor&=~(v<<p)
#define CLR_4VALUE(acceptor,v1,p1,v2,p2,v3,p3,v4,p4)	acceptor&=~((v1<<p1)|(v2<<p2)|(v3<<p3)|(v4<<p4))

#define SHIFT_L(val,position)				(val<<position)
#define SHIFT_R(val,position)		             	(val>>position)
#define _READ_VAL_NOKEEP(source,val,position)		 source&(val<<position)



typedef  unsigned char  INT8U ;
typedef  unsigned short INT16U;
typedef  unsigned long  INT32U;
typedef struct{
	INT8U Lower8Bits;
	INT8U Upper8Bits;
} s16Bit2Departs;

INT32U MyLib_U32DecimalToBinary( INT8U u8Val );
void MyLib_vTrimDigitsNumMax10D( INT32U u32Value, INT8U DigitsNumArr[], INT8U u8DArrSize ); 
void MyLib_vTrimAnyNumDigits(INT32U u32ValArr[], INT8U u8SizeArrNumVal, INT8U DigitsNumArr[], INT8U u8DArrSize);/* future design */
INT16U MyLib_u8PowerBase2( INT8U u8PowerVal );
INT16U MLib_u8Power( INT8U u8Base, INT8U u8PowerVal );
INT8U MyLib_u8CountDigitsNum( INT32U u32NumVal );
INT8U MyLib_u8CountStringchars( INT8U *PString );
s16Bit2Departs MyLib_u16sDepart16Bit( INT16U u16Value );



#endif /* MYLIBRARY_H_ */
