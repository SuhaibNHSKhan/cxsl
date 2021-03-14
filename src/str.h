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
#define cxsl__cstrhas		CXSL__DEC(cstrhas)
#define cxsl__cstrcmp		CXSL__DEC(cstrcmp)
#define cxsl__cstrlwr		CXSL__DEC(cstrlwr)
#define cxsl__cstrupr		CXSL__DEC(cstrupr)
#define cxsl__cstrrev		CXSL__DEC(cstrrev)
#define cxsl__cstrcat		CXSL__DEC(cstrcat)
#define cxsl__cstrtok		CXSL__DEC(cstrtok)
#define cxsl__cstrtrm		CXSL__DEC(cstrtrm)
#define cxsl__cstrsub		CXSL__DEC(cstrsub)
#define cxsl__cstrsubi		CXSL__DEC(cstrsubi)
#define cxsl__cstrsubn		CXSL__DEC(cstrsubn)

#define cxsl__fstrlwr		CXSL__DEC(fstrlwr)
#define cxsl__fstrupr		CXSL__DEC(fstrupr)
#define cxsl__fstrrev		CXSL__DEC(fstrrev)
#define cxsl__fstrcat		CXSL__DEC(fstrcat)
#define cxsl__fstrtok		CXSL__DEC(fstrtok)
#define cxsl__fstrtrm		CXSL__DEC(fstrtrm)
#define cxsl__fstrsub 		CXSL__DEC(fstrsub)
#define cxsl__fstrsubi		CXSL__DEC(fstrsubi)
#define cxsl__fstrsubn		CXSL__DEC(fstrsubn)

#define cxsl__lstrlwr		CXSL__DEC(lstrlwr)
#define cxsl__lstrupr		CXSL__DEC(lstrupr)
#define cxsl__lstrrev		CXSL__DEC(lstrrev)
#define cxsl__lstrcat		CXSL__DEC(lstrcat)
#define cxsl__lstrtok		CXSL__DEC(lstrtok)
#define cxsl__lstrtrm		CXSL__DEC(lstrtrm)
#define cxsl__lstrsub 		CXSL__DEC(lstrsub)
#define cxsl__lstrsubi		CXSL__DEC(lstrsubi)
#define cxsl__lstrsubn		CXSL__DEC(lstrsubn)

#define cxsl__nstrhas		CXSL__DEC(nstrhas)
#define cxsl__nstrcmp		CXSL__DEC(nstrcmp)
#define cxsl__nstrlwr		CXSL__DEC(nstrlwr)
#define cxsl__nstrupr		CXSL__DEC(nstrupr)
#define cxsl__nstrrev		CXSL__DEC(nstrrev)
#define cxsl__nstrcat		CXSL__DEC(nstrcat)
#define cxsl__nstrtok		CXSL__DEC(nstrtok)
#define cxsl__nstrtrm		CXSL__DEC(nstrtrm)
#define cxsl__nsubstr		CXSL__DEC(nsubstr)
#define cxsl__nsubstri		CXSL__DEC(nsubstri)
#define cxsl__nsubstrn		CXSL__DEC(nsubstrn)

#define cxsl__fnstrlwr		CXSL__DEC(fnstrlwr)
#define cxsl__fnstrupr		CXSL__DEC(fnstrupr)
#define cxsl__fnstrrev		CXSL__DEC(fnstrrev)
#define cxsl__fnstrcat		CXSL__DEC(fnstrcat)
#define cxsl__fnstrtok		CXSL__DEC(fnstrtok)
#define cxsl__fnstrtrm		CXSL__DEC(fnstrtrm)
#define cxsl__fnsubstr 		CXSL__DEC(fnsubstr)
#define cxsl__fnsubstri 	CXSL__DEC(fnsubstri)
#define cxsl__fnsubstrn 	CXSL__DEC(fnsubstrn)

// ----------------------- declarations -------------------------- //

size_t 		cxsl__cstrlen		(const char* str);
uint8_t 	cxsl__cstrhas		(const char* str, char ch);
int8_t		cxsl__cstrcmp		(const char* str1, const char* str2);
size_t 		cxsl__cstrlwr		(const char* str, const char** context, char* out, size_t sz);
size_t	 	cxsl__cstrupr		(const char* str, const char** context, char* out, size_t sz);
size_t 		cxsl__cstrrev		(const char* str, const char**	context, char* out, size_t sz);
size_t 		cxsl__cstrcat		(const char* str1, const char* str2, const char**	context, char* out, size_t sz);
size_t 		cxsl__cstrtok		(const char* str, const char* delimiters, const char** context, char* out, size_t sz);
size_t 		cxsl__cstrtrm		(const char* str, const char** context, char* out, size_t sz);
size_t 		cxsl__cstrsub 		(const char* str, size_t start_idx, const char** context, char* out, size_t sz);
size_t 		cxsl__cstrsubi 		(const char* str, size_t start_idx, size_t end_idx, const char** context, char* out, size_t sz);
size_t 		cxsl__cstrsubn 		(const char* str, size_t start_idx, size_t len, const char** context, char* out, size_t sz);

