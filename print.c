#include "libft/libft.h"
#include "includes/malloc.h"
#include "ft_printf/includes/printf.h"

void	show_alloc_mem() {

		t_head *cur;

		if (g_e.tiny) {
			cur = g_e.tiny->entry;
			ft_printf("TINY: %p\n", g_e.tiny);
			while (cur) {
				ft_printf("%p - %p : %zu octets\n", cur->addr, cur->addr + cur->size, cur->size);
				cur = cur->next;
			}
		}
		if (g_e.small) {
			cur = g_e.small->entry;
			ft_printf("SMALL: %p\n", g_e.small);
			while (cur) {
				ft_printf("%p - %p : %zu octets\n", cur->addr, cur->addr + cur->size, cur->size);
				cur = cur->next;
			}
		}
		if (g_e.large) {
			cur = g_e.large;
			ft_printf("LARGE: %p\n", g_e.large);
			while (cur) {
				ft_printf("%p - %p : %zu octets\n", cur->addr, cur->addr + cur->size, cur->size);
				cur = cur->next;
			}
		}
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
			printf("     cur->next => %p\n", cur->next);
			printf("     cur->prev => %p\n\n", cur->prev);
			cur = cur->next;
		}
		nb = nb + 1;
		zhead = zhead->next;
	}
}


t_head		*list_find_end(t_head *begin) {

	if (!begin->next)
		return begin;
	else
		return list_find_end(begin->next);
}

void		print_large(t_head *begin) {

	t_head	*hcur;
	size_t	nb;

	nb = 0;
	hcur = begin;
	while (hcur) {
		printf("\n---> *LARGEZone %zu\n", nb);
		printf("*LARGEhcur itelf => %p\n", hcur);
		printf("*LARGEhcur->addr => %p\n", hcur->addr);
		printf("*LARGEhcur->empty => %d\n", hcur->empty);
		printf("*LARGEhcur->size => %zu\n", hcur->size);
		printf("*LARGEhcur->next => %p\n", hcur->next);
		printf("*LARGEhcur->prev => %p\n\n", hcur->prev);
		hcur = hcur->next;
		nb = nb + 1;
	}
}

void		init_all(size_t size) {

	size_t	zone_size;

	zone_size = 0;
	(size <= TMAX_SIZE) ? (zone_size = TZMAX_SIZE) : (zone_size = SZMAX_SIZE);

	if (!g_e.tiny && zone_size == TZMAX_SIZE)
		init_ts(&g_e.tiny, TZMAX_SIZE);
	else if (!g_e.small && zone_size == SZMAX_SIZE)
		init_ts(&g_e.small, SZMAX_SIZE);
}

t_zone		*init_ts(t_zone **begin, size_t zone_size) {

	void	*ptr;
	t_head	*head;
	t_zone	*zone;

	head = NULL;
	ptr = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	zone = ptr;

	head = ptr + sizeof(*(*begin));
	//head->addr = head + sizeof(*head);
	head->addr = ptr + sizeof(*zone) + sizeof(*head);//head + sizeof(*head);
	head->empty = 1;
	head->size = zone_size - sizeof(*zone) - sizeof(*head);
	head->next = NULL;
	head->prev = NULL;

	zone->entry = head;
	zone->zleft = head->size;
	zone->next = NULL;

	if (*begin)
	{
		//write(1, "--NewZone--\n", 12);
		return zone;
	}
	*begin = zone;
	return NULL;
}
