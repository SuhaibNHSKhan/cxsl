#ifndef CXSL_STR_H
#define CXSL_STR_H

#include <stdint.h>

#undef CXSL__DEC

#ifdef CXSL_DEC
	#define CXSL__DEC(name) CXSL_DEF(name)
#else
	#define CXSL__DEC(name) cxsl_##name
#endif

#define cxsl__cstrlen		CXSL__DEC(cstrlen)
#define cxsl__ccontainsc	CXSL__DEC(ccontainsc)
#define cxsl__cconcat		CXSL__DEC(cconcat)
#define cxsl__cstrtok		CXSL__DEC(cstrtok)
#define cxsl__ctrim			CXSL__DEC(ctrim)
#define cxsl__csubstr		CXSL__DEC(csubstr)
#define cxsl__csubstri		CXSL__DEC(csubstri)
#define cxsl__csubstrn		CXSL__DEC(csubstrn)
#define cxsl__cstrlwr		CXSL__DEC(cstrlwr)
#define cxsl__cstrupr		CXSL__DEC(cstrupr)
#define cxsl__cstrrev		CXSL__DEC(cstrrev)

#define cxsl__bcontainsc	CXSL__DEC(bcontainsc)
#define cxsl__bconcat		CXSL__DEC(bconcat)
#define cxsl__bstrtok		CXSL__DEC(bstrtok)
#define cxsl__btrim			CXSL__DEC(btrim)
#define cxsl__bsubstr		CXSL__DEC(bsubstr)
#define cxsl__bsubstri		CXSL__DEC(bsubstri)
#define cxsl__bsubstrn		CXSL__DEC(bsubstrn)
#define cxsl__bstrlwr		CXSL__DEC(bstrlwr)
#define cxsl__bstrupr		CXSL__DEC(bstrupr)
#define cxsl__bstrrev		CXSL__DEC(bstrrev)

// ----------------------- declarations -------------------------- //

size_t 		cxsl__cstrlen		(const char* str);
uint8_t 	cxsl__cstrhas		(const char* str, char ch);
int8_t		cxsl__cstrcmp		(const char* str1, const char* str2);
size_t 		cxsl__cstrlwr		(const char* str, char* out, size_t sz);
size_t 		cxsl__cstrupr		(const char* str, char* out, size_t sz);
size_t 		cxsl__cstrrev		(const char* str, char* out, size_t sz);
size_t 		cxsl__cconcat		(const char* str1, const char* str2, char* out, size_t sz);
size_t 		cxsl__cstrtok		(const char** base, const char* delimiters, char* out, size_t sz);
size_t 		cxsl__ctrim			(const char* str, char* out, size_t sz);
size_t 		cxsl__csubstr 		(const char* str, size_t start_idx, char* out, size_t sz);
size_t 		cxsl__csubstri 		(const char* str, size_t start_idx, size_t end_idx, char* out, size_t sz);
size_t 		cxsl__csubstrn 		(const char* str, size_t start_idx, size_t len, char* out, size_t sz);


uint8_t 	cxsl__bstrhas		(const char* start, const char* endp1, char ch);
int8_t		cxsl__bstrcmp		(const char* str1_start, const char* str1_endp1, const char* str2_start, const char *str2_endp1);
size_t 		cxsl__bstrlwr		(const char* start, const char* endp1, char* out, size_t sz);
size_t 		cxsl__bstrupr		(const char* start, const char* endp1, char* out, size_t sz);
size_t 		cxsl__bstrrev		(const char* start, const char* endp1, char* out, size_t sz);
size_t 		cxsl__bconcat		(const char* str1_start, const char* str1_endp1, const char* str2_start, const char *str2_endp1, char* out, size_t sz);
size_t 		cxsl__bstrtok		(const char** base, const char* endp1, const char* delm_start, const char* delm_endp1, char* out, size_t sz);
size_t 		cxsl__btrim			(const char* start, const char* endp1, char* out, size_t sz);
size_t 		cxsl__bsubstr 		(const char* start, const char* endp1, size_t start_idx, char* out, size_t sz);
size_t 		cxsl__bsubstri 		(const char* start, const char* endp1, size_t start_idx, size_t end_idx, char* out, size_t sz);
size_t 		cxsl__bsubstrn 		(const char* start, const char* endp1, size_t start_idx, size_t len, char* out, size_t sz);


#endif

#ifdef CXSL_STR_IMPLEMENTATION
#undef CXSL_STR_IMPLEMENTATION

#undef cxsl__assert

#if defined(CXSL_ASSERT)
	#define cxsl__assert(check, format, ...) CXSL_ASSERT(check, message, __VA_ARGS__)
#else
	#include <assert.h>
	#define cxsl__assert(check, message, ...) assert(check)
#endif

// cstring functions

