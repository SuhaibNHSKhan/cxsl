#ifndef CXSL_NSTRB_H
#define CXSL_NSTRB_H

#include <stdint.h>

#undef NSTRB__TYPE
#undef NSTRB__SSO_THRESHOLD_BASE
#undef NSTRB__SSO_THRESHOLD
#undef NSTRB__DPTR_BIT_MASK
#undef NSTRB__FREE_BIT_MASK
#undef NSTRB__RESERVED_BIT_MASK
#undef NSTRB__DEC
#undef NSTRB__EXTRA_BYTES

#ifdef CXSL_NSTRB_DEC
	#define NSTRB__DEC(name) CXSL_NSTRB_DEC(name)
#else
	#define NSTRB__DEC(name) nstrb_##name
#endif

#ifdef CXSL_NSTRB_EXTRA_BYTES
	#define NSTRB__EXTRA_BYTES CXSL_NSTRB_EXTRA_BYTES
#else
	#define NSTRB__EXTRA_BYTES 0
#endif

#define NSTRB__TYPE(name) NSTRB__DEC(name)##_t

#define NSTRB__SSO_THRESHOLD_BASE 22
#define NSTRB__SSO_THRESHOLD (NSTRB__SSO_THRESHOLD_BASE + NSTRB__EXTRA_BYTES)

#if NSTRB__SSO_THRESHOLD > 64
	#undef NSTRB__SSO_THRESHOLD
	#define NSTRB__SSO_THRESHOLD 64
#endif

#define NSTRB__DPTR_BIT_MASK		(1ULL << (sizeof(size_t) * 8 - 1))
#define NSTRB__FREE_BIT_MASK      	(1ULL << (sizeof(size_t) * 8 - 2))
#define NSTRB__RESERVED_BIT_MASK 	(NSTRB__DPTR_BIT_MASK | NSTRB__FREE_BIT_MASK)


// undefine
#undef nstrb__empty
#undef nstrb__new
#undef nstrb__ofsize
#undef nstrb__move
#undef nstrb__delete

#undef nstrb__begin
#undef nstrb__end
#undef nstrb__endp1
#undef nstrb__size
#undef nstrb__data
#undef nstrb__tostr

#undef nstrb__t

// definitions
#define nstrb__empty 		NSTRB__DEC(empty)
#define nstrb__new 			NSTRB__DEC(new)
#define nstrb__ofsize 		NSTRB__DEC(ofsize)
#define nstrb__move 			NSTRB__DEC(move)
#define nstrb__cmove			NSTRB__DEC(cmove)
#define nstrb__delete 		NSTRB__DEC(delete)

#define nstrb__begin 		NSTRB__DEC(begin)
#define nstrb__end 			NSTRB__DEC(end)
#define nstrb__endp1 		NSTRB__DEC(endp1)
#define nstrb__size 			NSTRB__DEC(size)
#define nstrb__data 			NSTRB__DEC(data)
#define nstrb__tostr 		NSTRB__DEC(tostr)

#define nstrb__t 			NSTRB__DEC(t)

// ----------------------- types -------------------------- //

typedef struct nstrb__t {

	union {
		struct {
			const char* data;
			#if NSTRB__EXTRA_BYTES
				uint8_t extra[NSTRB__EXTRA_BYTES];
			#endif
			size_t cap;
			size_t sz;
		} lg;

		struct {
			char data[sizeof(size_t) * 3 + NSTRB__EXTRA_BYTES - 1];
			uint8_t sz;
		} sm;

		struct {
			size_t prefix[3 + NSTRB__EXTRA_BYTES / sizeof(size_t) - 1];
			size_t suffix;
		} bsz;
	};
	
} nstrb__t;

// ----------------------- declarations -------------------------- //

nstrb__t 		nstrb__empty 	();
nstrb__t 		nstrb__new 		(const char* str, void* user);
nstrb__t 		nstrb__ofsize 	(size_t sz, void* user);
nstrb__t 		nstrb__move 	(const char* str);
nstrb__t 		nstrb__cmove	(const char* str);
void 			nstrb__delete 	(nstrb__t* nstrb, void* user);

const char* 	nstrb__begin 	(nstrb__t* nstrb);
const char* 	nstrb__end 		(nstrb__t* nstrb);
const char* 	nstrb__endp1	(nstrb__t* nstrb);
size_t 			nstrb__size 	(nstrb__t* nstrb);
const char* 	nstrb__data 	(nstrb__t* nstrb);
const char* 	nstrb__tostr 	(nstrb__t* nstrb);


#endif // NSTRB_H

#ifdef CXSL_NSTRB_IMPLEMENTATION

#undef CXSL_NSTRB_IMPLEMENTATION

#undef nstrb__malloc
#undef nstrb__realloc
#undef nstrb__free
#undef nstrb__strlen
#undef nstrb__memcpy

#if defined(CXSL_NSTRB_MALLOC) || defined(CXSL_NSTRB_REALLOC) || defined(CXSL_NSTRB_FREE)
	#if defined(CXSL_NSTRB_MALLOC) && defined(CXSL_NSTRB_REALLOC) && defined(CXSL_NSTRB_FREE)
		#define nstrb__malloc(sz, user) CXSL_NSTRB_MALLOC(sz, user)
		#define nstrb__realloc(ptr, sz, user) CXSL_NSTRB_REALLOC(ptr, sz, user)
		#define nstrb__free(ptr, user) CXSL_NSTRB_FREE(ptr, user)
	#else
		#error If any one of CXSL_NSTRB_MALLOC, CXSL_NSTRB_REALLOC, CXSL_NSTRB_FREE is defined, then all of them must be defined
	#endif

