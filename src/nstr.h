#ifndef CXSL_NSTR_H
#define CXSL_NSTR_H

#include <stdint.h>

#undef NSTR__TYPE
#undef NSTR__SSO_THRESHOLD_BASE
#undef NSTR__SSO_THRESHOLD
#undef NSTR__DPTR_BIT_MASK
#undef NSTR__FREE_BIT_MASK
#undef NSTR__RESERVED_BIT_MASK
#undef NSTR__DEC
#undef NSTR__EXTRA_BYTES
#undef NSTR__MAX_SIZE

#ifdef CXSL_NSTR_DEC
	#define NSTR__DEC(name) CXSL_NSTR_DEC(name)
#else
	#define NSTR__DEC(name) nstr_##name
#endif

#ifdef CXSL_NSTR_EXTRA_BYTES
	#define NSTR__EXTRA_BYTES CXSL_NSTR_EXTRA_BYTES
#else
	#define NSTR__EXTRA_BYTES 0
#endif

#define NSTR__TYPE(name) NSTR__DEC(name)##_t

#define NSTR__SSO_THRESHOLD_BASE 14
#define NSTR__SSO_THRESHOLD (NSTR__SSO_THRESHOLD_BASE + NSTR__EXTRA_BYTES)

#if NSTR__SSO_THRESHOLD > 64
	#undef NSTR__SSO_THRESHOLD
	#define NSTR__SSO_THRESHOLD 64
#endif

#define NSTR__DPTR_BIT_MASK   	   	(1ULL << (sizeof(size_t) * 8 - 1))
#define NSTR__FREE_BIT_MASK      	(1ULL << (sizeof(size_t) * 8 - 2))
#define NSTR__RESERVED_BIT_MASK 	(NSTR__DPTR_BIT_MASK | NSTR__FREE_BIT_MASK)
#define NSTR__MAX_SIZE				(~NSTR__RESERVED_BIT_MASK)

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
#define nstr__empty 		NSTR__DEC(empty)
#define nstr__new 			NSTR__DEC(new)
#define nstr__ofsize 		NSTR__DEC(ofsize)
#define nstr__move 			NSTR__DEC(move)
#define nstr__cmove			NSTR__DEC(cmove)
#define nstr__delete 		NSTR__DEC(delete)

#define nstr__begin 		NSTR__DEC(begin)
#define nstr__end 			NSTR__DEC(end)
#define nstr__endp1 		NSTR__DEC(endp1)
#define nstr__size 			NSTR__DEC(size)
#define nstr__data 			NSTR__DEC(data)
#define nstr__tostr 		NSTR__DEC(tostr)

#define nstr__t 			NSTR__DEC(t)

// ----------------------- types -------------------------- //

typedef struct nstr__t {

	union {
		struct {
			const char* data;
			#if NSTR__EXTRA_BYTES
				uint8_t extra[NSTR__EXTRA_BYTES];
			#endif
			size_t sz;	
		} lg;

		struct {
			char data[sizeof(size_t) * 2 + NSTR__EXTRA_BYTES - 1];
			uint8_t sz;
		} sm;

		struct {
			size_t prefix[2 + NSTR__EXTRA_BYTES / sizeof(size_t) - 1];
			size_t suffix;
		} bsz;
	};
	
} nstr__t;

// ----------------------- declarations -------------------------- //

nstr__t 		nstr__empty 	();
nstr__t 		nstr__new 		(const char* str, void* user);
nstr__t 		nstr__ofsize 	(size_t sz, void* user);
nstr__t 		nstr__move 		(const char* str);
nstr__t 		nstr__cmove		(const char* str);
void 			nstr__delete 	(nstr__t* nstr, void* user);

const char* 	nstr__begin 	(nstr__t* nstr);
const char* 	nstr__end 		(nstr__t* nstr);
const char* 	nstr__endp1		(nstr__t* nstr);
size_t 			nstr__size 		(nstr__t* nstr);
const char* 	nstr__data 		(nstr__t* nstr);
const char* 	nstr__tostr 	(nstr__t* nstr);


