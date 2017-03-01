#include "libft/libft.h"
#include "includes/malloc.h"
//void free(void *ptr);
//void *malloc(size_t size);
//void *realloc(void *ptr, ize_t size);

int main(void) {

	init_ts(&g_e.tiny, TZMAX_SIZE);
	init_ts(&g_e.small, SZMAX_SIZE);
	printf("g_e.tiny->addr => %p\n", g_e.tiny);
	//printf("initial zone->zleft => %zu\n", g_e.tiny->zleft);

	//malloc(4000);
	//malloc(2000);
	//printf("malloc de 2000 return ======>>> %p\n", malloc(2000));
	//printf("malloc de 96 return ======>>> %p\n", malloc(96));
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
	return 0;
}
