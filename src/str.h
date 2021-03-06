#ifndef CXSL_STR_H
#define CXSL_STR_H

#include <stdint.h>

#undef CXSL__DEC

#ifdef CXSL_DEC
	#define CXSL__DEC(name) CXSL_DEF(name)
#else
	#define CXSL__DEC(name) cxsl_##name
#endif

#define cxsl__strlen		CXSL__DEC(strlen)
#define cxsl__containsc		CXSL__DEC(containsc)
#define cxsl__concat		CXSL__DEC(concat)
#define cxsl__strtok		CXSL__DEC(strtok)
#define cxsl__trim			CXSL__DEC(trim)
#define cxsl__substr		CXSL__DEC(substr)
#define cxsl__substri		CXSL__DEC(substri)
#define cxsl__substrn		CXSL__DEC(substrn)


// ----------------------- declarations -------------------------- //

size_t 		cxsl__strlen		(const char* str);
uint8_t 	cxsl__containsc		(const char* start, const char* endp1, char ch);
size_t 		cxsl__concat		(const char* str1_start, const char* str1_endp1, const char* str2_start, const char *str2_endp1, char* out);
size_t 		cxsl__strtok		(const char** base, const char* endp1, const char* delm_start, const char* delm_endp1, char* out);
size_t 		cxsl__trim			(const char* start, const char* endp1, char* out);
size_t 		cxsl__substr 		(const char* start, const char* endp1, size_t start_idx, char* out);
size_t 		cxsl__substri 		(const char* start, const char* endp1, size_t start_idx, size_t end_idx, char* out);
size_t 		cxsl__substrn 		(const char* start, const char* endp1, size_t start_idx, size_t len, char* out);

#endif

#ifdef CXSL_STR_IMPLEMENTATION

size_t 		cxsl__strlen		(	const char* str 	) {
	size_t sz;

	for (sz = 0; *str; str++, sz++) {

	}

	return sz;
}


uint8_t 	cxsl__containsc		(	const char* 	start	, 
									const char* 	endp1	, 
									char 			ch 			) 
{
	while (start != endp1) {
		if (*start == ch) {
			return 1;
		}
		start++;
	}

	return 0;
}

size_t 		cxsl__concat		(	const char* 	str1_start	, 
									const char* 	str1_endp1 	, 
									const char* 	str2_start	, 
									const char* 	str2_endp1 	, 
									char* 			out 			) 
{

	size_t i;

	for (i = 0; str1_start != str1_endp1; ++i, ++str1_start) {
		out[i] = *str1_start;
	}

	for (; str2_start != str2_endp1; ++i, ++str2_start) {
		out[i] = *str2_start;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__strtok		(	const char** 	base 		, 
									const char* 	endp1 		, 
									const char* 	delm_start 	, 
									const char* 	delm_endp1 	, 
									char* 			out 			) 
{
	const char* st = *base;
	size_t i;

	for (i = 0; st != endp1 && !cxsl__containsc(delm_start, delm_endp1, *st); ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	if (st != endp1) {
		st++;
	}

	*base = st;

	return i;
}


size_t 		cxsl__trim			(	const char* 	start	, 
									const char* 	endp1	, 
									char* 			out 		) 
{
	const char* st = start;
	const char* ed = endp1 - 1;
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

size_t 		cxsl__substr 		(	const char* 	start 		, 
									const char* 	endp1 		, 
									size_t 			start_idx	, 
									char* 			out 			) 
{
	const char* st;
	size_t i;

	for (i = 0, st = start + start_idx; st != endp1; ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__substri 		(	const char* 	start 		, 
									const char* 	endp1 		, 
									size_t 			start_idx	, 
									size_t 			end_idx		, 
									char* 			out 			) 
{
	const char* st = start + start_idx;
	const char* edp1 = endp1 + end_idx + 1;
	size_t i;

	for (i = 0; st != edp1; ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__substrn 		(	const char* 	start 		, 
									const char* 	endp1 		, 
									size_t 			start_idx	, 
									size_t 			len 		, 
									char* 			out 			) 
{
	const char* st = start + start_idx;
	size_t i = 0;

	for (i = 0; len; --len, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

#endif