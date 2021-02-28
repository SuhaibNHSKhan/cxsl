#ifndef PSTRB_H
#define PSTRB_H

#include <stdint.h>
#include "buff.h"
#include "str.h"

#ifndef PSTRB_DEC
	#define PSTRB_DEC(name) pstrb_##name
#endif // PSTRB_DEC

#define PSTRB_TYPE(name) PSTRB_DEC(name)##_t

// undefine 
#undef pstrb__new
#undef pstrb__ofsize
#undef pstrb__ofcap
#undef pstrb__delete
#undef pstrb__concat_cstr
#undef pstrb__concat

#undef pstrb__len
#undef pstrb__cap
#undef pstrb__begin
#undef pstrb__end
#undef pstrb__endp1
#undef pstrb__tostr

#undef pstrb__t
#undef pstrb__header_t


// definitions
#define pstrb__new			PSTRB_DEC(new)
#define pstrb__ofsize		PSTRB_DEC(ofsize)
#define pstrb__ofcap 		PSTRB_DEC(ofcap)
#define pstrb__delete		PSTRB_DEC(delete)

#define pstrb__concat_cstr 	PSTRB_DEC(concat_cstr)
#define pstrb__concat 		PSTRB_DEC(concat)

#define pstrb__len 			PSTRB_DEC(len)
#define pstrb__cap 			PSTRB_DEC(cap)
#define pstrb__begin 		PSTRB_DEC(begin)
#define pstrb__end 			PSTRB_DEC(end)
#define pstrb__endp1 		PSTRB_DEC(endp1)
#define pstrb__tostr 		PSTRB_DEC(tostr)

#define pstrb__t 			PSTRB_DEC(t)
#define pstrb__header_t		PSTRB_TYPE(header)
	

char*           pstrb__new			(const char* str, void* user);
char*           pstrb__ofsize		(size_t sz, void* user);
char*           pstrb__ofcap 		(size_t cap, void* user);
void			pstrb__delete 		(char* str, void* user);

char*           pstrb__concat_cstr	(char* str, const char* cstr, void* user);
char*           pstrb__concat 		(char* str, const char* src_st, const char* src_edp1, void* user);

size_t          pstrb__len 			(char* str);
size_t          pstrb__cap 			(char* str);
char*           pstrb__begin 		(char* str);
char*           pstrb__end 			(char* str);
char*           pstrb__endp1 		(char* str);
char*           pstrb__tostr 		(char* str);


#endif // PSTRB_H

#ifdef PSTRB_IMPLEMENTATION

#undef pstrb__malloc
#undef pstrb__realloc
#undef pstrb__free

#if defined(PSTRB_MALLOC) || defined(PSTRB_REALLOC) || defined(PSTRB_FREE)
	#if defined(PSTRB_MALLOC) && defined(PSTRB_REALLOC) && defined(PSTRB_FREE)
		#define pstrb__malloc(sz, user) PSTRB_MALLOC(sz, user)
		#define pstrb__realloc(ptr, sz, user) PSTRB_REALLOC(ptr, sz, user)
		#define pstrb__free(ptr, user) PSTRB_FREE(ptr, user)
	#else
		#error If any one of PSTRB_MALLOC, PSTRB_REALLOC, PSTRB_FREE is defined, then all of them must be defined
	#endif

#elif defined(GPUL_MALLOC) || defined(GPUL_REALLOC) || defined(GPUL_FREE)
	#if defined(GPUL_MALLOC) && defined(GPUL_REALLOC) && defined(GPUL_FREE)
		#define pstrb__malloc(sz, user) GPUL_MALLOC(sz, user)
		#define pstrb__realloc(ptr, sz, user) GPUL_REALLOC(ptr, sz, user)
		#define pstrb__free(ptr, user) GPUL_FREE(ptr, user)
	#else
		#error If any one of GPUL_MALLOC, GPUL_REALLOC, GPUL_FREE is defined, then all of them must be defined
	#endif
#else
	#include <malloc.h>

	#define pstrb__malloc(sz, user) malloc(sz)
	#define pstrb__realloc(ptr, sz, user) realloc(ptr, sz)
	#define pstrb__free(ptr, user) free(ptr)
#endif

// ----------------------- types -------------------------- //

typedef struct pstrb__header_t {
	size_t cap;
	size_t sz;

} pstrb__header_t;

typedef struct pstrb__t {
	pstrb__header_t header;
	char buff[1];

} pstrb__t;

// ----------------------- init and free -------------------------- // 

