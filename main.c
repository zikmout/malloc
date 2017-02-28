#include "libft/libft.h"
#include "includes/malloc.h"
//void free(void *ptr);
//void *malloc(size_t size);
//void *realloc(void *ptr, ize_t size);

int main(void) {

	init_ts(&g_e.tiny, TZMAX_SIZE);
	printf("g_e.tiny->addr => %p\n", g_e.tiny);
	printf("initial zone->zleft => %zu\n", g_e.tiny->zleft);

	malloc(4000);
	malloc(2000);
	printf("malloc de 2000 return ======>>> %p\n", malloc(2000));
	printf("malloc de 96 return ======>>> %p\n", malloc(96));
	print_zone(g_e.tiny);
	return 0;
}
