#ifndef NSTR_H
#define NSTR_H

#include <stdint.h>
#include "def.h"
#include "str.h"
#include "buff.h"

#ifndef NSTR_DEC
	#define NSTR_DEC(name) nstr_##name
#endif

#define NSTR_TYPE(name) NSTR_DEC(name)##_t

#define NSTR_SSO_THRESHOLD 14

// undefine
#undef nstr__empty
#undef nstr__new
#undef nstr__ofsize
#undef nstr__move
#undef nstr__delete

#undef nstr__begin
#undef nstr__end
#undef nstr__endp1
#undef nstr__size
#undef nstr__data
#undef nstr__tostr

#undef nstr__t

// definitions
#define nstr__empty 		NSTR_DEC(empty)
#define nstr__new 			NSTR_DEC(new)
#define nstr__ofsize 		NSTR_DEC(ofsize)
#define nstr__move 			NSTR_DEC(move)
#define nstr__delete 		NSTR_DEC(delete)

#define nstr__begin 		NSTR_DEC(begin)
#define nstr__end 			NSTR_DEC(end)
#define nstr__endp1 		NSTR_DEC(endp1)
#define nstr__size 			NSTR_DEC(size)
#define nstr__data 			NSTR_DEC(data)
#define nstr__tostr 		NSTR_DEC(tostr)

#define nstr__t 			NSTR_DEC(t)

// ----------------------- types -------------------------- //

typedef struct nstr__t {

	union {
		struct {
			const char* data;
			size_t sz;	
		} lg;

		struct {
			char data[sizeof(size_t) * 2 - 1];
			uint8_t sz;
		} sm;

		struct {
			size_t buff[2];
		} bsz;
	};
	
} nstr__t;

// ----------------------- definitions -------------------------- //

nstr__t 		nstr__empty 	();
nstr__t 		nstr__new 		(const char* str, void* user);
nstr__t 		nstr__ofsize 	(size_t sz, void* user);
nstr__t 		nstr__move 		(const char* str);
void 			nstr__delete 	(nstr__t* nstr, void* user);

const char* 	nstr__begin 	(nstr__t* nstr);
const char* 	nstr__end 		(nstr__t* nstr);
const char* 	nstr__endp1		(nstr__t* nstr);
size_t 			nstr__size 		(nstr__t* nstr);
const char* 	nstr__data 		(nstr__t* nstr);
const char* 	nstr__tostr 	(nstr__t* nstr);


#endif // NSTR_H

#ifdef NSTR_IMPLEMENTATION

#undef nstr__malloc
#undef nstr__realloc
#undef nstr__free

#if defined(NSTR_MALLOC) || defined(NSTR_REALLOC) || defined(NSTR_FREE)
	#if defined(NSTR_MALLOC) && defined(NSTR_REALLOC) && defined(NSTR_FREE)
		#define nstr__malloc(sz, user) NSTR_MALLOC(sz, user)
		#define nstr__realloc(ptr, sz, user) NSTR_REALLOC(ptr, sz, user)
		#define nstr__free(ptr, user) NSTR_FREE(ptr, user)
	#else
		#error If any one of NSTR_MALLOC, NSTR_REALLOC, NSTR_FREE is defined, then all of them must be defined
	#endif

#elif defined(GPUL_MALLOC) || defined(GPUL_REALLOC) || defined(GPUL_FREE)
	#if defined(GPUL_MALLOC) && defined(GPUL_REALLOC) && defined(GPUL_FREE)
		#define nstr__malloc(sz, user) GPUL_MALLOC(sz, user)
		#define nstr__realloc(ptr, sz, user) GPUL_REALLOC(ptr, sz, user)
		#define nstr__free(ptr, user) GPUL_FREE(ptr, user)
	#else
		#error If any one of GPUL_MALLOC, GPUL_REALLOC, GPUL_FREE is defined, then all of them must be defined
	#endif
#else
	#include <malloc.h>

	#define nstr__malloc(sz, user) malloc(sz)
	#define nstr__realloc(ptr, sz, user) realloc(ptr, sz)
	#define nstr__free(ptr, user) free(ptr)
#endif

// ----------------------- init and free -------------------------- // 

nstr__t 		nstr__empty 	() 
{
	return nstr__new("", NULL);
}

nstr__t 		nstr__new 		(	const char* 	str 	, 
									void* 			user		) 
{
	size_t sz = gpul_strlen(str);
	nstr__t nstr;

	if (sz > NSTR_SSO_THRESHOLD) {
		nstr.lg.sz = sz | GPUL_SIZE_T_HIGH_BIT_MASK;
		nstr.lg.data = nstr__malloc(sz + 1, user);

		gpul_memcpy((void*) nstr.lg.data, str, sz + 1);

	} else {
		nstr.sm.sz = (uint8_t) sz;
		gpul_memcpy(&nstr.sm.data[0], str, sz + 1);
	}

	return nstr;
}

nstr__t 		nstr__ofsize 	(	size_t 			sz 		, 
									void* 			user		)
{
	nstr__t nstr;
	char* data;

	if (sz > NSTR_SSO_THRESHOLD) {
		nstr.lg.sz = sz | GPUL_SIZE_T_HIGH_BIT_MASK;
		nstr.lg.data = nstr__malloc(sz + 1, user);

		data = (char*) &nstr.lg.data[0];

		data[sz] = 0;

	} else {
		nstr.sm.sz = (uint8_t) sz;
		
		nstr.sm.data[sz] = 0;
	}

	return nstr;
}

nstr__t 		nstr__move 		(	const char* str 	)
{
	nstr__t nstr;
	
	nstr.lg.sz = gpul_strlen(str) | GPUL_SIZE_T_HIGH_BIT_MASK;
	nstr.lg.data = str;

	return nstr;
}

void 			nstr__delete 	(	nstr__t* 	nstr 	,
									void*		user 		)
{
	if (nstr->bsz.buff[1] & GPUL_SIZE_T_HIGH_BIT_MASK) {
		nstr__free((void*) nstr->lg.data, user);
	}
}

// ----------------------- data access -------------------------- // 

const char* 	nstr__begin 	(	nstr__t* nstr 	) 
{
	if (nstr->bsz.buff[1] & GPUL_SIZE_T_HIGH_BIT_MASK) {
		return nstr->lg.data;
	}
	else {
		return &nstr->sm.data[0];
	}
}

const char* 	nstr__end 		(	nstr__t* nstr 	) 
{
	return nstr__begin(nstr) + nstr__size(nstr) - 1;
}

const char* 	nstr__endp1		( 	nstr__t* nstr 	) 
{
	return nstr__begin(nstr) + nstr__size(nstr);
}

size_t 			nstr__size 		( 	nstr__t* nstr 	) 
{
	if (nstr->bsz.buff[1] & GPUL_SIZE_T_HIGH_BIT_MASK) {
		return nstr->lg.sz & ~GPUL_SIZE_T_HIGH_BIT_MASK;
	}
	else {
		return (size_t) nstr->sm.sz;
	}
}

const char* 	nstr__data 		(	nstr__t* nstr 	)
{
	return nstr__begin(nstr);
}

const char* 	nstr__tostr 	( 	nstr__t* nstr 	)
{
	return nstr__begin(nstr);
}

#endif // NSTR_H