size_t 		cxsl__cstrlen		(	const char* str 	) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t sz;

	for (sz = 0; *str; str++, sz++) {

	}

	return sz;
}

uint8_t 	cxsl__cstrhas		(	const char* 	str 	, 
									char 			ch 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	for (; *str; ++str) {
		if (*str == ch) return 1; 
	}

	return 0;
}

int8_t		cxsl__cstrcmp		(const char* str1, const char* str2)
{	
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");

	if (str1 == str2) {
		return 0;
	}

	for (; *str1 && *str2 && *str1 == *str2; ++str1, ++str2) {

	}

	if (*str1 == 0 && *str2 == 0) {
		return 0;
	} else {
		if (*str1 == 0) {
			return -1;
		} else if (*str2 == 0) {
			return 1;
		} else {
			return *str1 < *str2 ? -1 : 1;
		}
	}
}

size_t 		cxsl__cstrlwr		(	const char* 	str 		, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i, r;
	sz--;

	for (i = 0; sz && *str; ++str, ++i, --sz) {
		if (*str >= 'A' && *str <= 'Z') {
			out[i] = (*str - 'A') + 'a';	
		}
	}

	out[i] = 0;

	if (*str) {
		for (r = 0; *str; ++str, ++r);

		return r;
	} else {
		return 0;
	}
}

size_t 		cxsl__cstrupr		(	const char* 	str 		, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i, r;
	sz--;

	for (i = 0; sz && *str; ++str, ++i, --sz) {
		if (*str >= 'a' && *str <= 'z') {
			out[i] = (*str - 'a') + 'A';	
		}
	}

	out[i] = 0;

	if (*str) {
		for (r = 0; *str; ++str, ++r);

		return r;
	} else {
		return 0;
	}
}

size_t 		cxsl__cstrrev		(	const char* 	str 		, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	return cxsl__bstrrev(str, str + cxsl__cstrlen(str), out, sz);
}

size_t 		cxsl__cconcat		(	const char* 	str1 	, 
									const char* 	str2 	, 
									char* 			out 	,
									size_t 			sz 			)
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i, r;

	sz--;

	for (i = 0; sz && *str1; --sz, ++str1) {
		out[i] = *str1;
	}

	for (r = 0; *str1; ++str1, ++r);

	for (; sz && *str2; --sz, ++str2) {
		out[i] = *str2;
	}

	for (; *str2; ++str2, ++r);

	out[i] = 0;

	return r;
}

size_t 		cxsl__cstrtok		(	const char** 	base 		, 
									const char* 	delimiters 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(base != NULL, "Parameter base cannot be NULL");
	cxsl__assert(*base != NULL, "Parameter base should not point to a NULL");
	cxsl__assert(delimiters != NULL, "Parameter delimiters cannot be NULL");

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char* st = *base;
	size_t i, r;

	r = 0;
	sz--; // need one byte for null always

	for (i = 0; sz && *st && !cxsl__cstrhas(delimiters, *st); --sz, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	if (sz && *st) {
		st++;
	}

	*base = st;

	if (sz == 0) {
		for (; *st && !cxsl__cstrhas(delimiters, *st); ++st, ++r);
	}

	return r;
}

size_t 		cxsl__ctrim			(	const char* 	str 	, 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	return cxsl__btrim(str, str + cxsl__cstrlen(str), out, sz);
}

size_t 		cxsl__csubstr 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									char* 			out 		, 
									size_t 			sz 				) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i, r;
	const char* st;

	sz--;

	for (i = 0, st = str + start_idx; sz && *st; --sz, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	for (r = 0; *st; ++st, ++r); 

	return r;
}

size_t 		cxsl__csubstri 		(	const char*		str 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 	, 
									char* 			out 		, 
									size_t 			sz 				) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(end_idx >= start_idx, "start_idx [%zd] must be either <= to end_idx [%zd]", start_idx, end_idx);
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char *st, *ep1;
	size_t i, r;

	sz--;

	for (st = str + start_idx, ep1 = str + end_idx + 1, i = 0; sz && *st && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	for (r = 0; *st && st != ep1; ++st, ++r);

	return r;

}

size_t 		cxsl__csubstrn 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									size_t 			len 		, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char *st, *ep1;
	size_t i, r;

	sz--;

	for (st = str + start_idx, ep1 = str + start_idx + len, i = 0; sz && *st && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	for (r = 0; *st && st != ep1; ++st, ++r);

	return r;
}

// bounded string function

uint8_t 	cxsl__bstrhas		(	const char* 	start	, 
									const char* 	endp1	, 
									char 			ch 			) 
{
	cxsl__assert(start != NULL, "Parameter start cannot be NULL");
	cxsl__assert(endp1 != NULL, "Parameter endp1 cannot be NULL");
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) start, "start [%p] must be either <= to endp1 [%p]", start, endp1);

	while (start != endp1) {
		if (*start == ch) {
			return 1;
		}
		start++;
	}

	return 0;
}

