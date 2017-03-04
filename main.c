#include "libft/libft.h"
#include "includes/malloc.h"
#include "ft_printf/includes/printf.h"
//void free(void *ptr);
//void *malloc(size_t size);
//void *realloc(void *ptr, ize_t size);

int main(void) {

	//ft_printf("Ttransaction\n");
	//ft_printf("Ttransaction\n");
	//ft_printf("Ttransaction\n");
	//ft_printf("Ttranstctio %d\n", 58);


/*
	void *rea1 = NULL;
	void *rea2 = NULL;
	void *rea3 = NULL;
	void *rea4 = NULL;
	void *rea5 = NULL;
	void *rea6 = NULL;
	void *rea7 = NULL;
	void *rea8 = NULL;
	void *rea9 = NULL;
	void *rea10 = NULL;
	void *rea11 = NULL;
	void *rea12 = NULL;
	void *rea13 = NULL;
	void *rea14 = NULL;
	void *rea15 = NULL;
	void *rea16 = NULL;
	void *rea17 = NULL;
	void *rea18 = NULL;
	void *rea19 = NULL;
	void *rea20 = NULL;
	void *rea21 = NULL;
	void *rea22 = NULL;
	void *rea23 = NULL;
	void *rea24 = NULL;
	void *rea25 = NULL;

	rea1 = malloc(128);
	rea2 = malloc(320);
	rea3 = malloc(320);
	rea4 = malloc(320);
	rea5 = malloc(320);
	rea6 = malloc(320);
	rea7 = malloc(320);
	rea8 = malloc(320);
	rea9 = malloc(320);
	rea10 = malloc(320);
	rea11 = malloc(320);
	rea12 = malloc(320);
	rea13 = malloc(320);
	rea14 = malloc(320);
	rea15 = malloc(320);
	rea16 = malloc(320);
	rea17 = malloc(256);
	rea18 = malloc(256);
	rea19 = malloc(256);
	rea20 = malloc(256);
	rea21 = malloc(256);
	rea22 = malloc(256);
	rea23 = malloc(256);
	rea24 = malloc(256);
	rea25 = malloc(256);

	free(rea1);
	free(rea2);
	free(rea3);
	free(rea4);
	free(rea5);
	free(rea6);
	free(rea7);
	free(rea8);
	free(rea9);
	free(rea10);
	free(rea11);
	free(rea12);
	free(rea13);
	free(rea14);
	free(rea15);
	free(rea16);
	free(rea17);
	free(rea18);
	free(rea19);
	free(rea20);
	free(rea21);
	free(rea22);
	free(rea23);
	free(rea24);
	free(rea25);
	show_alloc_mem();

*/
	//rea1 = malloc(1000000);
	//rea2 = malloc(1100000);
	//rea3 = malloc(1200000);
	//free(rea3);
	//rea3 = malloc(90000);
	//rea4 = malloc(130000);

	//free(rea2);
	//free(rea3);
	//realloc(rea1, 1800);
	//free(rea4);
	//ptr = malloc(3900);
	//rea3 = malloc(90000);
	//free(rea3);


	//rea = realloc(ptr, 4001);

	//free(rea);

	//print_zone(g_e.tiny);
	//print_zone(g_e.small);
	//print_large(g_e.large);


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
