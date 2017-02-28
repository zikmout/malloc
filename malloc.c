#include "libft/libft.h"
#include "includes/malloc.h"

void		init_ts(t_zone **begin, size_t zone_size) {

	void	*ptr;
	t_head	*head;
	t_zone	*zone;

	head = NULL;
	ptr = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	zone = ptr;

	head = ptr + sizeof(*(*begin));
	head->addr = head + sizeof(*head);
	head->empty = 1;
	head->size = zone_size;
	head->next = NULL;

	zone->entry = head;
	zone->zleft = zone_size;
	zone->next = NULL;

	*begin = zone;
}

void		new_alloc(t_zone **zcur, t_head **hcur, size_t size) {

	t_head	*end;

	write(1, "*******-----> debug\n", 21);

	end = (void *)*(hcur) + size;
	(*zcur)->zleft = (*zcur)->zleft - size - sizeof(*end);
	end->addr = end + sizeof(*end);
	end->size = (*zcur)->zleft;
	end->empty = 1;
	end->next = NULL;

	(*hcur)->empty = 0;
	(*hcur)->size = size;
	(*hcur)->next = end;
}

void		new_zone_alloc(t_zone **zcur, size_t size) {

	size_t	zone_size;

	printf("New Zone Alloc ... because zone->zleft => %zu\n", (*zcur)->zleft);
	(size <= TMAX_SIZE) ? (zone_size = TZMAX_SIZE) : (zone_size = SZMAX_SIZE);
	init_ts(&(*zcur)->next, zone_size);
	printf("zcur->next itself == %p\n", ((t_head *)((*zcur)->next)));
	printf("zcur->next addr == %p\n", (((*zcur)->next->entry))->addr);
	new_alloc(&(*zcur)->next, &((*zcur)->next->entry), size);
}

void		*malloc(size_t size) {

	t_zone	*zcur;
	t_head	*hcur;
	size_t	zone_size;

	zone_size = 0;
	zcur = g_e.tiny;
	while (zcur) {
		hcur = zcur->entry;
		while (hcur) {
			if (hcur->empty == 1 && hcur->size >= size + sizeof(*hcur)) {
				write(1, "-> new alloc\n", 13);
				new_alloc(&zcur, &hcur, size);
				return hcur->addr;
			}
			hcur = hcur->next;
		}
		if (zcur->next == NULL)
			break ;
		zcur = zcur->next;
	}
	(size >= TMAX_SIZE) ? (zone_size = TZMAX_SIZE) : (zone_size = SZMAX_SIZE);
	new_zone_alloc(&zcur, size);
	return NULL;
}

void		print_zone(t_zone *begin) {

	t_zone *zhead;
	t_head *cur;
	size_t nb;

	nb = 0;
	zhead = begin;
	while (zhead) {
		printf("\n---> Zone %zu\n", nb);
		printf("zone itelf => %p\n", zhead);
		printf("zone->entry => %p\n", zhead->entry);
		printf("zone->zleft => %zu\n", zhead->zleft);
		printf("zone->next => %p\n\n", zhead->next);

		cur = zhead->entry;
		while (cur) {
			printf("     cur itelf => %p\n", cur);
			printf("     cur->addr => %p\n", cur->addr);
			printf("     cur->empty => %d\n", cur->empty);
			printf("     cur->size => %zu\n", cur->size);
			printf("     cur->next => %p\n\n", cur->next);
			cur = cur->next;
		}
		nb = nb + 1;
		zhead = zhead->next;
	}
}
