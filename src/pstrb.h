#ifndef CXSL_PSTRB_H
#define CXSL_PSTRB_H

#include <stdint.h>

#undef PSTRB__DEC
#undef PSTRB__TYPE

#ifdef CXSL_PSTRB_DEC
	#define PSTRB__DEC(name) CXSL_PSTRB_DEC(name)
#else
	#define PSTRB__DEC(name) pstrb_##name
#endif // PSTRB_DEC

#define PSTRB__TYPE(name) PSTRB__DEC(name)##_t

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
#define pstrb__new			PSTRB__DEC(new)
#define pstrb__ofsize		PSTRB__DEC(ofsize)
#define pstrb__ofcap 		PSTRB__DEC(ofcap)
#define pstrb__delete		PSTRB__DEC(delete)

#define pstrb__concat_cstr 	PSTRB__DEC(concat_cstr)
#define pstrb__concat 		PSTRB__DEC(concat)

#define pstrb__len 			PSTRB__DEC(len)
#define pstrb__cap 			PSTRB__DEC(cap)
#define pstrb__begin 		PSTRB__DEC(begin)
#define pstrb__end 			PSTRB__DEC(end)
#define pstrb__endp1 		PSTRB__DEC(endp1)
#define pstrb__tostr 		PSTRB__DEC(tostr)

#define pstrb__t 			PSTRB__DEC(t)
#define pstrb__header_t		PSTRB__TYPE(header)
	
// ----------------------- declarations -------------------------- //

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


#endif // CXSL_PSTRB_H

#ifdef CXSL_PSTRB_IMPLEMENTATION

#undef CXSL_PSTRB_IMPLEMENTATION

#undef pstrb__malloc
#undef pstrb__realloc
#undef pstrb__free
#undef pstrb__strlen
#undef pstrb__memcpy
#undef pstrb__null_string

#define pstrb__null_string PSTRB__DEC(internal__null_string)

#if defined(CXSL_PSTRB_MALLOC) || defined(CXSL_PSTRB_REALLOC) || defined(CXSL_PSTRB_FREE)
	#if defined(CXSL_PSTRB_MALLOC) && defined(CXSL_PSTRB_REALLOC) && defined(CXSL_PSTRB_FREE)
		#define pstrb__malloc(sz, user) CXSL_PSTRB_MALLOC(sz, user)
		#define pstrb__realloc(ptr, sz, user) CXSL_PSTRB_REALLOC(ptr, sz, user)
		#define pstrb__free(ptr, user) CXSL_PSTRB_FREE(ptr, user)
	#else
		#error If any one of CXSL_PSTRB_MALLOC, CXSL_PSTRB_REALLOC, CXSL_PSTRB_FREE is defined, then all of them must be defined
	#endif

#elif defined(CXSL_MALLOC) || defined(CXSL_REALLOC) || defined(CXSL_FREE)
	#if defined(CXSL_MALLOC) && defined(CXSL_REALLOC) && defined(CXSL_FREE)
		#define pstrb__malloc(sz, user) CXSL_MALLOC(sz, user)
		#define pstrb__realloc(ptr, sz, user) CXSL_REALLOC(ptr, sz, user)
		#define pstrb__free(ptr, user) CXSL_FREE(ptr, user)
	#else
		#error If any one of CXSL_MALLOC, CXSL_REALLOC, CXSL_FREE is defined, then all of them must be defined
	#endif
#else
	#include <malloc.h>

	#define pstrb__malloc(sz, user) malloc(sz)
	#define pstrb__realloc(ptr, sz, user) realloc(ptr, sz)
	#define pstrb__free(ptr, user) free(ptr)
#endif

#if defined(CXSL_PSTRB_STRLEN)
	#define pstrb__strlen(str) CXSL_PSTRB_STRLEN(str)
#elif defined(CXSL_STRLEN)
	#define pstrb__strlen(str) CXSL_STRLEN(str)
#else
	#include <string.h>
	#define pstrb__strlen(str) strlen(str)
#endif

#if defined(CXSL_PSTRB_MEMCPY)
	#define pstrb__memcpy(dest, src, sz) CXSL_PSTRB_MEMCPY(dest, src, sz)
#elif defined(CXSL_MEMCPY)
	#define pstrb__memcpy(dest, src, sz) CXSL_MEMCPY(dest, src, sz)
#else
	#include <string.h>
	#define pstrb__memcpy(dest, src, sz) memcpy(dest, src, sz)
#endif

#if defined(CXSL_ASSERT)
	#define pstrb__assert(check, format, ...) CXSL_ASSERT(check, message, __VA_ARGS__)
#else
	#include <assert.h>
	#define pstrb__assert(check, message, ...) assert(check)
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

const uint8_t pstrb__null_string[32] = {	0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0	};

// ----------------------- init and free -------------------------- // 

char*           pstrb__new			(	const char*      str    , 
										void*            user		)							 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	size_t sz, cap;
	pstrb__t* pstrb;
	char* out;

	sz = pstrb__strlen(str);

	if (sz == 0) {
		pstrb = (pstrb__t*) &pstrb__null_string[0];

		out = &pstrb->buff[0];

	} else {
		cap = sz * 2 + 1;

		pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);

		pstrb__assert(pstrb != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

		pstrb->header.cap = cap;
		pstrb->header.sz = sz;

		out = &pstrb->buff[0];

		pstrb__memcpy((void*) out, (void*) str, sz + 1);
	}

	return out;
}