#endif // NSTR_H

#ifdef CXSL_NSTR_IMPLEMENTATION

#undef CXSL_NSTR_IMPLEMENTATION

#undef nstr__malloc
#undef nstr__realloc
#undef nstr__free
#undef nstr__strlen
#undef nstr__memcpy
#undef nstr__assert

#if defined(CXSL_NSTR_MALLOC) || defined(CXSL_NSTR_REALLOC) || defined(CXSL_NSTR_FREE)
	#if defined(CXSL_NSTR_MALLOC) && defined(CXSL_NSTR_REALLOC) && defined(CXSL_NSTR_FREE)
		#define nstr__malloc(sz, user) CXSL_NSTR_MALLOC(sz, user)
		#define nstr__realloc(ptr, sz, user) CXSL_NSTR_REALLOC(ptr, sz, user)
		#define nstr__free(ptr, user) CXSL_NSTR_FREE(ptr, user)
	#else
		#error If any one of CXSL_NSTR_MALLOC, CXSL_NSTR_REALLOC, CXSL_NSTR_FREE is defined, then all of them must be defined
	#endif

#elif defined(CXSL_MALLOC) || defined(CXSL_REALLOC) || defined(CXSL_FREE)
	#if defined(CXSL_MALLOC) && defined(CXSL_REALLOC) && defined(CXSL_FREE)
		#define nstr__malloc(sz, user) CXSL_MALLOC(sz, user)
		#define nstr__realloc(ptr, sz, user) CXSL_REALLOC(ptr, sz, user)
		#define nstr__free(ptr, user) CXSL_FREE(ptr, user)
	#else
		#error If any one of CXSL_MALLOC, CXSL_REALLOC, CXSL_FREE is defined, then all of them must be defined
	#endif
#else
	#include <malloc.h>

	#define nstr__malloc(sz, user) malloc(sz)
	#define nstr__realloc(ptr, sz, user) realloc(ptr, sz)
	#define nstr__free(ptr, user) free(ptr)
#endif

#if defined(CXSL_NSTR_STRLEN)
	#define nstr__strlen(str) CXSL_NSTR_STRLEN(str)
#elif defined(CXSL_STRLEN)
	#define nstr__strlen(str) CXSL_STRLEN(str)
#else
	#include <string.h>
	#define nstr__strlen(str) strlen(str)
#endif

#if defined(CXSL_NSTR_MEMCPY)
	#define nstr__memcpy(dest, src, sz) CXSL_NSTR_MEMCPY(dest, src, sz)
#elif defined(CXSL_MEMCPY)
	#define nstr__memcpy(dest, src, sz) CXSL_MEMCPY(dest, src, sz)
#else
	#include <string.h>
	#define nstr__memcpy(dest, src, sz) memcpy(dest, src, sz)
#endif

#if defined(CXSL_ASSERT)
	#define nstr__assert(check, format, ...) CXSL_ASSERT(check, message, __VA_ARGS__)
#else
	#include <assert.h>
	#define nstr__assert(check, message, ...) assert(check)
#endif

// ----------------------- init and free -------------------------- // 

nstr__t 		nstr__empty 	() 
{
	return nstr__new("", NULL);
}

