#include <malloc.h>
#include <stdio.h>
#include <string.h>

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

#ifdef T4
void t4() {
	const char* str = pstr_new("Hello World", &my_malloc, NULL);

	printf("%s: %zd\n", str, pstr_len(str));

	pstr_for(s, str) {
		printf("%c ", *s);
	}

	printf("\n");
	
	pstr_free(str, &my_free, NULL);
}
#endif


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
	t2_1();
	printf("\n--------------------------------\n");
	t2_2();
	printf("\n--------------------------------\n");
	t5_1();


}