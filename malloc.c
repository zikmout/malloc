#include "libft/libft.h"
#include "includes/malloc.h"

void		free(void *ptr) {

	t_head	*found;

	if (g_e.tiny) {
		found = parse_ts(g_e.tiny, ptr);
		if (found) {
			printf("T-Return of parse_ts size ===> %zu\n", found->size);
			return ;
		}
	}
	if (g_e.small) {
		found = parse_ts(g_e.small, ptr);
		if (found) {
			printf("S-Return of parse_ts size ===> %zu\n", found->size);
			return ;
		}
	}
	if (g_e.large) {
		found = parse_large(g_e.large, ptr);
		if (found) {
			printf("L-Return of parse_ts size ===> %zu\n", found->size);
			return ;
		}
	}
}

t_head		*parse_large(t_head *begin, void *ptr) {

	t_head	*hcur;
	t_head	*hcur_prev;
	t_head	*tmp;

	tmp = NULL;
	hcur_prev = NULL;
	hcur = begin;
	while (hcur) {
		if (hcur->addr == ptr) {
			if (hcur_prev != NULL && hcur->next != NULL) {
				printf("(middle) HCUR PREV ----> %zu\n", hcur_prev->size);
				hcur_prev->next = hcur->next;
				printf("Retour mmap %d\n", munmap((void *)(hcur), hcur->size + sizeof(*hcur)));
				return NULL;
			}
			else if (hcur->next == NULL) {
				printf("(fin) HCUR SIZE ----> %zu\n", hcur->size);
				if (hcur_prev == NULL) {
					//personne apres ni avant //printf("(fin seul memem) HCUR SIZE ----> %zu\n", hcur->size);
					printf("Retour mmap %d\n", munmap((void *)(g_e.large), hcur->size + sizeof(*hcur)));
					g_e.large = NULL;
					return NULL;
				}
				else {
					hcur_prev->next = NULL;
					printf("Retour mmap %d\n", munmap((void *)(hcur), hcur->size + sizeof(*hcur)));
					return NULL;
				}
				return NULL;
			}
			else {
				printf("(debut) HCUR SIZE ----> %zu\n", hcur->size);
				g_e.large = hcur->next;
				printf("Retour mmap %d\n", munmap((void *)(hcur), hcur->size + sizeof(*hcur)));
				return NULL;
			}
		}
		hcur_prev = hcur;
		hcur = hcur->next;
	}
	return NULL;
}

t_head		*parse_ts(t_zone *begin, void *ptr) {

	t_zone	*zcur;
	t_head	*hcur;
	size_t	stop;

	stop = 0;
	zcur = begin;
	while (zcur) {
		hcur = zcur->entry;
		while (hcur) {
			if (hcur->addr == ptr) {
				hcur->empty = 1;
				zcur->zleft = zcur->zleft + hcur->size;
				list_find_end(hcur)->size = zcur->zleft;
				return hcur;
			}
			hcur = hcur->next;
		}
		zcur = zcur->next;
	}
	return NULL;
}

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

void		new_alloc_end(t_zone **zcur, t_head **hcur, size_t size) {

	t_head	*end;

	write(1, "EE*****-----> debug\n", 21);
	end = (void *)(*(hcur) + size);
	(*zcur)->zleft = (*zcur)->zleft - size - sizeof(*end);
	end->addr = end + sizeof(*end);
	end->size = (*zcur)->zleft;
	end->empty = 1;
	end->next = NULL;

	(*hcur)->empty = 0;
	(*hcur)->size = size;
	(*hcur)->next = end;
}

void		*new_zone_alloc(t_zone **zcur, size_t size) {

	size_t	zone_size;

	(size <= TMAX_SIZE) ? (zone_size = TZMAX_SIZE) : (zone_size = SZMAX_SIZE);
	init_ts(&(*zcur)->next, zone_size);
	new_alloc_end(&(*zcur)->next, &((*zcur)->next->entry), size);
	return ((*zcur)->next->entry->addr);
}

t_head		*list_find_end(t_head *begin) {

	if (!begin->next)
		return begin;
	else
		return list_find_end(begin->next);
}

void		*malloc_large(size_t size) {

	t_head	*hcur;
	void	*ptr;

	ptr = mmap(NULL, size + 32, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	hcur = ptr;
	hcur->addr = hcur + sizeof(*hcur);
	hcur->empty = 0;
	hcur->size = size;
	hcur->next = NULL;

	if (g_e.large == NULL)
		g_e.large = hcur;
	else
		list_find_end(g_e.large)->next = hcur;

	return hcur->addr;
}

void		*malloc(size_t size) {

	t_zone	*zcur;
	t_head	*hcur;

	if (size > SMAX_SIZE)
		return malloc_large(size);
	(size <= TMAX_SIZE) ? (zcur = g_e.tiny) : (zcur = g_e.small);
	while (zcur) {
		hcur = zcur->entry;
		while (hcur) {
			if (!hcur->next && hcur->empty == 1 && hcur->size >= size + sizeof(*hcur)) {
				write(1, "-> new alloc end\n", 14);
				new_alloc_end(&zcur, &hcur, size);
				return hcur->addr;
			}
			else if (hcur->next && hcur->empty == 1 && hcur->size >= size) {
				write(1, "-> new alloc middle\n", 20);
				hcur->empty = size;
				return hcur->addr;
			}
			hcur = hcur->next;
		}
		if (zcur->next == NULL)
			break ;
		zcur = zcur->next;
	}
	return new_zone_alloc(&zcur, size);
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

void		print_large(t_head *begin) {

	t_head *hcur;

	hcur = begin;
	while (hcur) {
		printf("     LARGEhcur itelf => %p\n", hcur);
		printf("     LARGEhcur->addr => %p\n", hcur->addr);
		printf("     LARGEhcur->empty => %d\n", hcur->empty);
		printf("     LARGEhcur->size => %zu\n", hcur->size);
		printf("     LARGEhcur->next => %p\n\n", hcur->next);
		hcur = hcur->next;
	}
}

/*
typedef char    *(*psf)(struct s_params *, char *, char *, size_t);

void    init_ptab(psf **tab)
{
	*tab = (psf*)malloc(sizeof(psf) * 14);

	(*tab)[0] = &ft_1;
	(*tab)[1] = &ft_2;
	(*tab)[2] = &ft_3;
	(*tab)[3] = &ft_4;
	(*tab)[4] = &ft_5;
	(*tab)[5] = &ft_6;
	(*tab)[6] = &ft_7;
	(*tab)[7] = &ft_8;
	(*tab)[8] = &ft_9;
	(*tab)[9] = &ft_10;
	(*tab)[10] = &ft_11;
	(*tab)[11] = &ft_12;
	(*tab)[12] = &ft_13;
	(*tab)[13] = &ft_14;
}


psf    *p_tab;
    init_ptab(&p_tab);
while (i <= 13)
{
	if (i == code - 1)
	{
		str = (*(p_tab[i]))(p, flags, str, len);
		break ;
	}
	i = i + 1;
}
*/
