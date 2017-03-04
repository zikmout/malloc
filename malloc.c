#include "libft/libft.h"
#include "includes/malloc.h"

void		*new_zone_alloc(t_zone **zcur, size_t size) {

	size_t	zone_size;

	//write(1, "ZZ*****-----> debug\n", 21);
	(size <= TMAX_SIZE) ? (zone_size = TZMAX_SIZE) : (zone_size = SZMAX_SIZE);
	(*zcur)->next = init_ts(zcur, zone_size);
	//print_zone(g_e.small);
	new_alloc_end(&(*zcur)->next, &((*zcur)->next->entry), size);
	return (((*zcur)->next)->entry->addr);
}

void		new_alloc_end(t_zone **zcur, t_head **hcur, size_t size) {

	t_head	*end;

	//write(1, "EE*****-----> debug\n", 21);
	end = (*hcur)->addr + size;
	(*zcur)->zleft = (*zcur)->zleft - size - sizeof(*end);
	end->addr = (*hcur)->addr + size + sizeof(*end);
	end->size = (*zcur)->zleft;
	end->empty = 1;
	end->next = NULL;
	end->prev = (*hcur);

	(*hcur)->empty = 0;
	(*hcur)->size = size;
	(*hcur)->next = end;
}

void		*malloc(size_t size) {

	t_zone	*zcur;
	t_head	*hcur;

	zcur = NULL;
	hcur = NULL;
int nb = 0;
int znb = 0;
	if (!size)
		return NULL;
	if (size > SMAX_SIZE)
		return malloc_large(size);
	else
		init_all(size);
	//printf("******** MALLOC of size -> %zu\n", size);

	(size <= TMAX_SIZE) ? (zcur = g_e.tiny) : (zcur = g_e.small);

	while (zcur) {
		hcur = zcur->entry;
		//printf("zone -> %d\n", znb);
			//print_zone(zcur);
		while (hcur) {
			nb++;
			//printf("    -> %d\n", nb);
			if (hcur->next && hcur->empty == 1 && hcur->size >= size) {
	//			write(1, "-> new alloc middle\n", 20);
				hcur->empty = (size_t)size;
				return hcur->addr;
			}
			else if (!hcur->next && zcur->zleft >= size + sizeof(*hcur)) {
	//			write(1, "-> new alloc end\n", 17);
				new_alloc_end(&zcur, &hcur, size);
				return hcur->addr;
			}
			hcur = hcur->next;
		}
		if (zcur->next == NULL)
			break ;
		zcur = zcur->next;
		znb++;
	}

	return new_zone_alloc(&zcur, size);
}

void		*realloc(void *ptr, size_t size) {

	t_zone	*test;
	t_head	*found;
	void	*ret;
	size_t	old_size;

	//printf("******** REALLOC of pointer -> %p for size %zu\n", ptr, size);
	if (ptr == NULL)
		return malloc(size);

	found = locate(g_e.tiny, &test, ptr);
	if (!found)
		found = locate(g_e.small, &test, ptr);
	if (!found) {
		found = locate_head(g_e.large, ptr);
	}
	if (!found)
		return NULL;

	(found && found->empty != 0) ? (old_size = (size_t)found->empty) : (old_size = found->size);

	if (found && test) {
		if (found && size == 0) {
			free(ptr);
			return NULL;
		}
		else if (found && size > 0) {
			if (found->size >= size) {
				found->empty = (int)size;
				return found->addr;
			}
			else if (found->size < size) {
				ret = malloc(size);
				ft_memcpy(ret, found->addr, old_size);
				free(found->addr);
				return ret;
			}
		}
		else
			return NULL;
	}
	return NULL;
}

