#include "libft/libft.h"
#include "includes/malloc.h"
//void free(void *ptr);
//void *malloc(size_t size);
//void *realloc(void *ptr, ize_t size);

int main(void) {

	init_ts(&g_e.tiny, TZMAX_SIZE);
	init_ts(&g_e.small, SZMAX_SIZE);
	printf("g_e.tiny->addr => %p\n", g_e.tiny);
	printf("g_e.small->addr => %p\n", g_e.small);
	//printf("initial zone->zleft => %zu\n", g_e.tiny->zleft);

	//malloc(4000);
	//malloc(2000);
	//printf("malloc de 2000 return ======>>> %p\n", malloc(2000));
	//printf("malloc de 96 return ======>>> %p\n", malloc(96));

	void *rea1 = NULL;
	void *rea2 = NULL;
	//void *ptr = NULL;

	malloc(4000);
	rea1 = malloc(4000);
	rea2 = malloc(40);
	malloc(1);
	//rea = malloc(40);

	free(rea1);
	free(rea2);

	//ptr = malloc(3900);

	//rea = realloc(ptr, 4001);

	//free(rea);
	//print_zone(g_e.tiny);

	//malloc(3333);
	//malloc(4002);

	print_zone(g_e.tiny);
	//print_zone(g_e.small);
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