nstr__t 		nstr__new 		(	const char* 	str 	, 
									void* 			user		) 
{
	nstr__assert(str != NULL, "Parameter str cannot be NULL");

	size_t sz = nstr__strlen(str);

	nstr__assert(sz <= NSTR__MAX_SIZE, "Size of str = %zd, Max Size allowed for nstr = %zd", sz, NSTR__MAX_SIZE);

	nstr__t nstr;

	if (sz > NSTR__SSO_THRESHOLD) {
		nstr.lg.sz = sz | NSTR__DPTR_BIT_MASK | NSTR__FREE_BIT_MASK;
		nstr.lg.data = nstr__malloc(sz + 1, user);

		nstr__assert(nstr.lg.data != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

		nstr__memcpy((void*) nstr.lg.data, str, sz + 1);

	} else {
		nstr.sm.sz = (uint8_t) sz;
		nstr__memcpy(&nstr.sm.data[0], str, sz + 1);
	}

	return nstr;
}

nstr__t 		nstr__ofsize 	(	size_t 			sz 		, 
									void* 			user		)
{
	nstr__assert(sz <= NSTR__MAX_SIZE, "Size of str = %zd, Max Size allowed for nstr = %zd", sz, NSTR__MAX_SIZE);

	nstr__t nstr;

	if (sz > NSTR__SSO_THRESHOLD) {
		nstr.lg.sz = sz | NSTR__DPTR_BIT_MASK | NSTR__FREE_BIT_MASK;
		nstr.lg.data = nstr__malloc(sz + 1, user);

		nstr__assert(nstr.lg.data != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

		((char*) nstr.lg.data)[sz] = 0;

	} else {
		nstr.sm.sz = (uint8_t) sz;
		
		nstr.sm.data[sz] = 0;
	}

	return nstr;
}

nstr__t 		nstr__move 		(	const char* str 	)
{
	nstr__assert(str != NULL, "Parameter str cannot be NULL");
	size_t sz;

	sz = nstr__strlen(str);

	nstr__assert(sz <= NSTR__MAX_SIZE, "Size of str = %zd, Max Size allowed for nstr = %zd", sz, NSTR__MAX_SIZE);

	nstr__t nstr;
	
	nstr.lg.sz = sz | NSTR__DPTR_BIT_MASK;
	nstr.lg.data = str;

	return nstr;
}

nstr__t 		nstr__cmove		(	const char* str 	)
{
	nstr__assert(str != NULL, "Parameter str cannot be NULL");

	size_t sz;

	sz = nstr__strlen(str);

	nstr__assert(sz <= NSTR__MAX_SIZE, "Size of str = %zd, Max Size allowed for nstr = %zd", sz, NSTR__MAX_SIZE);

	if (sz > NSTR__SSO_THRESHOLD) {
		return nstr__move(str);

	} else {
		return nstr__new(str, NULL);
	}
}

void 			nstr__delete 	(	nstr__t* 	nstr 	,
									void*		user 		)
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	if (nstr->bsz.suffix & NSTR__FREE_BIT_MASK) {
		nstr__free((void*) nstr->lg.data, user);
	}
}

// ----------------------- data access -------------------------- // 

const char* 	nstr__begin 	(	nstr__t* nstr 	) 
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	if (nstr->bsz.suffix & NSTR__DPTR_BIT_MASK) {
		return nstr->lg.data;
	}
	else {
		return &nstr->sm.data[0];
	}
}

const char* 	nstr__end 		(	nstr__t* nstr 	) 
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	return nstr__begin(nstr) + nstr__size(nstr) - 1;
}

const char* 	nstr__endp1		( 	nstr__t* nstr 	) 
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	return nstr__begin(nstr) + nstr__size(nstr);
}

size_t 			nstr__size 		( 	nstr__t* nstr 	) 
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	if (nstr->bsz.suffix & NSTR__DPTR_BIT_MASK) {
		return nstr->lg.sz & ~NSTR__RESERVED_BIT_MASK;
	}
	else {
		return (size_t) nstr->sm.sz;
	}
}

const char* 	nstr__data 		(	nstr__t* nstr 	)
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	return nstr__begin(nstr);
}

const char* 	nstr__tostr 	( 	nstr__t* nstr 	)
{
	nstr__assert(nstr != NULL, "Parameter nstr cannot be NULL");

	return nstr__begin(nstr);
}

#endif // NSTR_IMPLEMENTATION