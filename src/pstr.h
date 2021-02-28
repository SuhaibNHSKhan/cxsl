#ifndef PSTR_H
#define PSTR_H

#include "buff.h"

typedef struct pstr_header_t {
	size_t sz;
} pstr_header_t;

typedef struct pstr_t {
	pstr_header_t header;
	char buff[1];

} pstr_t;

const char* pstr_new(const char* str, gpul_alloc alloc, void* user) {
	size_t sz = gpul_strlen(str);

	pstr_t* pstr = alloc(sizeof(pstr_header_t) + sz + 1, user);

	pstr->header.sz = sz;

	char* ostr = &pstr->buff[0];

	gpul_memcpy((void*) ostr, (void*) str, sz);

	ostr[sz] = 0;

	return ostr;
}

const char* pstr_ofsize(size_t sz, gpul_alloc alloc, void* user) {
	pstr_t* pstr = alloc(sizeof(pstr_header_t) + sz + 1, user);

	pstr->header.sz = sz;

	char* str = &pstr->buff[0];

	str[sz] = 0;

	return str;
}

size_t pstr_len(const char* str) {
	pstr_t* pstr = (pstr_t*) (str - sizeof(size_t));

	return pstr->header.sz;
}

const char* pstr_begin(const char* str) {
	return str;
}

const char* pstr_end(const char* str) {
	return str + pstr_len(str) - 1;
}

const char* pstr_endp1(const char* str) {
	return str + pstr_len(str);
}

const char* pstr_tostr(const char* str) {
	return str;
}

void pstr_free(const char* str, gpul_free gfree, void* user) {
	gfree((void*) (str - sizeof(pstr_header_t)), user);
}

#define pstr_for(var, str) for (const char* var = pstr_begin(str), const char* pstr__end = pstr_endp1(str); var != pstr__end; var++)

#endif