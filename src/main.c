#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CXSL_MEM_IMPLEMENTATION
#define CXSL_STR_IMPLEMENTATION
#include "mem.h"
#include "str.h"

void* my_malloc(size_t sz, void* user) {
	printf("my_malloc\n");
	return malloc(sz);
}

void* my_realloc(void* ptr, size_t sz, void* user) {
	printf("my_realloc\n");
	return realloc(ptr, sz);
}

void my_free(void* ptr, void* user) {
	printf("my_free\n");
	free(ptr);
}

#if 0
#define CXSL_PSTR_MALLOC(sz, user) my_malloc(sz, user)
#define CXSL_PSTR_REALLOC(ptr, sz, user) my_realloc(ptr, sz, user)
#define CXSL_PSTR_FREE(ptr, user) my_free(ptr, user)

#define CXSL_PSTRB_MALLOC(sz, user) my_malloc(sz, user)
#define CXSL_PSTRB_REALLOC(ptr, sz, user) my_realloc(ptr, sz, user)
#define CXSL_PSTRB_FREE(ptr, user) my_free(ptr, user)

#define CXSL_NSTR_MALLOC(sz, user) my_malloc(sz, user)
#define CXSL_NSTR_REALLOC(ptr, sz, user) my_realloc(ptr, sz, user)
#define CXSL_NSTR_FREE(ptr, user) my_free(ptr, user)
#else
#define CXSL_MALLOC(sz, user) my_malloc(sz, user)
#define CXSL_REALLOC(ptr, sz, user) my_realloc(ptr, sz, user)
#define CXSL_FREE(ptr, user) my_free(ptr, user)
#endif

#define NSTR_EXTRA_BYTES 24
#define CXSL_NSTR_IMPLEMENTATION
#include "nstr.h"

#define CXSL_PSTRB_IMPLEMENTATION
#include "pstrb.h"

#define CXSL_PSTR_IMPLEMENTATION
#include "pstr.h"

int8_t t1_helper(const char* s1, const char* s2) {
	return cxsl__bstrcmp(s1, s1 + cxsl__cstrlen(s1), s2, s2 + cxsl__cstrlen(s2));
}

void t1() {
	const char* s1 = "Hello";
	const char* s2 = "Hello";
	const char* s3 = "Anything";
	const char* s4 = "Hellz Kitchen";
	const char* s5 = "Hello World";
	const char* s6 = "Hell";

	printf("%d\n%d\n%d\n%d\n%d\n",
			t1_helper(s1, s2),
			t1_helper(s1, s3),
			t1_helper(s1, s4),
			t1_helper(s1, s5),
			t1_helper(s1, s6));

}


void t2_1() {
	nstr_t str1 = nstr_new("Hello", NULL);
	nstr_t str2 = nstr_new(" World This is a large string", NULL);

	printf("%s\n%s\n\n", nstr_tostr(&str1), nstr_tostr(&str2));

	nstr_t str3 = nstr_ofsize(nstr_size(&str1) + nstr_size(&str2), NULL);

	strcpy((char*) nstr_begin(&str3), nstr_begin(&str1));
	strcat((char*) nstr_begin(&str3), nstr_begin(&str2));

	printf("%s\n", nstr_tostr(&str3));

	nstr_delete(&str1, NULL);
	nstr_delete(&str2, NULL);
	nstr_delete(&str3, NULL);
}

void t2_2() {
	nstr_t str1 = nstr_move("Hello");
	nstr_t str2 = nstr_move(" World This is a large string");

	printf("%s\n%s\n\n", nstr_tostr(&str1), nstr_tostr(&str2));

	nstr_t str3 = nstr_ofsize(nstr_size(&str1) + nstr_size(&str2), NULL);

	strcpy((char*) nstr_begin(&str3), nstr_begin(&str1));
	strcat((char*) nstr_begin(&str3), nstr_begin(&str2));

	printf("%s\n", nstr_tostr(&str3));

	nstr_delete(&str3, NULL);
}

void t3() {
	char* s1 = pstrb_new("", NULL);
	char* s2 = pstrb_new("", NULL);

	printf("s1 ['%s'] == s2 ['%s'] : %d\n", s1, s2, s1 == s2);

	s1 = pstrb_concat_cstr(s1, "Hello", NULL);
	s2 = pstrb_concat_cstr(s2, " World!", NULL);

	printf("s1 ['%s'] == s2 ['%s'] : %d\n", s1, s2, s1 == s2);	

	s1 = pstrb_concat_cstr(s1, s2, NULL);

	printf("s1 ['%s'] == s2 ['%s'] : %d\n", s1, s2, s1 == s2);	
}

void t4() {
	const char* str = "Hello World thiis";
	// const char* str = "";
	const char* context = str;

	char buff[16];

	intptr_t sz = cxsl_cstrlwr(str, NULL, NULL, 0), rm;

	printf("%Id\n", sz);

	// for (;;) {
	// 	sz = cxsl__cstrlwr(str, &context, buff, 16);
	// 	rm = cxsl__cstrlwr(str, &context, NULL, 0);
	// 	printf("%s [%zd, %zd]\n", buff, cxsl__outstrsz(sz, 16), rm);

	// 	if (sz) break;
	// } 

	// while (sz = cxsl__cstrlwr(str, &context, buff, 16), !sz) {
	// 	printf("%s [%zd]\n", buff, sz);
	// }
	// printf("%s [%zd]\n", buff, sz);

	do {
		sz = cxsl__cstrlwr(str, &context, buff, 16);
		rm = cxsl__cstrlwr(str, &context, NULL, 0);
		printf("%s [%zd, %zd]\n", buff, cxsl__outstrsz(sz, 16), rm);

	} while (!sz);

	printf("\n------------------------\n");

	context = str + strlen(str) - 1;

	do {
		sz = cxsl__cstrrev(str, &context, buff, 16);
		rm = cxsl__cstrrev(str, &context, NULL, 0);
		printf("%s [%zd, %zd]\n", buff, cxsl__outstrsz(sz, 16), rm);

	} while (!sz);

	printf("\n------------------------\n");

	const char* str1 = "Hello World this is the first string";
	const char* str2 = " Hello World this is the second string";

	context = str1;

	sz = cxsl_cstrcat(str1, str2, NULL, NULL, 0);

	printf("[%zd]\n------------\n", sz);

	do {
		sz = cxsl_cstrcat(str1, str2, &context, buff, 16);

		printf("%s [%zd]\n", buff, sz);

	} while (!sz);
}


void t5_1() {
	const char* astr = "Suhaib Khan the programming morgan something";
	size_t astr_sz = strlen(astr);

	char* str = pstrb_new("Hello ", NULL);

	printf("%s, %zd, %zd\n", str, pstrb_len(str), pstrb_cap(str));

	str = pstrb_concat_cstr(str, "World!", NULL);

	printf("%s, %zd, %zd\n", str, pstrb_len(str), pstrb_cap(str));

	str = pstrb_concat(str, astr, astr + astr_sz, NULL);

	printf("%s, %zd, %zd\n", str, pstrb_len(str), pstrb_cap(str));

	pstrb_delete(str, NULL);
}


int main(int argc, char** argv) {
	t1();
	printf("\n--------------------------------\n");
	t2_1();
	printf("\n--------------------------------\n");
	t2_2();
	printf("\n--------------------------------\n");
	t5_1();
	printf("\n--------------------------------\n");
	t3();
	printf("\n--------------------------------\n");
	t4();

}