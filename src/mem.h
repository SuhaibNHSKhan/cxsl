#ifndef CXSL_MEM_H
#define CXSL_MEM_H

#include <stdint.h>

#ifdef CXSL_DEC
	#define CXSL__DEC(name) CXSL_DEF(name)
#else
	#define CXSL__DEC(name) cxsl_##name
#endif

#undef cxsl__memcpy
#undef cxsl__memset

#define cxsl__memcpy 	CXSL__DEC(memcpy)
#define cxsl__memset 	CXSL__DEC(memset)

// ----------------------- declarations -------------------------- //

void 	cxsl__memcpy	(void* dest, const void* src, size_t sz);
void 	cxsl__memset	(void* dest, uint8_t b, size_t sz);

#endif

#ifdef CXSL_MEM_IMPLEMENTATION

#undef CXSL_MEM_IMPLEMENTATION

void 	cxsl__memcpy	(	void* 			dest 	, 
							const void* 	src		, 
							size_t 			sz 			) 
{
	uint8_t* d = (uint8_t*) dest;
	uint8_t* s = (uint8_t*) src;

	for (; sz; --sz, ++d, ++s) {
		*d = *s;
	}
}

void 	cxsl__memset	(	void* 			dest 	, 
							uint8_t 		b		, 
							size_t 			sz 			) 
{
	uint8_t* d = (uint8_t*) dest;

	for (; sz; --sz, ++d) {
		*d = b;
	}
}

#endif