size_t 		cxsl__fstrlwr		(const char* str, char* out);
size_t	 	cxsl__fstrupr		(const char* str, char* out);
size_t 		cxsl__fstrrev		(const char* str, char* out);
size_t 		cxsl__fstrcat		(const char* str1, const char* str2, char* out);
size_t 		cxsl__fstrtok		(const char* str, const char* delimiters, const char** context, char* out);
size_t 		cxsl__fstrtrm		(const char* str, char* out);
size_t 		cxsl__fstrsub 		(const char* str, size_t start_idx, char* out);
size_t 		cxsl__fstrsubi 		(const char* str, size_t start_idx, size_t end_idx, char* out);
size_t 		cxsl__fstrsubn 		(const char* str, size_t start_idx, size_t len, char* out);

size_t 		cxsl__lstrlwr		(const char* str);
size_t	 	cxsl__lstrupr		(const char* str);
size_t 		cxsl__lstrrev		(const char* str);
size_t 		cxsl__lstrcat		(const char* str1, const char* str2);
size_t 		cxsl__lstrtok		(const char* str, const char* delimiters, const char** context);
size_t 		cxsl__lstrtrm		(const char* str);
size_t 		cxsl__lstrsub 		(const char* str, size_t start_idx);
size_t 		cxsl__lstrsubi 		(const char* str, size_t start_idx, size_t end_idx);
size_t 		cxsl__lstrsubn 		(const char* str, size_t start_idx, size_t len);

uint8_t 	cxsl__nstrhas		(const char* str, size_t len, char ch);
int8_t		cxsl__nstrcmp		(const char* str1, size_t len1, const char* str2, size_t len2);
size_t 		cxsl__nstrlwr		(const char* str, size_t len, const char** context, char* out, size_t sz);
size_t 		cxsl__nstrupr		(const char* str, size_t len, const char** context, char* out, size_t sz);
size_t 		cxsl__nstrrev		(const char* str, size_t len, const char** context, char* out, size_t sz);
size_t 		cxsl__nstrcat		(const char* str1, size_t len1, const char* str2, size_t len2, const char** context, char* out, size_t sz);
size_t 		cxsl__nstrtok		(const char* str, size_t len, const char* delimiters, size_t dlen, const char** context, char* out, size_t sz);
size_t 		cxsl__nstrtrm 		(const char* str, size_t len, const char** context, char* out, size_t sz);
size_t 		cxsl__nsubstr 		(const char* str, size_t len, size_t start_idx, const char** context, char* out, size_t sz);
size_t 		cxsl__nsubstri 		(const char* str, size_t len, size_t start_idx, size_t end_idx, const char** context, char* out, size_t sz);
size_t 		cxsl__nsubstrn 		(const char* str, size_t len, size_t start_idx, size_t l, const char** context, char* out, size_t sz);

size_t 		cxsl__fnstrlwr		(const char* str, size_t len, char* out, size_t sz);
size_t 		cxsl__fnstrupr		(const char* str, size_t len, char* out, size_t sz);
size_t 		cxsl__fnstrrev		(const char* str, size_t len, char* out, size_t sz);
size_t 		cxsl__fnstrcat		(const char* str1, size_t len1, const char* str2, size_t len2, char* out, size_t sz);
size_t 		cxsl__fnstrtok		(const char* str, size_t len, const char* delimiters, size_t dlen, const char** context, char* out, size_t sz);
size_t 		cxsl__fntrim		(const char* str, size_t len, char* out, size_t sz);
size_t 		cxsl__fnsubstr 		(const char* str, size_t len, size_t start_idx, char* out, size_t sz);
size_t 		cxsl__fnsubstri 	(const char* str, size_t len, size_t start_idx, size_t end_idx, char* out, size_t sz);
size_t 		cxsl__fnsubstrn 	(const char* str, size_t len, size_t start_idx, size_t l, char* out, size_t sz);

size_t 		cxsl__lnstrlwr		(const char* str, size_t len);
size_t 		cxsl__lnstrupr		(const char* str, size_t len);
size_t 		cxsl__lnstrrev		(const char* str, size_t len);
size_t 		cxsl__lnconcat		(const char* str1, size_t len1, const char* str2, size_t len2);
size_t 		cxsl__lnstrtok		(const char* str, size_t len, const char* delimiters, size_t dlen, const char** context);
size_t 		cxsl__lntrim		(const char* str, size_t len);
size_t 		cxsl__lnsubstr 		(const char* str, size_t len, size_t start_idx);
size_t 		cxsl__lnsubstri 	(const char* str, size_t len, size_t start_idx, size_t end_idx);
size_t 		cxsl__lnsubstrn 	(const char* str, size_t len, size_t start_idx, size_t l);