int8_t		cxsl__bstrcmp		(	const char* 	str1_start 	, 
									const char* 	str1_endp1 	, 
									const char* 	str2_start 	, 
									const char* 	str2_endp1 		) 
{
	cxsl__assert(str1_start != NULL, "Parameter str1_start cannot be NULL");
	cxsl__assert(str1_endp1 != NULL, "Parameter str1_endp1 cannot be NULL");
	cxsl__assert((uintptr_t) str1_endp1 >= (uintptr_t) str1_start, "start [%p] must be either <= to endp1 [%p]", str1_start, str1_endp1);

	cxsl__assert(str2_start != NULL, "Parameter str1_start cannot be NULL");
	cxsl__assert(str2_endp1 != NULL, "Parameter str1_endp1 cannot be NULL");
	cxsl__assert((uintptr_t) str2_endp1 >= (uintptr_t) str2_start, "start [%p] must be either <= to endp1 [%p]", str2_start, str2_endp1);


	if (str1_start == str2_start && str1_endp1 == str2_endp1) {
		return 0;
	}

	for (; str1_start != str1_endp1 && str2_start != str2_endp1 && *str1_start == *str2_start; ++str1_start, ++str2_start) {

	}

	if (str1_start == str1_endp1 && str2_start == str2_endp1) {
		return 0;
	} else {
		if (str1_start == str1_endp1) {
			return -1;
		} else if (str2_start == str2_endp1) {
			return 1;
		} else {
			return *str1_start < *str2_start ? -1 : 1;
		}
	}
}

size_t 		cxsl__bstrlwr		(	const char* 	start 	, 
									const char* 	endp1 	, 
									char* 			out 	, 
									size_t 			sz 			) 
{
	size_t i;

	sz--;

	for (i = 0; sz && start != endp1; ++start, ++i, --sz) {
		if (*start >= 'A' && *start <= 'Z') {
			out[i] = (*start - 'A') + 'a';
		} else {
			out[i] = *start;
		}
	}

	out[i] = 0;

	return (size_t) endp1 - (size_t) start;
}

size_t 		cxsl__bstrupr		(	const char* 	start 	, 
									const char* 	endp1 	, 
									char* 			out 	, 
									size_t 			sz 			) 
{
	size_t i;

	sz--;

	for (i = 0; sz && start != endp1; ++start, ++i, --sz) {
		if (*start >= 'a' && *start <= 'z') {
			out[i] = (*start - 'a') + 'A';
		} else {
			out[i] = *start;
		}
	}

	out[i] = 0;

	return (size_t) endp1 - (size_t) start;
}

size_t 		cxsl__bstrrev		(	const char* 	start 	, 
									const char* 	endp1 	, 
									char* 			out 	, 
									size_t 			sz 			) 
{
	const char* ed = endp1 - 1;
	const char* sm1 = start - 1;
	size_t i;

	sz--;

	for (i = 0; sz && ed != sm1; --ed, ++i, --sz) {
		out[i] = *ed;
	}

	out[i] = 0;

	return (size_t) ed - (size_t) sm1;
}

size_t 		cxsl__bconcat		(	const char* 	str1_start	, 
									const char* 	str1_endp1 	, 
									const char* 	str2_start	, 
									const char* 	str2_endp1 	, 
									char* 			out			,
									size_t			sz 				) 
{
	cxsl__assert(str1_start != NULL, "Parameter str1_start cannot be NULL");
	cxsl__assert(str1_endp1 != NULL, "Parameter str1_endp1 cannot be NULL");
	cxsl__assert((uintptr_t) str1_endp1 >= (uintptr_t) str1_start, "start [%p] must be either <= to endp1 [%p]", str1_start, str1_endp1);

	cxsl__assert(str2_start != NULL, "Parameter str1_start cannot be NULL");
	cxsl__assert(str2_endp1 != NULL, "Parameter str1_endp1 cannot be NULL");
	cxsl__assert((uintptr_t) str2_endp1 >= (uintptr_t) str2_start, "start [%p] must be either <= to endp1 [%p]", str2_start, str2_endp1);

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i, r;

	r = 0;
	sz--; // need one byte for null always

	for (i = 0; sz > 0 && str1_start != str1_endp1; --sz, ++i, ++str1_start) {
		out[i] = *str1_start;
	}

	for (; sz > 0 && str2_start != str2_endp1; --sz, ++i, ++str2_start) {
		out[i] = *str2_start;
	}


	r += (size_t) str1_endp1 - (size_t) str1_start;
	r += (size_t) str2_endp1 - (size_t) str2_start;

	out[i] = 0;

	return r;
}

