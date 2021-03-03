#ifndef BUFF_H
#define BUFF_H

#include <stdint.h>

static void gpul_memcpy(void* dest, const void* src, size_t sz) {
	uint8_t* d = (uint8_t*) dest;
	uint8_t* s = (uint8_t*) src;

	for (; sz; --sz, ++d, ++s) {
		*d = *s;
	}
}

static void gpul_memset(void* dest, uint8_t b, size_t sz) {
	uint8_t* d = (uint8_t*) dest;

	for (; sz; --sz, ++d) {
		*d = b;
	}
}

#endif