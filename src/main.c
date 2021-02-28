#include <malloc.h>
#include <stdio.h>

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

#define GPUL_MALLOC(sz, user) my_malloc(sz, user)
#define GPUL_REALLOC(ptr, sz, user) my_realloc(ptr, sz, user)
#define GPUL_FREE(ptr, user) my_free(ptr, user)

#define PSTRB_DEC(name) mystr_##name
#define PSTRB_IMPLEMENTATION
#include "pstrb.h"
#undef PSTRB_DEC


#undef PSTRB_H
#define PSTRB_DEC(name) custom_##name
#define PSTRB_IMPLEMENTATION
#include "pstrb.h"
#undef PSTRB_DEC

#define NSTR_IMPLEMENTATION
#include "nstr.h"

#define T2
#define T5
#define T6

#ifdef T1
void t1() {
	const char* pstr = "   ABC  \n1, 23 \n 45  ,  6 ,   ,5    ,     8";

	char buff[256];

	char* str = &buff[0];

	gpul_substri(pstr, pstr + gpul_strlen(pstr), 4, 17, str);

	size_t sz1, sz2;
	char buff1[256];
	char buff2[256];
	char buff3[256];

	const char* s = str;
	const char* ep = str + gpul_strlen(str);


	while (sz1 = gpul_strtok(&s, ep, "\n", &buff1[0])) {
		const char* in = &buff1[0];
		const char* inp1 = in + sz1;

		while (sz2 = gpul_strtok(&in, inp1, ",", &buff2[0])) {	
			const char* s1 = &buff2[0];
			const char* ep1 = s1 + sz2;
			gpul_trim(s1, ep1, &buff3[0]);
			printf("|%s| ", &buff3[0]);	
		}
		printf("\n");
	}

}
#endif

#ifdef T2
void t2_1() {
	nstr_t str1 = nstr_new("Hello", NULL);
	nstr_t str2 = nstr_new(" World This is a large string", NULL);

	printf("%s\n%s\n\n", nstr_tostr(&str1), nstr_tostr(&str2));

	nstr_t str3 = nstr_ofsize(nstr_size(&str1) + nstr_size(&str2), NULL);

	gpul_concat(nstr_begin(&str1), nstr_endp1(&str1), nstr_begin(&str2), nstr_endp1(&str2), (char*) nstr_data(&str3));

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

	gpul_concat(nstr_begin(&str1), nstr_endp1(&str1), nstr_begin(&str2), nstr_endp1(&str2), (char*) nstr_data(&str3));

	printf("%s\n", nstr_tostr(&str3));

	nstr_delete(&str3, NULL);
}
#endif

#ifdef T3
#include <string.h>

#define SZ 10000000

void t3() {
	double base, elapsed;
	volatile size_t size;
	shl_time_init();
	// t2();

	char* str = malloc(SZ + 1);
	str[SZ] = 0;

	for (size_t sz = 0; sz < SZ; sz++) {
		str[sz] = 'a' + sz % 26;
	}

	base = shl_get_base_time();
	for (int i = 0; i < 100; i++) {
		size = gpul_strlen(str);	
	}
	elapsed = shl_get_elapsed_time(base);

	printf("slow: %lf, size: %zd\n", elapsed, size);

	base = shl_get_base_time();
	for (int i = 0; i < 100; i++) {
		size = strlen(str);	
	}
	elapsed = shl_get_elapsed_time(base);

	printf("base: %lf, size: %zd\n", elapsed, size);

	base = shl_get_base_time();
	for (int i = 0; i < 100; i++) {
		size = gpul_strlen_fast(str);	
	}
	elapsed = shl_get_elapsed_time(base);

	printf("fast: %lf, size: %zd\n", elapsed, size);
	
	return 0;
}
#endif

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

#ifdef T5
void t5_1() {
	const char* astr = "Suhaib Khan the programming morgan something";
	size_t astr_sz = gpul_strlen(astr);

	char* str = mystr_new("Hello ", NULL);

	printf("%s, %zd, %zd\n", str, mystr_len(str), mystr_cap(str));

	str = mystr_concat_cstr(str, "World!", NULL);

	printf("%s, %zd, %zd\n", str, mystr_len(str), mystr_cap(str));

	str = mystr_concat(str, astr, astr + astr_sz, NULL);

	printf("%s, %zd, %zd\n", str, mystr_len(str), mystr_cap(str));

	mystr_delete(str, NULL);
}

void t5_2() {
	const char* astr = "Suhaib Khan the programming morgan something";
	size_t astr_sz = gpul_strlen(astr);

	char* str = custom_new("Hello ", NULL);

	printf("%s, %zd, %zd\n", str, custom_len(str), custom_cap(str));

	str = custom_concat_cstr(str, "World!", NULL);

	printf("%s, %zd, %zd\n", str, custom_len(str), custom_cap(str));

	str = custom_concat(str, astr, astr + astr_sz, NULL);

	printf("%s, %zd, %zd\n", str, custom_len(str), custom_cap(str));

	custom_delete(str, NULL);
}

#endif

#ifdef T6
#include "nstrb.h"

void t6() {
	ostr s1 = ostr_new("Hello World");
	ostr s2 = ostr_new("1234567890123456789012");
	ostr s3 = ostr_new("12345678901234567890123");
	ostr s4 = ostr_new("This is the biggest string anyone has ever created");

	printf("%zd %zd %zd %zd\n", get_size(s1), get_size(s2), get_size(s3), get_size(s4));

}
#endif

int main(int argc, char** argv) {
	t2_1();
	t2_2();
}