size_t 		cxsl__bstrtok		(	const char** 	base 		, 
									const char* 	endp1 		, 
									const char* 	delm_start 	, 
									const char* 	delm_endp1 	, 
									char* 			out			,
									size_t 			sz 				) 
{
	cxsl__assert(base != NULL, "Parameter base cannot be NULL");

	cxsl__assert(*base != NULL, "Parameter base should not point to a NULL");
	cxsl__assert(endp1 != NULL, "Parameter endp1 cannot be NULL");
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) *base, "start (*base) [%p] must be either <= to endp1 [%p]", st, endp1);	

	cxsl__assert(delm_start != NULL, "Parameter delm_start cannot be NULL");
	cxsl__assert(delm_endp1 != NULL, "Parameter delm_endp1 cannot be NULL");
	cxsl__assert((uintptr_t) delm_endp1 >= (uintptr_t) delm_start, "delm_start [%p] must be either <= to delm_endp1 [%p]", delm_start, delm_endp1);

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char* st = *base;
	size_t i, r;

	r = 0;
	sz--; // need one byte for null always

	for (i = 0; sz && st != endp1 && !cxsl__bstrhas(delm_start, delm_endp1, *st); --sz, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	if (sz && st != endp1) {
		st++;
	}

	*base = st;

	
	if (sz == 0) {
		for (; st != endp1 && !cxsl__bstrhas(delm_start, delm_endp1, *st); ++st, ++r);
	}
	

	return r;
}


size_t 		cxsl__btrim			(	const char* 	start	, 
									const char* 	endp1	, 
									char* 			out		,
									size_t 			sz 			) 
{
	cxsl__assert(start != NULL, "Parameter start cannot be NULL");
	cxsl__assert(endp1 != NULL, "Parameter endp1 cannot be NULL");
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) start, "start [%p] must be either <= to endp1 [%p]", delm_start, delm_endp1);

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

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

	sz--; // need one byte for null always
	
	for (i = 0; sz && st != ed + 1; --sz, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return (size_t) ed - (size_t) st + 1;
}

size_t 		cxsl__bsubstr 		(	const char* 	start 		, 
									const char* 	endp1 		, 
									size_t 			start_idx	, 
									char* 			out 		,
									size_t			sz 				) 
{
	cxsl__assert(start != NULL, "Parameter start cannot be NULL");
	cxsl__assert(endp1 != NULL, "Parameter endp1 cannot be NULL");
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) start, "start [%p] must be either <= to endp1 [%p]", start, endp1);
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) (start + start_idx), "start + start_idx [%p] must be either <= to endp1 [%p]", start + start_idx, endp1);

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char* st;
	size_t i;

	sz--; // need one byte for null always

	for (i = 0, st = start + start_idx; sz && st != endp1; --sz, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return (size_t) endp1 - (size_t) st;
}

size_t 		cxsl__bsubstri 		(	const char* 	start 		, 
									const char* 	endp1 		, 
									size_t 			start_idx	, 
									size_t 			end_idx		, 
									char* 			out 		,
									size_t			sz 				) 
{
	cxsl__assert(start != NULL, "Parameter start cannot be NULL");
	cxsl__assert(endp1 != NULL, "Parameter endp1 cannot be NULL");
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) start, "start [%p] must be either <= to endp1 [%p]", start, endp1);
	cxsl__assert(end_idx >= start_idx, "start_idx [%zd] must be either <= to end_idx [%zd]", start_idx, end_idx);
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) (start + start_idx), "start + start_idx [%p] must be either <= to endp1 [%p]", start + start_idx, endp1);
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) (start + end_idx), "start + end_idx [%p] must be either <= to endp1 [%p]", start + end_idx, endp1);

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char* st = start + start_idx;
	const char* edp1 = endp1 + end_idx + 1;
	size_t i;

	sz--; // need one byte for null always

	for (i = 0; sz && st != edp1; ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return (size_t) edp1 - (size_t) st;
}

size_t 		cxsl__bsubstrn 		(	const char* 	start 		, 
									const char* 	endp1 		, 
									size_t 			start_idx	, 
									size_t 			len 		, 
									char* 			out 		,
									size_t 			sz 				) 
{
	cxsl__assert(start != NULL, "Parameter start cannot be NULL");
	cxsl__assert(endp1 != NULL, "Parameter endp1 cannot be NULL");
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) start, "start [%p] must be either <= to endp1 [%p]", start, endp1);
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) (start + start_idx), "start + start_idx [%p] must be either <= to endp1 [%p]", start + start_idx, endp1);
	cxsl__assert((uintptr_t) endp1 >= (uintptr_t) (start + start_idx + len), "start + end_idx [%p] must be either <= to endp1 [%p]", start + start_idx + len, endp1);

	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char* st = start + start_idx;
	size_t i;

	sz--; // need one byte for null always

	for (i = 0; sz && len; --len, --sz, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	return (size_t) endp1 - (size_t) st;
}

#endif