char*           pstrb__ofsize		(		size_t			sz 		, 
											void*			user		)
{
	size_t cap;
	pstrb__t* pstrb;
	char* out;

	if (sz == 0) {
		pstrb = (pstrb__t*) &pstrb__null_string[0];

		out = &pstrb->buff[0];

	} else {
		cap = sz * 2 + 1;

		pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);

		pstrb__assert(pstrb != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

		pstrb->header.cap = cap;
		pstrb->header.sz = sz;

		out = &pstrb->buff[0];

		out[sz] = 0;
	}

	return out;	
}

char*           pstrb__ofcap 		(	size_t			cap 	, 
										void*			user		) 
{
	pstrb__assert(cap > 0, "Parameter cap has to be greater than 0");

	size_t sz = 0;
	pstrb__t* pstrb;
	char* out;

	pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);

	pstrb__assert(pstrb != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

	pstrb->header.cap = cap;
	pstrb->header.sz = sz;

	out = &pstrb->buff[0];

	out[sz] = 0;

	return out;	
}

void			pstrb__delete 		(	char*		str 	, 
										void* 		user		) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	pstrb__t* pstrb = (pstrb_t*) (str - sizeof(pstrb__header_t));
	pstrb__t* null_string = (pstrb_t*) &pstrb__null_string[0];

	if (pstrb != null_string) {
		pstrb__free((void*) (pstrb), user);	
	}
}

// ----------------------- functional -------------------------- // 

char*           pstrb__concat_cstr	(	char*			str 		, 
										const char* 	cstr 		, 
										void* 			user			) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");
	pstrb__assert(cstr != NULL, "Parameter cstr cannot be NULL");

	size_t remain, i, len, cap;
	pstrb__t *pstrb, *null_string;


	pstrb = str - sizeof(pstrb__header_t);	
	len = pstrb__len(str);
	remain = pstrb__cap(str) - len;

	for (i = len; *cstr != 0 && remain > 0; ++cstr, --remain, ++i) {
		str[i] = *cstr;
	}

	if (remain == 0 && *cstr != 0) {
		cap = pstrb__cap(str);
		len = pstrb__strlen(cstr) + cap;
		null_string = (pstrb_t*) &pstrb__null_string[0];

		while (cap < len) {
			cap = 2 * cap + 1;
		}

		if (pstrb == null_string) {
			pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);
		} else {
			pstrb = pstrb__realloc(pstrb, sizeof(pstrb__header_t) + cap + 1, user);	
		}

		pstrb__assert(pstrb != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

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

char*           pstrb__concat 		(	char*		 	str 		, 
										const char* 	src_st 		, 
										const char* 	src_edp1	, 
										void* user						) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");
	pstrb__assert(src_st != NULL, "Parameter src_st cannot be NULL");
	pstrb__assert(src_edp1 != NULL, "Parameter src_edp1 cannot be NULL");

	size_t i, cap, len, remain;
	const char* curr;
	pstrb__t *pstrb, *null_string;

	len = pstrb__len(str);
	remain = pstrb__cap(str) - len;

	pstrb = (pstrb__t*) (str - sizeof(pstrb__header_t));

	for (i = len, curr = src_st; curr != src_edp1 && remain > 0; ++curr, --remain, ++i) {
		str[i] = *curr;
	}


	if (remain == 0 && curr != src_edp1) {
		cap = pstrb__cap(str);
		len = (size_t) ((uintptr_t) src_edp1 - (uintptr_t) src_st) + cap;
		null_string = (pstrb_t*) &pstrb__null_string[0];

		while (cap < len) {
			cap = 2 * cap + 1;
		}	

		if (pstrb == null_string) {
			pstrb = pstrb__malloc(sizeof(pstrb__header_t) + cap + 1, user);
		} else {
			pstrb = pstrb__realloc(pstrb, sizeof(pstrb__header_t) + cap + 1, user);	
		}

		pstrb__assert(pstrb != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

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

size_t          pstrb__len 			(	char* str 	) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	pstrb__header_t* pstrbh;

	pstrbh = (pstrb__header_t*) (str - sizeof(pstrb__header_t));

	return pstrbh->sz;
}

size_t          pstrb__cap 			(	char* str 	) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	pstrb__header_t* pstrbh;

	pstrbh = (pstrb__header_t*) (str - sizeof(pstrb__header_t));

	return pstrbh->cap;
}

char*           pstrb__begin 		(	char* str 	) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	return str;
}

char*           pstrb__end 			(	char* str 	) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	return str + pstrb__len(str) - 1;
}

char*           pstrb__endp1 		(	char* str 	) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");

	return str + pstrb__len(str);
}

char*           pstrb__tostr 		(	char* str 	) 
{
	pstrb__assert(str != NULL, "Parameter str cannot be NULL");
	
	return str;
}

#endif // PSTRB_IMPLEMENTATION