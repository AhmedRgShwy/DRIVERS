

#ifndef IIIMACROS_H_
#define IIIMACROS_H_


#define SET_3VALUE(acceptor,v1,p1,v2,p2,v3,p3)		acceptor|=(v1<<p1)|(v2<<p2)|(v3<<p3)
#define CLR_3VALUE(acceptor,v1,p1,v2,p2,v3,p3)		acceptor&=~((v1<<p1)|(v2<<p2)|(v3<<p3))


#endif /* IIIMACROS_H_ */