#elif defined(CXSL_MALLOC) || defined(CXSL_REALLOC) || defined(CXSL_FREE)
	#if defined(CXSL_MALLOC) && defined(CXSL_REALLOC) && defined(CXSL_FREE)
		#define nstrb__malloc(sz, user) CXSL_MALLOC(sz, user)
		#define nstrb__realloc(ptr, sz, user) CXSL_REALLOC(ptr, sz, user)
		#define nstrb__free(ptr, user) CXSL_FREE(ptr, user)
	#else
		#error If any one of CXSL_MALLOC, CXSL_REALLOC, CXSL_FREE is defined, then all of them must be defined
	#endif
#else
	#include <malloc.h>

	#define nstrb__malloc(sz, user) malloc(sz)
	#define nstrb__realloc(ptr, sz, user) realloc(ptr, sz)
	#define nstrb__free(ptr, user) free(ptr)
#endif

#if defined(CXSL_NSTRB_STRLEN)
	#define nstrb__strlen(str) CXSL_NSTRB_STRLEN(str)
#elif defined(CXSL_STRLEN)
	#define nstrb__strlen(str) CXSL_STRLEN(str)
#else
	#include <string.h>
	#define nstrb__strlen(str) strlen(str)
#endif

#if defined(CXSL_NSTRB_MEMCPY)
	#define nstrb__memcpy(dest, src, sz) CXSL_NSTRB_MEMCPY(dest, src, sz)
#elif defined(CXSL_MEMCPY)
	#define nstrb__memcpy(dest, src, sz) CXSL_MEMCPY(dest, src, sz)
#else
	#include <string.h>
	#define nstrb__memcpy(dest, src, sz) memcpy(dest, src, sz)
#endif

// ----------------------- init and free -------------------------- // 

nstrb__t 		nstrb__empty 	() 
{
	return nstrb__new("", NULL);
}

nstrb__t 		nstrb__new 		(	const char* 	str 	, 
									void* 			user		) 
{
	size_t sz = nstrb__strlen(str);
	nstrb__t nstrb;

	if (sz > NSTRB__SSO_THRESHOLD) {
		nstrb.lg.sz = sz | NSTRB__DPTR_BIT_MASK | NSTRB__FREE_BIT_MASK;
		nstrb.lg.data = nstrb__malloc(sz + 1, user);

		nstrb__memcpy((void*) nstrb.lg.data, str, sz + 1);

	} else {
		nstrb.sm.sz = (uint8_t) sz;
		nstrb__memcpy(&nstrb.sm.data[0], str, sz + 1);
	}

	return nstrb;
}

nstrb__t 		nstrb__ofsize 	(	size_t 			sz 		, 
									void* 			user		)
{
	nstrb__t nstrb;
	char* data;

	if (sz > NSTRB__SSO_THRESHOLD) {
		nstrb.lg.sz = sz | NSTRB__DPTR_BIT_MASK | NSTRB__FREE_BIT_MASK;
		nstrb.lg.data = nstrb__malloc(sz + 1, user);

		data = (char*) &nstrb.lg.data[0];

		data[sz] = 0;

	} else {
		nstrb.sm.sz = (uint8_t) sz;
		
		nstrb.sm.data[sz] = 0;
	}

	return nstrb;
}

nstrb__t 		nstrb__move 		(	const char* str 	)
{
	nstrb__t nstrb;
	
	nstrb.lg.sz = nstrb__strlen(str) | NSTRB__DPTR_BIT_MASK;
	nstrb.lg.data = str;

	return nstrb;
}

nstrb__t 		nstrb__cmove		(	const char* str 	)
{
	size_t sz;

	sz = nstrb__strlen(str);

	if (sz > NSTRB__SSO_THRESHOLD) {
		return nstrb__move(str);

	} else {
		return nstrb__new(str, NULL);
	}
}

void 			nstrb__delete 	(	nstrb__t* 	nstrb 	,
									void*		user 		)
{
	if (nstrb->bsz.suffix & NSTRB__FREE_BIT_MASK) {
		nstrb__free((void*) nstrb->lg.data, user);
	}
}

// ----------------------- data access -------------------------- // 

const char* 	nstrb__begin 	(	nstrb__t* nstrb 	) 
{
	if (nstrb->bsz.suffix & NSTRB__DPTR_BIT_MASK) {
		return nstrb->lg.data;
	}
	else {
		return &nstrb->sm.data[0];
	}
}

const char* 	nstrb__end 		(	nstrb__t* nstrb 	) 
{
	return nstrb__begin(nstrb) + nstrb__size(nstrb) - 1;
}

const char* 	nstrb__endp1		( 	nstrb__t* nstrb 	) 
{
	return nstrb__begin(nstrb) + nstrb__size(nstrb);
}

size_t 			nstrb__size 		( 	nstrb__t* nstrb 	) 
{
	if (nstrb->bsz.suffix & NSTRB__DPTR_BIT_MASK) {
		return nstrb->lg.sz & ~NSTRB__RESERVED_BIT_MASK;
	}
	else {
		return (size_t) nstrb->sm.sz;
	}
}

const char* 	nstrb__data 		(	nstrb__t* nstrb 	)
{
	return nstrb__begin(nstrb);
}

const char* 	nstrb__tostr 	( 	nstrb__t* nstrb 	)
{
	return nstrb__begin(nstrb);
}

#endif // NSTRB_IMPLEMENTATION