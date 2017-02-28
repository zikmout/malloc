#include "libft/libft.h"
#include "includes/malloc.h"
//void free(void *ptr);
//void *malloc(size_t size);
//void *realloc(void *ptr, ize_t size);

int main(void) {

	g_e.tiny = init_ts();
	g_e.small = init_ts();
	printf("g_e.tiny->addr => %p\n", g_e.tiny);
	printf("g_e.small->addr => %p\n", g_e.small);
	malloc(4000);
	print_zone(g_e.tiny);
	print_zone(g_e.small);
	return 0;
}
