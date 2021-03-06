#ifndef CXSL_PSTR_H
#define CXSL_PSTR_H

#include <stdint.h>

#undef PSTR__DEC
#undef PSTR__TYPE

#ifdef CXSL_PSTR_DEC
    #define PSTR__DEC(name) CXSL_PSTR_DEC(name)
#else
    #define PSTR__DEC(name) pstr_##name
#endif // PSTR_DEC

#define PSTR__TYPE(name) PSTR__DEC(name)##_t

// undefine 
#undef pstr__new
#undef pstr__ofsize
#undef pstr__delete

#undef pstr__len
#undef pstr__cap
#undef pstr__begin
#undef pstr__end
#undef pstr__endp1
#undef pstr__tostr

#undef pstr__t
#undef pstr__header_t

// definitions
#define pstr__new PSTR__DEC(new)
#define pstr__ofsize PSTR__DEC(ofsize)
#define pstr__delete PSTR__DEC(delete)

#define pstr__len PSTR__DEC(len)
#define pstr__cap PSTR__DEC(cap)
#define pstr__begin PSTR__DEC(begin)
#define pstr__end PSTR__DEC(end)
#define pstr__endp1 PSTR__DEC(endp1)
#define pstr__tostr PSTR__DEC(tostr)

#define pstr__t PSTR__DEC(t)
#define pstr__header_t PSTR__TYPE(header)

// ----------------------- declarations -------------------------- //

const char* pstr__new(const char* str, void* user);
const char* pstr__ofsize(size_t sz, void* user);
void pstr__delete(const char* str, void* user);

size_t pstr__len(const char* str);
const char* pstr__begin(const char* str);
const char* pstr__end(const char* str);
const char* pstr__endp1(const char* str);
const char* pstr__tostr(const char* str);

#endif // CXSL_PSTR_H

#ifdef CXSL_PSTR_IMPLEMENTATION

#undef CXSL_PSTR_IMPLEMENTATION

#undef pstr__malloc
#undef pstr__realloc
#undef pstr__free
#undef pstr__strlen
#undef pstr__memcpy
#undef pstr__assert

#if defined(CXSL_PSTR_MALLOC) || defined(CXSL_PSTR_REALLOC) || defined(CXSL_PSTR_FREE)
#if defined(CXSL_PSTR_MALLOC) && defined(CXSL_PSTR_REALLOC) && defined(CXSL_PSTR_FREE)
#define pstr__malloc(sz, user) CXSL_PSTR_MALLOC(sz, user)
#define pstr__realloc(ptr, sz, user) CXSL_PSTR_REALLOC(ptr, sz, user)
#define pstr__free(ptr, user) CXSL_PSTR_FREE(ptr, user)
#else
#error If any one of CXSL_PSTR_MALLOC, CXSL_PSTR_REALLOC, CXSL_PSTR_FREE is defined, then all of them must be defined
#endif
#elif defined(CXSL_MALLOC) || defined(CXSL_REALLOC) || defined(CXSL_FREE)
#if defined(CXSL_MALLOC) && defined(CXSL_REALLOC) && defined(CXSL_FREE)
#define pstr__malloc(sz, user) CXSL_MALLOC(sz, user)
#define pstr__realloc(ptr, sz, user) CXSL_REALLOC(ptr, sz, user)
#define pstr__free(ptr, user) CXSL_FREE(ptr, user)
#else
#error If any one of CXSL_MALLOC, CXSL_REALLOC, CXSL_FREE is defined, then all of them must be defined
#endif
#else
#include <malloc.h>

#define pstr__malloc(sz, user) malloc(sz)
#define pstr__realloc(ptr, sz, user) realloc(ptr, sz)
#define pstr__free(ptr, user) free(ptr)
#endif

#if defined(CXSL_PSTR_STRLEN)
#define pstr__strlen(str) CXSL_PSTR_STRLEN(str)
#elif defined(CXSL_STRLEN)
#define pstr__strlen(str) CXSL_STRLEN(str)
#else
#include <string.h>
#define pstr__strlen(str) strlen(str)
#endif

#if defined(CXSL_PSTRB_MEMCPY)
#define pstr__memcpy(dest, src, sz) CXSL_PSTR_MEMCPY(dest, src, sz)
#elif defined(CXSL_MEMCPY)
#define pstr__memcpy(dest, src, sz) CXSL_MEMCPY(dest, src, sz)
#else
#include <string.h>
#define pstr__memcpy(dest, src, sz) memcpy(dest, src, sz)
#endif

#if defined(CXSL_ASSERT)
#define pstr__assert(check, format, ...) CXSL_ASSERT(check, message, __VA_ARGS__)
#else
#include <assert.h>
#define pstr__assert(check, message, ...) assert(check)
#endif

// ----------------------- types -------------------------- //

typedef struct pstr__header_t {
    size_t sz;
} pstr__header_t;

typedef struct pstr__t {
    pstr__header_t header;
    char buff[1];

} pstr__t;

const uint8_t pstr__null_string[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// ----------------------- init and free -------------------------- // 

const char* pstr__new(const char* str,void* user) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    size_t sz;
    pstr__t* pstr;
    char* out;

    sz = pstr__strlen(str);

    if (sz == 0) {
        pstr = (pstr__t*) &pstr__null_string[0];

        out = &pstr->buff[0];

    } else {
        pstr = pstr__malloc(sizeof(pstr__header_t) + sz + 1, user);

        pstr__assert(pstr != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

        pstr->header.sz = sz;

        out = &pstr->buff[0];

        pstr__memcpy((void*) out, (void*) str, sz + 1);
    }

    return out;
}

const char* pstr__ofsize(size_t sz,void* user) 
{
    pstr__t* pstr;
    char* out;

    if (sz == 0) {
        pstr = (pstr__t*) &pstr__null_string[0];

        out = &pstr->buff[0];

    } else {
        pstr = pstr__malloc(sizeof(pstr__header_t) + sz + 1, user);

        pstr__assert(pstr != NULL, "Failed allocating a buffer for string [size = %zd]", sz);

        pstr->header.sz = sz;

        out = &pstr->buff[0];

        out[sz] = 0;    
    }
    
    return out;
}

void pstr__delete(const char* str,void* user) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    pstr__t* pstr = (pstr_t*) (str - sizeof(pstr__header_t));
    pstr__t* null_string = (pstr_t*) &pstr__null_string[0];

    if (pstr != null_string) {
        pstr__free((void*) (pstr), user);   
    }
}


// ----------------------- data access -------------------------- // 

size_t pstr__len(const char* str) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    pstr__t* pstr;

    pstr = (pstr__t*) (str - sizeof(size_t));

    return pstr->header.sz;
}

const char* pstr__begin(const char* str) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    return str;
}

const char* pstr__end (const char* str) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    return str + pstr__len(str) - 1;
}

const char* pstr__endp1 (const char* str) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    return str + pstr__len(str);
}

const char* pstr__tostr(const char* str) 
{
    pstr__assert(str != NULL, "Parameter str cannot be NULL");

    return str;
}

#endif // CXSL_PSTR_IMPLEMENTATION