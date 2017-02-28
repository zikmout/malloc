#include "libft/libft.h"
#include "includes/malloc.h"

t_zone		*init_ts(void) {

	void	*ptr;
	t_head	*head;
	t_zone	*zone;

	head = NULL;
	ptr = mmap(NULL, TZMAX_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	zone = ptr;

	head = ptr + sizeof(*g_e.tiny);
	head->addr = head + sizeof(*head);
	head->empty = 1;
	head->size = TZMAX_SIZE;
	head->next = NULL;

	zone->entry = head;
	zone->zleft = TZMAX_SIZE;
	zone->next = NULL;

	return zone;
}

void		*malloc(size_t size) {

	printf("MALLOC SIZE -> %zu\n", size);
	return NULL;
}

void		print_zone(t_zone *begin) {

	t_zone *zhead;
	t_head *cur;
	size_t nb;

	nb = 0;
	zhead = begin;
	while (zhead) {
		printf("---> Zone %zu\n", nb);
		printf("zone itself => %p\n", zhead);
		printf("zone->entry => %p\n", zhead->entry);
		printf("zone->zleft => %zu\n", zhead->zleft);
		printf("zone->next => %p\n\n", zhead->next);

		cur = zhead->entry;
		while (cur) {
			printf("     cur itself => %p\n", cur);
			printf("     cur->addr => %p\n", cur->addr);
			printf("     cur->empty => %d\n", cur->empty);
			printf("     cur->size => %zu\n", cur->size);
			printf("     cur->next => %p\n", cur->next);
			cur = cur->next;
		}
		zhead = zhead->next;
	}
}
