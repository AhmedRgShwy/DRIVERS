

#ifndef IIMACROS_H_
#define IIMACROS_H_
#include "IIIMACROS.h"

#define READ_BIT(save,reg,n,x)						acceptor|=((reg&(1<<n))>>n)
#define SET_2VALUE(acceptor,v1,p1,v2,p2)			acceptor|=(v1<<p1)|(v2<<p2)
#define CLR_2VALUE(acceptor,v1,p1,v2,p2)			acceptor&=~((v1<<p1)|(v2<<p2))


#endif /* IIMACROS_H_ */