char* pstrb__new 	(	const char*      str    , 
						void*            user		)							 
{
	size_t sz, cap;
	pstrb__t* pstrb;
	char* out;

	sz = gpul_strlen(str);
	cap = sz * 2 + 1;

	pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);

	pstrb->header.cap = cap;
	pstrb->header.sz = sz;

	out = &pstrb->buff[0];

	gpul_memcpy((void*) out, (void*) str, sz);

	out[sz] = 0;

	return out;
}

char* pstrb__ofsize    (		size_t			sz 		, 
								void*			user		)
{
	size_t cap;
	pstrb__t* pstrb;
	char* out;

	cap = sz * 2 + 1;

	pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);

	pstrb->header.cap = cap;
	pstrb->header.sz = sz;

	out = &pstrb->buff[0];

	out[sz] = 0;

	return out;	
}

char* pstrb__ofcap		(	size_t			cap 	, 
							void*			user		) 
{
	size_t sz = 0;
	pstrb__t* pstrb;
	char* out;

	pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);

	pstrb->header.cap = cap;
	pstrb->header.sz = sz;

	out = &pstrb->buff[0];

	out[sz] = 0;

	return out;	
}

void pstrb__delete	(	char*		str 	, 
						void* 		user		) 
{
	pstrb__free((void*) (str - sizeof(pstrb__header_t)), user);
}

// ----------------------- functional -------------------------- // 

char* pstrb__concat_cstr 	(	char*			str 		, 
								const char* 	cstr 		, 
								void* 			user			) 
{
	size_t remain, i, len, cap;
	pstrb__t* pstrb;


	pstrb = str - sizeof(pstrb__header_t);	
	len = pstrb__len(str);
	remain = pstrb__cap(str) - len;

	for (i = len; *cstr != 0 && remain > 0; ++cstr, --remain, ++i) {
		str[i] = *cstr;
	}

	if (remain == 0 && *cstr != 0) {
		cap = pstrb__cap(str);
		len = gpul_strlen(cstr) + cap;

		while (cap < len) {
			cap = 2 * cap + 1;
		}

		pstrb = pstrb__realloc(pstrb, cap + 1, user);
		pstrb->header.cap = cap;

		str = &pstrb->buff[0];

		for (; *cstr != 0; ++cstr, ++i) {
			str[i] = *cstr;
		}
	}

	pstrb->header.sz = i;
	str[i] = 0;	

	return str;
}

char* pstrb__concat 	(	char*		 	str 		, 
							const char* 	src_st 		, 
							const char* 	src_edp1	, 
							void* user						) 
{
	size_t i, cap, len, remain;
	const char* curr;
	pstrb__t* pstrb;

	len = pstrb__len(str);
	remain = pstrb__cap(str) - len;

	pstrb = (pstrb__t*) (str - sizeof(pstrb__header_t));

	for (i = len, curr = src_st; curr != src_edp1 && remain > 0; ++curr, --remain, ++i) {
		str[i] = *curr;
	}


	if (remain == 0 && curr != src_edp1) {
		cap = pstrb__cap(str);
		len = (size_t) ((uintptr_t) src_edp1 - (uintptr_t) src_st) + cap;

		while (cap < len) {
			cap = 2 * cap + 1;
		}	

		pstrb = pstrb__realloc(pstrb, cap + 1, user);
		pstrb->header.cap = cap;

		str = &pstrb->buff[0];

		for (; curr != src_edp1; ++curr, ++i) {
			str[i] = *curr;
		}
	}

	pstrb->header.sz = i;
	str[i] = 0;	

	return str;
}

// ----------------------- data access -------------------------- // 

size_t pstrb__len	(	char* str 	) 
{
	pstrb__header_t* pstrbh = (pstrb__header_t*) (str - sizeof(pstrb__header_t));

	return pstrbh->sz;
}

size_t pstrb__cap 	(	char* str 	) 
{
	pstrb__header_t* pstrbh = (pstrb__header_t*) (str - sizeof(pstrb__header_t));

	return pstrbh->cap;
}

char* pstrb__begin 	(	char* str 	) 
{
	return str;
}

char* pstrb__end 	(	char* str 	) 
{
	return str + pstrb__len(str) - 1;
}

char* pstrb__endp1 	(	char* str 	) 
{
	return str + pstrb__len(str);
}

char* pstrb__tostr (	char* str 	) 
{
	return str;
}

#undef PSTRB_IMPLEMENTATION
#endif // PSTRB_IMPLEMENTATION