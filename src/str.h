#ifndef STR_H
#define STR_H

#include <stdint.h>

static size_t gpul_strlen(const char* str) {
	size_t sz;

	for (sz = 0; *str; str++, sz++) {

	}

	return sz;
}


static uint8_t gpul_containsc(const char* st, const char* ep, char ch) {
	while (st != ep) {
		if (*st == ch) {
			return 1;
		}
		st++;
	}

	return 0;
}

static size_t gpul_concat(const char* s1, const char* ep1, const char* s2, const char *ep2, char* out) {

	size_t i;

	for (i = 0; s1 != ep1; ++i, ++s1) {
		out[i] = *s1;
	}

	for (; s2 != ep2; ++i, ++s2) {
		out[i] = *s2;
	}

	out[i] = 0;

	return i;
}

static size_t gpul_strtok(const char** base, const char* ep, const char* delimiters, char* out) {
	const char* st = *base;
	const char* dep1 = delimiters + gpul_strlen(delimiters);
	size_t i;

	for (i = 0; st != ep && !gpul_containsc(delimiters, dep1, *st); ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	if (st != ep) {
		st++;
	}

	*base = st;

	return i;
}


static size_t gpul_trim(const char* s, const char* ep, char* out) {
	const char* st = s;
	const char* ed = ep - 1;
	size_t i;

	while (ed != st && (*ed == ' ' || *ed == '\r' || *ed == '\n' || *ed == '\t')) {
		ed--;
	}

	while (st != (ed + 1) && (*st == ' ' || *st == '\r' || *st == '\n' || *st == '\t')) {
		st++;
	}

	if (st == ed + 1) {
		out[0] = 0;
		return 0;
	}
	
	for (i = 0; st != ed + 1; ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

static size_t gpul_substr(const char* str, const char* ep, size_t s, char* out) {
	const char* st;
	size_t i;

	for (i = 0, st = str + s; st != ep; ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

static size_t gpul_substri(const char* str, const char* ep, size_t s, size_t e, char* out) {
	const char* st = str + s;
	const char* edp1 = str + e + 1;
	size_t i;

	for (i = 0; st != edp1; ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

static size_t gpul_substrn(const char* str, const char* ep, size_t s, size_t l, char* out) {
	const char* st = str + s;
	size_t i = 0;

	for (i = 0, st = str + s; l; --l, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

#endif