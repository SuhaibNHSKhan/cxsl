#ifndef NSTRB_H
#define NSTRB_H

#include <stdint.h>
#include <string.h>

typedef struct ostr {
	union {
		struct {
			char* data;
			size_t cap;
			size_t sz;
		} lg;
		struct {
			char data[sizeof(size_t) * 3 - 1];
			uint8_t sz;
		} sm;
		struct {
			size_t buff[3];
		} bsz;
	};
	
} ostr;

ostr ostr_new(const char* str) {
	size_t sz = strlen(str);
	ostr s;
	size_t shf = 1 << (sizeof(size_t) - 1);

	if (sz > 22)
	{
		s.lg.sz = sz | shf;
		s.lg.cap = 2 * sz + 1;
		s.lg.data = malloc(s.lg.cap + 1);

		memcpy(s.lg.data, str, sz + 1);
	}
	else {
		s.sm.sz = (uint8_t) sz;

		memcpy(&s.sm.data[0], str, sz + 1);
	}

	return s;
}


size_t mask[] = { 0x7fffffffffffffff, 0xff00000000000000 };
size_t shft[] = { 0, (sizeof(size_t) - 1) * 8 };

size_t get_size(ostr str) {
	size_t sz;
	size_t shf = 1 << (sizeof(size_t) - 1);

	size_t* b = &str.bsz.buff[0];

	size_t p = (b[2] & shf) == 0;

	sz = (b[2] & mask[p]) >> shft[p];

	return sz;
}


#endif