void		*malloc_large(size_t size) {

	t_head	*hcur;
	t_head	*tmp;
	void	*ptr;

	ptr = mmap(NULL, size + sizeof(*hcur), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	hcur = ptr;
	hcur->addr = hcur + sizeof(*hcur);
	hcur->empty = 0;
	hcur->size = size;
	hcur->next = NULL;

	if (g_e.large == NULL) {
		g_e.large = hcur;
		hcur->prev = NULL;
	}
	else {
		tmp = list_find_end(g_e.large);
		tmp->next = hcur;
		hcur->prev = tmp;
	}
	return hcur->addr;
}

t_head		*locate(t_zone *begin, t_zone **head, void *ptr) {

	t_zone	*zcur;
	t_head	*hcur;

	zcur = begin;
	while (zcur) {
		hcur = zcur->entry;
		while (hcur) {
			if (hcur->addr == ptr) {
				*head = zcur;
				return hcur;
			}
			hcur = hcur->next;
		}
		zcur = zcur->next;
	}
	return NULL;
}

int			free_zone(t_zone *to_free, size_t zone_size) {
	return munmap(to_free, zone_size);
}

void		check_fusion(t_zone *test, t_head *found) {

	size_t	zone_size;

	zone_size = 0;
	//write(1, "ENTER -------------FUSION\n", 26);

	if (found->prev && found->next && found->prev->empty == 1 && found->next->empty == 1) {
		found->prev->empty = 1;
		found->prev->next = found->next->next;
		found->prev->size = found->prev->size + found->size + found->next->size;
		if (found->next->next)
			found->next->next->prev = found->prev;

		test->zleft = test->zleft + sizeof(*found) + sizeof(*found);

		if (found->prev && !found->prev->prev && !found->prev->next) {
			(found->size <= TMAX_SIZE) ? (zone_size = TZMAX_SIZE) : (zone_size = SZMAX_SIZE);

			//printf("Vider la ZZZZZZZZZZZZZZZZZZZZZZZZZONOOOOONNNNE\n");
			//printf("Retour de munmap = %d\n", free_zone(test, zone_size));
			free_zone(test, zone_size);
			(zone_size <= TZMAX_SIZE) ? (g_e.tiny = NULL) : (g_e.small = NULL);
		}
	}
	else { //can be reduced here
		if (found->prev && found->next && found->prev->empty == 1) {
			found->prev->next = found->next;
			found->prev->size = found->prev->size + found->size;
			found->next->prev = found->prev;
			test->zleft = test->zleft + sizeof(*found);
			found->next->empty = 1;
			//found = NULL;
		}
		if (found->next && found->prev && found->next->empty == 1) {


			found->empty = 1;
			found->size = found->size + found->next->size;
			if (found->next->next) {
				found->next = found->next->next;
				found->next->next->prev = found;
			}
			else {
				found->next = NULL;
			}

			//found->prev->next = found->next;
			//found->next->size = found->next->size + found->size;
			//found->next->prev = found->prev;
			//test->zleft = test->zleft + sizeof(*found);
			//found->next->empty = 1;
			//found = NULL;
		}
		//print_zone(test);
	}
}

void		free(void *ptr) {

	t_zone	*test;
	t_head	*found;

	//write(1, "ENTER -------------FREEEE\n", 26);
	test = NULL;
	found = NULL;
	found = locate(g_e.tiny, &test, ptr);
	if (found) {
		//printf("found->size = %zu\n", found->size);
		//found->empty = 1;
		check_fusion(test, found);
		return ;
	}
	found = locate(g_e.small, &test, ptr);
	if (found) {
		//printf("found->size = %zu\n", found->size);
		//found->empty = 1;
		check_fusion(test, found);
		return ;
	}
	found = locate_head(g_e.large, ptr);
	if (found) {
		//printf("found large ptr = %p and size = %zu\n", ptr, found->size);
		if (found->prev && found->next) {
			found->prev->next = found->next;
			found->next->prev = found->prev;
			munmap(found, found->size + sizeof(*found));
		}
		else if (found->prev && !found->next) {
			found->prev->next = NULL;
			munmap(found, found->size + sizeof(*found));
		}
		else if (!found->prev && found->next) {
			found->next->prev = NULL;
			g_e.large = found->next;
			munmap(found, found->size + sizeof(*found));

		}
		else if (!found->prev && !found->next) {
			munmap(found, found->size + sizeof(*found));
			g_e.large = NULL;
		}
	}
}

t_head		*locate_head(t_head *head, void *ptr) {

	t_head	*hcur;

	hcur = head;
	while (hcur) {
		if (hcur->addr == ptr) {
			return hcur;
		}
		hcur = hcur->next;
	}
	return NULL;
}
