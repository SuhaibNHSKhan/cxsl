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
#define cxsl__cstrcat		CXSL__DEC(cstrcat)
#define cxsl__cstrtok		CXSL__DEC(cstrtok)
#define cxsl__cstrtrm		CXSL__DEC(cstrtrm)
#define cxsl__cstrsub		CXSL__DEC(cstrsub)
#define cxsl__cstrsubi		CXSL__DEC(cstrsubi)
#define cxsl__cstrsubn		CXSL__DEC(cstrsubn)
#define cxsl__cstrlwr		CXSL__DEC(cstrlwr)
#define cxsl__cstrupr		CXSL__DEC(cstrupr)
#define cxsl__cstrrev		CXSL__DEC(cstrrev)

#define cxsl__fstrlwr		CXSL__DEC(fstrlwr)
#define cxsl__fstrupr		CXSL__DEC(fstrupr)
#define cxsl__fstrrev		CXSL__DEC(fstrrev)
#define cxsl__fstrcat		CXSL__DEC(fstrcat)
#define cxsl__fstrtok		CXSL__DEC(fstrtok)
#define cxsl__fstrtrm		CXSL__DEC(fstrtrm)
#define cxsl__fstrsub		CXSL__DEC(fstrsub)
#define cxsl__fstrsubi		CXSL__DEC(fstrsubi)
#define cxsl__fstrsubn		CXSL__DEC(fstrsubn)

#define cxsl__lstrlwr		CXSL__DEC(lstrlwr)
#define cxsl__lstrupr		CXSL__DEC(lstrupr)
#define cxsl__lstrrev		CXSL__DEC(lstrrev)
#define cxsl__lstrcat		CXSL__DEC(lstrcat)
#define cxsl__lstrtok		CXSL__DEC(lstrtok)
#define cxsl__lstrtrm		CXSL__DEC(lstrtrm)
#define cxsl__lstrsub		CXSL__DEC(lstrsub)
#define cxsl__lstrsubi		CXSL__DEC(lstrsubi)
#define cxsl__lstrsubn		CXSL__DEC(lstrsubn)

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

#define cxsl__conditionally_update_context(context, value) if (*(context)) *(context) = value
#define cxsl__get_start(context, start) (context) ? *(context) : (start)

#define cxsl__label_internal(func, label) func##_##label
#define cxsl__label(func, label) cxsl__label_internal(func, label)
#define cxsl__size_only_label(func) cxsl__label(func, size_only)
#define cxsl__conditionally_goto_size_only(func, out) if (!out) goto cxsl__size_only_label(func)

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
	
	return (intptr_t) cxsl__cstrlen(st);
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
	
	return (intptr_t) cxsl__cstrlen(st);
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
	char* out_end = out + strlen(str) - 1;

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

	if (*context == NULL) {
		*context = str;
	}

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