#endif

#ifdef CXSL_STR_IMPLEMENTATION
#undef CXSL_STR_IMPLEMENTATION

#undef cxsl__assert
#undef cxsl__min
#undef cxsl__max

#if defined(CXSL_ASSERT)
	#define cxsl__assert(check, format, ...) CXSL_ASSERT(check, message, __VA_ARGS__)
#else
	#include <assert.h>
	#define cxsl__assert(check, message, ...) assert(check)
#endif

#define cxsl__conditionally_update_context(context, value) if (*(context)) *(context) = value
#define cxsl__get_start(context, start) (context && *context) ? *(context) : (start)

#define cxsl__label_internal(func, label) func##_##label
#define cxsl__label(func, label) cxsl__label_internal(func, label)
#define cxsl__size_only_label(func) cxsl__label(func, size_only)
#define cxsl__conditionally_goto_size_only(func, out) if (!out) goto cxsl__size_only_label(func)
#define cxsl__min(a, b) ((a) < (b) ? (a) : (b))
#define cxsl__max(a, b) ((a) > (b) ? (a) : (b))

size_t 		cxsl__outstrsz		(size_t ret_val, size_t buffer_size) 
{
	return ret_val == 0 ? buffer_size - 1 : ret_val - 1;
}

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
									const char**	context		,
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	cxsl__conditionally_goto_size_only(cxsl__cstrlwr, out);

	sz--;

	for (i = 0; sz && *st; ++st, ++i, --sz) {
		if (*st >= 'A' && *st <= 'Z') {
			out[i] = (*st - 'A') + 'a';	
		} else {
			out[i] = *st;	
		}
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return *st ? 0 : i + 1;

	cxsl__size_only_label(cxsl__cstrlwr):
	
	return cxsl__cstrlen(st);
}

size_t 		cxsl__cstrupr		(	const char* 	str 		, 
									const char**	context		,
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	cxsl__conditionally_goto_size_only(cxsl__cstrlwr, out);

	sz--;

	for (i = 0; sz && *st; ++st, ++i, --sz) {
		if (*st >= 'a' && *st <= 'z') {
			out[i] = (*st - 'a') + 'A';	
		} else {
			out[i] = *st;	
		}
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return *st ? 0 : i + 1;

	cxsl__size_only_label(cxsl__cstrlwr):
	
	return cxsl__cstrlen(st);
}


size_t 		cxsl__cstrrev		(	const char* 	str 		,
									const char**	context 	,
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	
	size_t i;
	const char* sm1 = str - 1;
	const char* ed  = str + cxsl__cstrlen(str) - 1;

	ed = cxsl__get_start(context, ed);

	cxsl__conditionally_goto_size_only(cxsl__cstrrev, out);

	sz--;

	for (i = 0; sz && ed != sm1; --ed, --sz, ++i) {
		out[i] = *ed;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, ed);

	return ed != sm1 ? 0 : i + 1;

	cxsl__size_only_label(cxsl__cstrrev):

	return (size_t) ed - (size_t) sm1;
}

size_t 		cxsl__cstrcat		(	const char* 	str1 	, 
									const char* 	str2 	, 
									const char**	context ,
									char* 			out 	,
									size_t 			sz 			)
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");

	cxsl__conditionally_goto_size_only(cxsl__cstrcat, out);

	char* curr;
	size_t i;

	i = 0;
	sz--;

	if (!context) goto cxsl__label(cxsl__cstrcat, skip_context);

	curr = (char*) *context;

	intptr_t diff1 = (intptr_t) curr - (intptr_t) str1;
	intptr_t diff2 = (intptr_t) curr - (intptr_t) str2;

	if (diff2 < 0 || diff1 < diff2) {
		goto cxsl__label(cxsl__cstrcat, direct_str1);
	} else if (diff1 < 0 || diff2 < diff1) {
		goto cxsl__label(cxsl__cstrcat, direct_str2);
	} else {
		cxsl__assert(0, "Reached unreachable code");
	}

	cxsl__label(cxsl__cstrcat, skip_context):

	curr = (char*) str1; 

	cxsl__label(cxsl__cstrcat, direct_str1):

	for (; sz && *curr; --sz, ++curr, ++i) {
		out[i] = *curr;
	}

	if (!(*curr)) {
		curr = (char*) str2;

		cxsl__label(cxsl__cstrcat, direct_str2):

		for (; sz && *curr; --sz, ++curr, ++i) {
			out[i] = *curr;
		}	
	}
	
	out[i] = 0;

	cxsl__conditionally_update_context(context, curr);

	return *curr ? 0 : i + 1;

	cxsl__size_only_label(cxsl__cstrcat):

	return cxsl__cstrlen(str1) + cxsl__cstrlen(str2);
}

