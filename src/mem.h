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
#undef cxsl__memcmp
#undef cxsl__memmov

#define cxsl__memcpy CXSL__DEC(memcpy)
#define cxsl__memset CXSL__DEC(memset)
#define cxsl__memcmp CXSL__DEC(memcmp)
#define cxsl__memmov CXSL__DEC(memmov)

// ----------------------- declarations -------------------------- //

void cxsl__memcpy(void* dest, const void* src, size_t sz);
void cxsl__memset(void* dest, uint8_t b, size_t sz);
int8_t cxsl__memcmp(const void* m1, const void* m2, size_t sz);
void cxsl__memmov(void* dest, const void* src, size_t sz);

#endif

#ifdef CXSL_MEM_IMPLEMENTATION
#undef CXSL_MEM_IMPLEMENTATION

#undef cxsl__assert

#if defined(CXSL_ASSERT)
#define cxsl__assert(check, format, ...) CXSL_ASSERT(check, message, __VA_ARGS__)
#else
#include <assert.h>
#define cxsl__assert(check, message, ...) assert(check)
#endif

void cxsl__memcpy(void* dest,const void* src,size_t sz) 
{
    cxsl__assert(dest != NULL, "Parameter dest cannot be NULL");
    cxsl__assert(src != NULL, "Parameter src cannot be NULL");

    uint8_t* d = (uint8_t*) dest;
    uint8_t* s = (uint8_t*) src;

    for (; sz; --sz, ++d, ++s) {
        *d = *s;
    }
}

void cxsl__memset(void* dest,uint8_t b,size_t sz) 
{
    cxsl__assert(dest != NULL, "Parameter dest cannot be NULL");

    uint8_t* d = (uint8_t*) dest;

    for (; sz; --sz, ++d) {
        *d = b;
    }
}

int8_t cxsl__memcmp(const void* m1,const void* m2,size_t sz)
{
    cxsl__assert(m1 != NULL, "Parameter m1 cannot be NULL");
    cxsl__assert(m2 != NULL, "Parameter m2 cannot be NULL");

    const uint8_t* u1 = m1;
    const uint8_t* u2 = m2;

    for (; sz && *u1 == *u2; --sz, ++u1, ++u2);

    if (sz) {
        return *u1 < *u2 ? -1 : 1;
    } else {
        return 0;
    }
}

void cxsl__memmov(void* dest,const void* src,size_t sz)
{
    cxsl__assert(dest != NULL, "Parameter dest cannot be NULL");
    cxsl__assert(src != NULL, "Parameter src cannot be NULL");
    
    uint8_t* d = (uint8_t*) dest;
    uint8_t* s = (uint8_t*) src;

    for (; sz; --sz, ++d, ++s) {
        *d = *s;
    }
}

#endif