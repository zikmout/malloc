#include "libft/libft.h"
#include "includes/malloc.h"
//void free(void *ptr);
//void *malloc(size_t size);
//void *realloc(void *ptr, ize_t size);

int main(void) {


	void *rea1 = NULL;
	void *rea2 = NULL;
	void *rea3 = NULL;
	//void *rea4 = NULL;

	rea1 = malloc(1000000);
	rea2 = malloc(1100000);
	rea3 = malloc(1200000);
	//free(rea3);
	//rea3 = malloc(90000);
	//rea4 = malloc(130000);

	//free(rea2);
	//free(rea3);
	realloc(rea1, 1800);
	//free(rea4);
	//ptr = malloc(3900);
	//rea3 = malloc(90000);
	//free(rea3);

	//malloc(150000);

	//rea = realloc(ptr, 4001);

	//free(rea);

	print_zone(g_e.tiny);
	print_zone(g_e.small);
	print_large(g_e.large);


	/* ---- LARGE TESTING MALLOC & FREE

	void *rea1 = NULL;
	void *rea2 = NULL;
	void *rea3 = NULL;
	//void *rea4 = NULL;

	rea1 = malloc(1000000);
	rea2 = malloc(1100000);
	rea3 = malloc(1200000);
	//free(rea3);
	//rea3 = malloc(90000);
	//rea4 = malloc(130000);

	free(rea1);
	free(rea2);
	free(rea3);
	//free(rea4);
	//ptr = malloc(3900);
	//rea3 = malloc(90000);
	//free(rea3);

	//malloc(150000);

	//rea = realloc(ptr, 4001);

	//free(rea);

	print_zone(g_e.tiny);
	print_zone(g_e.small);
	print_large(g_e.large);

	*/


	/* ---- SMALL TESTING MALLOC & FREE

	void *rea1 = NULL;
	void *rea2 = NULL;
	void *rea3 = NULL;
	void *rea4 = NULL;

	rea1 = malloc(100000);
	rea2 = malloc(110000);
	rea3 = malloc(120000);
	//free(rea3);
	//rea3 = malloc(90000);
	rea4 = malloc(130000);

	free(rea1);
	free(rea2);
	free(rea3);
	//free(rea4);
	//ptr = malloc(3900);
	//rea3 = malloc(90000);
	//free(rea3);

	//malloc(150000);

	//rea = realloc(ptr, 4001);

	//free(rea);

	print_zone(g_e.tiny);
	print_zone(g_e.small);
	print_large(g_e.large);

	*/

	//malloc(3333);
	//malloc(4002);
	//print_zone(g_e.small);
	//g_e.tiny = NULL;
	/* TEST LOCATE FUNCTION
	void *ptrl;
	void *ptrs;
	void *ptrt;

	ptrl = malloc(150000);
	ptrs = malloc(5000);
	ptrt = malloc(400);

	t_zone *test;
	test = NULL;

	printf("PTR Large = %p\n", ptrl);


	printf("PTR Small = %p\n", ptrs);
	printf("PTR Small locate size = %zu\n", ((t_head *)(locate(g_e.small, &test, ptrs)))->size);
	printf("PTR Small locate zone = %p\n", test);


	printf("PTR Tiny = %p\n", ptrt);
	printf("PTR Tiny locate size = %zu\n", ((t_head *)(locate(g_e.tiny, &test, ptrt)))->size);
	printf("PTR Tiny locate zone = %p\n", test);


	print_large(g_e.large);
	print_zone(g_e.small);
	print_zone(g_e.tiny);
	*/

	/*
	void *ptr = NULL;

	ptr = malloc(50);
	malloc(40);
	malloc(30);
	malloc(20);
	malloc(10);

	free(ptr);
	malloc(3);
	malloc(3);

	malloc(150000);
	malloc(150000);
	ptr = malloc(160000);
	malloc(150000);
	free(ptr);
	printf("PTR = %p\n", ptr);
	//malloc(150000);
	//print_zone(g_e.tiny);
	//malloc(133333);


	//printf("g_e.large->addr => %p\n", g_e.large);
	print_large(g_e.large);
	//print_zone(g_e.small);
	print_zone(g_e.tiny);
	*/
	return 0;
}