size_t 		cxsl__cstrtok		(	const char* 	str 		, 
									const char* 	delimiters 	, 
									const char**	context 	,
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(delimiters != NULL, "Parameter delimiters cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	cxsl__conditionally_goto_size_only(cxsl__cstrtok, out);

	sz--;

	for (i = 0; sz && *st && !cxsl__cstrhas(delimiters, *st); --sz, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	if (cxsl__cstrhas(delimiters, *st)) {
		for (; *st && cxsl__cstrhas(delimiters, *st); ++st);	

		cxsl__conditionally_update_context(context, st);

		return i + 1;
	} else {
		cxsl__conditionally_update_context(context, st);

		return *st ? 0 : i + 1;
	}

	cxsl__size_only_label(cxsl__cstrtok):

	for (i = 0; *st && !cxsl__cstrhas(delimiters, *st); ++i, ++st);

	return i;
}

size_t 		cxsl__cstrtrm		(	const char* 	str 		,
									const char**	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t i;
	const char* st = cxsl__get_start(context, str);
	const char* ed = str + cxsl__cstrlen(str);

	for (; *st && (*st == ' ' || *st == '\t' || *st == '\r' || *st == '\n'); ++st);
	for (; ed != st && (*ed == ' ' || *ed == '\t' || *ed == '\r' || *ed == '\n' || *ed == '\0'); --ed) {
	}

	cxsl__conditionally_goto_size_only(cxsl__cstrtrm, out);		

	sz--;

	for (i = 0; sz && *st && st != (ed + 1); --sz, ++st, ++i) {
		out[i] = *st;
	}
	
	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return *st == 0 || st == ed + 1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__cstrtrm):

	printf("%c %c\n", *st, *ed);

	return *st || *ed ? (size_t) ed - (size_t) st + 1 : 0;
}

size_t 		cxsl__cstrsub 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									const char** 	context 	,
									char* 			out 		, 
									size_t 			sz 				) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t i;
	const char* st = cxsl__get_start(context, str + start_idx);

	if ((uintptr_t) st < (uintptr_t) (str + start_idx)) {
		st = str + start_idx;
	}

	cxsl__conditionally_goto_size_only(cxsl__csubstr, out);

	sz--;

	for (i = 0; sz && *st; --sz, ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return *st ? 0 : i + 1;

	cxsl__size_only_label(cxsl__csubstr):

	for (i = 0; *st; ++st, ++i);

	return i;

}

size_t 		cxsl__cstrsubi 		(	const char*		str 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 	, 
									const char**	context 	,
									char* 			out 		, 
									size_t 			sz 				) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(end_idx >= start_idx, "end_idx must be greater than or equal to start_idx");

	size_t i;
	const char* st = cxsl__get_start(context, str + start_idx);
	const char* ep1 = str + end_idx + 1;

	if ((uintptr_t) st < (uintptr_t) (str + start_idx)) {
		st = str + start_idx;
	}

	cxsl__conditionally_goto_size_only(cxsl__csubstr, out);

	sz--;

	for (i = 0; sz && *st && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return st == ep1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__csubstr):

	for (i = 0; *st && st != ep1; ++st, ++i);

	return i;

}

size_t 		cxsl__cstrsubn 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									size_t 			len 		, 
									const char**	context 	,
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t i;
	const char* st = cxsl__get_start(context, str + start_idx);
	const char* ep1 = str + start_idx + len;

	if ((uintptr_t) st < (uintptr_t) (str + start_idx)) {
		st = str + start_idx;
	}

	cxsl__conditionally_goto_size_only(cxsl__csubstr, out);

	sz--;

	for (i = 0; sz && *st && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return st == ep1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__csubstr):

	for (i = 0; *st && st != ep1; ++st, ++i);

	return i;
}

