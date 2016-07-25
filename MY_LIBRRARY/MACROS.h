

#ifndef MACROS_H_
#define MACROS_H_

typedef  unsigned char  INT8U ;
typedef  unsigned short INT16U;
typedef  unsigned long  INT32U;

#define	SET_BIT(reg,n)							reg|=(1<<n)
#define CLR_BIT(reg,n)							reg&=~(1<<n)
#define TOGGLE_BIT(reg,n)						reg^=(1<<n)
#define READ_BIT(save,reg,n,x)					save|=((reg&(1<<n))>>n)
#define READ_BIT_NoSHFIT(save,reg,n)			save|=(reg&(1<<n))
#define READ_BIT_NoSET(val,reader,shift)		((val&reader)>>shift)

#endif /* MACROS_H_ */