size_t 		cxsl__fstrlwr		(	const char* 	str 	, 
									char* 			out 		) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;

	for (i = 0; *str; ++str, ++i) {
		if (*str >= 'A' && *str <= 'Z') {
			out[i] = (*str - 'A') + 'a';	
		} else {
			out[i] = *str;	
		}
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrupr		(	const char* 	str 	, 
									char* 			out 		) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;

	for (i = 0; *str; ++str, ++i) {
		if (*str >= 'a' && *str <= 'z') {
			out[i] = (*str - 'a') + 'A';	
		} else {
			out[i] = *str;	
		}
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrrev		(	const char* 	str 	, 
									char* 			out 		)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	char* out_end = out + cxsl__cstrlen(str) - 1;

	for (i = 0; *str; --out_end, ++str, ++i) {
		*out_end = *str;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrcat		(	const char* 	str1 	, 
									const char*  	str2 	, 
									char* 			out 		) 
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;

	for (i = 0; *str1; ++i, ++str1) {
		out[i] = *str1;
	}

	for (i = 0; *str2; ++i, ++str2) {
		out[i] = *str2;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrtok		(	const char* 	str 		, 
									const char*  	delimiters 	, 
									const char** 	context 	, 
									char* 			out 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(delimiters != NULL, "Parameter delimiters cannot be NULL");
	cxsl__assert(context != NULL, "Parameter context cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	for (i = 0; *st && !cxsl__cstrhas(delimiters, *st); ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	for (; st && cxsl__cstrhas(delimiters, *st); ++st);

	*context = st;

	return i;
}

size_t 		cxsl__fstrtrm		(	const char* 	str 	, 
									char* 			out 		) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str;
	const char* ed = str + cxsl__cstrlen(str);

	for (; *st && (*st == ' ' || *st == '\t' || *st == '\r' || *st == '\n'); ++st);
	for (; ed != st && (*ed == ' ' || *ed == '\t' || *ed == '\r' || *ed == '\n' || *ed == '\0'); --ed);

	for (i = 0; *st && st != (ed + 1); ++st, ++i) {
		out[i] = *st;
	}
	
	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrsub 		(	const char* 	str 	 	, 
									size_t 			start_idx 	, 
									char* 			out 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str + start_idx;

	for (i = 0; *st; ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrsubi 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 	, 
									char* 			out 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(end_idx >= start_idx, "end_idx must be greater than or equal to start_idx");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str + start_idx;
	const char* ep1 = str + end_idx + 1;

	for (i = 0; *st && st != ep1; ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

size_t 		cxsl__fstrsubn 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									size_t  		len 		, 
									char*  			out 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str + start_idx;
	const char* ep1 = str + start_idx + len;

	for (i = 0; *st && st != ep1; ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	return i;
}

// length only functions

size_t 		cxsl__lstrlwr		(	const char* 	str 	) 
{
	return str ? cxsl__cstrlen(str) + 1 : 0;
}

size_t	 	cxsl__lstrupr		(	const char* 	str 	)
{
	return str ? cxsl__cstrlen(str) + 1 : 0;
}

size_t 		cxsl__lstrrev		(	const char* 	str 	)
{
	return str ? cxsl__cstrlen(str) + 1 : 0;
}

size_t 		cxsl__lstrcat		(	const char* 	str1 	, 
									const char* 	str2 		)
{
	return str1 && str2 ? cxsl__cstrlen(str1) + cxsl__cstrlen(str2) + 1 : 0;
}

size_t 		cxsl__lstrtok		(	const char* 	str 		, 
									const char* 	delimiters 	, 
									const char** 	context 		)
{
	if (str == NULL || delimiters == NULL) return 0;

	const char* st = cxsl__get_start(context, str);
	size_t i;


	for (i = 0; *st && !cxsl__cstrhas(delimiters, *st); ++i, ++st);

	return i + 1;
}

size_t 		cxsl__lstrtrm		(	const char* 	str 	)
{
	if (!str) return 0;

	const char* st = str;
	const char* ed = str + cxsl__cstrlen(str);

	for (; *st && (*st == ' ' || *st == '\t' || *st == '\r' || *st == '\n'); ++st);
	for (; ed != st && (*ed == ' ' || *ed == '\t' || *ed == '\r' || *ed == '\n' || *ed == '\0'); --ed);

	return (size_t) ed - (size_t) st + 2;
}

size_t 		cxsl__lstrsub 		(	const char* 	str 	, 
									size_t 			start_idx 	)
{
	if (!str) return 0;

	const char* st = str + start_idx;
	size_t i;

	for (i = 0; st; ++st, ++i);

	return i + 1;
}

size_t 		cxsl__lstrsubi 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 		)
{
	if (!str || start_idx > end_idx) return 0;

	const char* st = str + start_idx;
	const char* ep1 = str + end_idx + 1;
	size_t i;

	for (i = 0; st && st != ep1; ++st, ++i);

	return i + 1;
}

size_t 		cxsl__lstrsubn 		(	const char* 	str 		, 
									size_t 			start_idx 	, 
									size_t 			len 	 		)
{
	if (!str) return 0;

	const char* st = str + start_idx;
	const char* ep1 = st + len;
	size_t i;

	for (i = 0; st && st != ep1; ++st, ++i);

	return i + 1;
}

// bounded string function

uint8_t 	cxsl__nstrhas		(	const char*		str 	, 
									size_t  		len 	, 
									char  			ch 			) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	for (; len; ++str, --len) {
		if (*str == ch) {
			return 1;
		}
	}

	return 0;
}

int8_t		cxsl__nstrcmp		(	const char* 	str1 	, 
									size_t 			len1 	, 
									const char* 	str2 	, 
									size_t 			len2 		)
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");

	if (str1 == str2 && len1 == len2) {
		return 0;
	}

	for (; len1 && len2 && *str1 == *str2; ++str1, ++str2, --len1, --len2);

	if (len1 == 0 && len2 == 0) {
		return 0;
	} else if (len1 == 0) {
		return -1;
	} else if (len2 == 0) {
		return 1;
	} else {
		return *str1 < *str2 ? -1 : 1;
	}
}

size_t 		cxsl__nstrlwr		(	const char* 	str 		, 
									size_t 			len 		, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	cxsl__conditionally_goto_size_only(cxsl__nstrlwr, out);

	sz--;

	for (i = 0; sz && len; ++st, ++i, --sz, --len) {
		if (*st >= 'A' && *st <= 'Z') {
			out[i] = (*st - 'A') + 'a';	
		} else {
			out[i] = *st;	
		}
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return len ? 0 : i + 1;

	cxsl__size_only_label(cxsl__nstrlwr):
	
	return sz;
}

size_t 		cxsl__nstrupr		(	const char* 	str 		,
									size_t 			len 		, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	cxsl__conditionally_goto_size_only(cxsl__nstrupr, out);

	sz--;

	for (i = 0; sz && len; ++st, ++i, --sz, --len) {
		if (*st >= 'a' && *st <= 'z') {
			out[i] = (*st - 'a') + 'A';	
		} else {
			out[i] = *st;	
		}
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return len ? 0 : i + 1;

	cxsl__size_only_label(cxsl__nstrupr):
	
	return sz;
}

size_t 		cxsl__nstrrev		(	const char* 	str 		, 
									size_t 			len 		, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	
	size_t i;
	const char* sm1 = str - 1;
	const char* ed  = str + len - 1;

	ed = cxsl__get_start(context, ed);

	cxsl__conditionally_goto_size_only(cxsl__nstrrev, out);

	sz--;

	for (i = 0; sz && ed != sm1; --ed, --sz, ++i) {
		out[i] = *ed;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, ed);

	return ed != sm1 ? 0 : i + 1;

	cxsl__size_only_label(cxsl__nstrrev):

	return (size_t) ed - (size_t) sm1;
}

size_t 		cxsl__nstrcat		(	const char* 	str1 		, 
									size_t 			len1 		, 
									const char* 	str2 		, 
									size_t 			len2 		, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");

	cxsl__conditionally_goto_size_only(cxsl__nstrcat, out);

	char* curr;
	size_t i, len;

	i = 0;
	sz--;

	if (!context) goto cxsl__label(cxsl__nstrcat, skip_context);

	curr = (char*) *context;

	intptr_t diff1 = (intptr_t) curr - (intptr_t) str1;
	intptr_t diff2 = (intptr_t) curr - (intptr_t) str2;

	if (diff2 < 0 || diff1 < diff2) {
		len = len1;
		goto cxsl__label(cxsl__nstrcat, direct_str1);
	} else if (diff1 < 0 || diff2 < diff1) {
		len = len2;
		goto cxsl__label(cxsl__nstrcat, direct_str2);
	} else {
		cxsl__assert(0, "Reached unreachable code");
	}

	cxsl__label(cxsl__nstrcat, skip_context):

	curr = (char*) str1; 
	len = len1;

	cxsl__label(cxsl__nstrcat, direct_str1):

	for (; sz && len; --sz, ++curr, ++i, --len) {
		out[i] = *curr;
	}

	if (!len) {
		curr = (char*) str2;
		len = len2;

		cxsl__label(cxsl__nstrcat, direct_str2):

		for (; sz && len; --sz, ++curr, ++i, --len) {
			out[i] = *curr;
		}	
	}
	
	out[i] = 0;

	cxsl__conditionally_update_context(context, curr);

	return len ? 0 : i + 1;

	cxsl__size_only_label(cxsl__nstrcat):

	return len1 + len2;
}

size_t 		cxsl__nstrtok		(	const char* 	str 		, 
									size_t 			len 		, 
									const char* 	delimiters	, 
									size_t 			dlen 		, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(delimiters != NULL, "Parameter delimiters cannot be NULL");

	const char* st = cxsl__get_start(context, str);
	size_t i;

	cxsl__conditionally_goto_size_only(cxsl__cstrtok, out);

	sz--;

	for (i = 0; sz && len && !cxsl__cstrhas(delimiters, *st); --sz, ++i, ++st, --len) {
		out[i] = *st;
	}

	out[i] = 0;

	if (cxsl__cstrhas(delimiters, *st)) {
		for (; *st && cxsl__cstrhas(delimiters, *st); ++st);	

		cxsl__conditionally_update_context(context, st);

		return i + 1;
	} else {
		cxsl__conditionally_update_context(context, st);

		return len ? 0 : i + 1;
	}

	cxsl__size_only_label(cxsl__cstrtok):

	for (i = 0; *st && !cxsl__cstrhas(delimiters, *st); ++i, ++st);

	return i;
}

size_t 		cxsl__nstrtrm 		(	const char*		str 	, 
									size_t 			len 	, 
									const char** 	context , 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t i;
	const char* st = cxsl__get_start(context, str);
	const char* ed = str + len;

	for (; st != ed && (*st == ' ' || *st == '\t' || *st == '\r' || *st == '\n'); ++st);
	for (; ed != st && (*ed == ' ' || *ed == '\t' || *ed == '\r' || *ed == '\n' || *ed == '\0'); --ed);

	cxsl__conditionally_goto_size_only(cxsl__nstrtrm, out);		

	sz--;

	for (i = 0; sz && st != (ed + 1); --len, --sz, ++st, ++i) {
		out[i] = *st;
	}
	
	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return len || st == ed + 1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__nstrtrm):

	return st == str + len ? 0 : (size_t) ed - (size_t) st + 1;
}

size_t 		cxsl__nsubstr 		(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t i;
	const size_t sidx = cxsl__min(start_idx, len);
	const char* st = cxsl__get_start(context, str + start_idx);
	const char* ep1 = str + len;

	if ((uintptr_t) st < (uintptr_t) (str + start_idx)) {
		st = str + start_idx;
	}

	cxsl__conditionally_goto_size_only(cxsl__nsubstr, out);

	sz--;

	for (i = 0; sz && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return st == ep1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__nsubstr):

	return len - sidx;
}

size_t 		cxsl__nsubstri 		(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 	, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(end_idx >= start_idx, "end_idx must be greater than or equal to start_idx");

	size_t i;
	const size_t sidx = cxsl__min(start_idx, len);
	const size_t eidx = cxsl__min(end_idx, len - 1);
	const char* st = cxsl__get_start(context, str + sidx);
	const char* ep1 = str + eidx + 1;

	if ((uintptr_t) st < (uintptr_t) (str + sidx)) {
		st = str + sidx;
	}

	cxsl__conditionally_goto_size_only(cxsl__nsubstri, out);

	sz--;

	for (i = 0; sz && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return st == ep1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__nsubstri):

	return eidx - sidx + 1;
}

size_t 		cxsl__nsubstrn 		(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									size_t 			l 			, 
									const char** 	context 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	size_t i;
	const size_t sidx = cxsl__min(start_idx, len - 1);
	const size_t eidx = cxsl__min(sidx + l - 1, len - 1);
	const char* st = cxsl__get_start(context, str + sidx);
	const char* ep1 = str + eidx + 1;

	if ((uintptr_t) st < (uintptr_t) (str + sidx)) {
		st = str + sidx;
	}

	cxsl__conditionally_goto_size_only(cxsl__nsubstrn, out);

	sz--;

	for (i = 0; sz && *st && st != ep1; --sz, ++st, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	cxsl__conditionally_update_context(context, st);

	return st == ep1 ? i + 1 : 0;

	cxsl__size_only_label(cxsl__nsubstrn):

	return eidx - sidx + 1;
}

size_t 		cxsl__fnstrlwr		(	const char* 	str 	, 
									size_t 			len 	, 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;

	for (i = 0; len; ++str, --len, ++i) {
		if (*str >= 'A' && *str <= 'Z') {
			out[i] = (*str - 'A') + 'a';
		}
		out[i] = *str;
	}

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__fnstrupr		(	const char* 	str 	, 
									size_t 			len 	, 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;

	for (i = 0; len; ++str, --len, ++i) {
		if (*str >= 'a' && *str <= 'a') {
			out[i] = (*str - 'a') + 'A';
		}
		out[i] = *str;
	}

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__fnstrrev		(	const char* 	str 	, 
									size_t 			len 	, 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* ed = str + len - 1;

	for (i = 0; len; --ed, --len, ++i) {
		out[i] = *str;
	}

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__fnstrcat		(	const char* 	str1 	, 
									size_t 			len1 	, 
									const char* 	str2 	, 
									size_t 			len2 	, 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");	

	size_t i;

	for (i = 0; len1; --len1, ++i, ++str1) {
		out[i] = *str1;
	}

	for (; len2; --len2, ++i, ++str2) {
		out[i] = *str2;
	}

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__fnstrtok		(	const char* 	str 		, 
									size_t 			len 		, 
									const char* 	delimiters 	, 
									size_t 			dlen 		, 
									const char**	context 	,
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(delimiters != NULL, "Parameter delimiters cannot be NULL");
	cxsl__assert(context != NULL, "Parameter context cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = cxsl__get_start(context, str);

	for (i = 0; len && !cxsl__nstrhas(delimiters, dlen, *st); --len, ++i, ++st) {
		out[i] = *st;
	}

	out[i] = 0;

	for (; len && cxsl__nstrhas(delimiters, dlen, *st); --len, ++st);

	*context = st;

	return i + 1;
}

size_t 		cxsl__fntrim		(	const char* 	str 	, 
									size_t 			len 	, 
									char* 			out 	, 
									size_t 			sz 			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str;
	const char* ed = str + len;

	for (; *st && (*st == ' ' || *st == '\t' || *st == '\r' || *st == '\n'); ++st, --len);
	for (; ed != st && (*ed == ' ' || *ed == '\t' || *ed == '\r' || *ed == '\n' || *ed == '\0'); --ed, --len);

	for (i = 0; len, st != (ed + 1); ++st, ++i, --len) {
		out[i] = *st;
	}

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__fnstrsub 		(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str + start_idx;
	len -= start_idx;


	for (i = 0; len; ++st, --len, ++i) {
		out[i] = *st;
	}	

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__fnsubstri 	(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 	, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str + start_idx;
	const char* ep1 = str + end_idx + 1;

	len -= start_idx;

	for (i = 0; len && st != ep1; ++st, --len, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	return i + 1;	
}

size_t 		cxsl__fnsubstrn 	(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									size_t 			l 			, 
									char* 			out 		, 
									size_t 			sz 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(out != NULL, "Parameter out cannot be NULL");

	size_t i;
	const char* st = str + start_idx;
	const char* ep1 = str + start_idx + len;

	len -= start_idx;

	for (i = 0; len && st != ep1; ++st, --len, ++i) {
		out[i] = *st;
	}

	out[i] = 0;

	return i + 1;
}

size_t 		cxsl__lnstrlwr		(	const char* 	str 	, 
									size_t 			len 		) 
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	return len + 1;
}

size_t 		cxsl__lnstrupr		(	const char* 	str 	, 
									size_t 			len 		)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	return len + 1;	
}

size_t 		cxsl__lnstrrev		(	const char* 	str 	, 
									size_t 			len 		)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	return len + 1;	
}

size_t 		cxsl__lnstrcat		(	const char* 	str1 	, 
									size_t 			len1	,
									const char* 	str2 	, 
									size_t 			len2		)
{
	cxsl__assert(str1 != NULL, "Parameter str1 cannot be NULL");
	cxsl__assert(str2 != NULL, "Parameter str2 cannot be NULL");

	return len1 + len2 + 1;	
}

size_t 		cxsl__lnstrtok		(	const char* 	str 		, 
									size_t 			len 		, 
									const char* 	delimiters 	, 
									size_t 			dlen 		,
									const char**	context			)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");
	cxsl__assert(context != NULL, "Parameter context cannot be NULL");
	cxsl__assert(delimiters != NULL, "Parameter delimiters cannot be NULL");	

	const char* st = cxsl__get_start(context, str);
	size_t i;

	for (i = 0; len && !cxsl__nstrhas(delimiters, dlen, *st); --len, ++i, ++st);

	return i + 1;
}

size_t 		cxsl__lntrim		(const char* str, size_t len)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	const char* st = str;
	const char* ed = str + len;

	for (; *st && (*st == ' ' || *st == '\t' || *st == '\r' || *st == '\n'); ++st);
	for (; ed != st && (*ed == ' ' || *ed == '\t' || *ed == '\r' || *ed == '\n' || *ed == '\0'); --ed);

	return (size_t) ed - (size_t) st + 2;
}

size_t 		cxsl__lnsubstr 		(	const char* 	str 	 	, 
									size_t 			len 		, 
									size_t 			start_idx 		)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	return start_idx >= len ? 0 : len - start_idx;
}	

size_t 		cxsl__lnsubstri 	(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									size_t 			end_idx 		)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	return start_idx >= len ? 0 : end_idx >= len ? len - start_idx : end_idx - start_idx + 1;	
}	

size_t 		cxsl__lnsubstrn 	(	const char* 	str 		, 
									size_t 			len 		, 
									size_t 			start_idx 	, 
									size_t 			l 				)
{
	cxsl__assert(str != NULL, "Parameter str cannot be NULL");

	return start_idx >= len ? 0 : start_idx + l >= len ? len - start_idx : l;
}

#endif