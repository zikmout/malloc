#include "libft/libft.h"
#include "includes/malloc.h"

void		new_alloc_end(t_zone **zcur, t_head **hcur, size_t size)
{
	t_head	*end;

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

void		*malloc(size_t size)
{
	t_zone	*zcur;
	t_head	*hcur;

	if (!size)
		return (NULL);
	if (size > SMAX_SIZE)
		return (malloc_large(size));
	else
		init_all(size);
	zcur = (size <= TMAX_SIZE) ? (g_e.tiny) : (g_e.small);
	while (zcur)
	{
		hcur = zcur->entry;
		while (hcur)
		{
			if (hcur->next && hcur->empty == 1 && hcur->size >= size)
			{
				hcur->empty = (size_t)size;
				return (hcur->addr);
			}
			else if (!hcur->next && zcur->zleft >= size + sizeof(*hcur))
			{
				new_alloc_end(&zcur, &hcur, size);
				return (hcur->addr);
			}
			hcur = hcur->next;
		}
		if (zcur->next == NULL)
			break ;
		zcur = zcur->next;
	}
	return (new_zone_alloc(&zcur, size));
}

void		*malloc_large(size_t size)
{
	t_head	*hcur;
	t_head	*tmp;
	void	*ptr;

	ptr = mmap(NULL, size + sizeof(*hcur), PROT_READ | PROT_WRITE,\
			MAP_ANON | MAP_PRIVATE, -1, 0);
	hcur = ptr;
	hcur->addr = hcur + sizeof(*hcur);
	hcur->empty = 0;
	hcur->size = size;
	hcur->next = NULL;
	if (g_e.large == NULL)
	{
		g_e.large = hcur;
		hcur->prev = NULL;
	}
	else
	{
		tmp = list_find_end(g_e.large);
		tmp->next = hcur;
		hcur->prev = tmp;
	}
	return (hcur->addr);
}

t_head		*locate(t_zone *begin, t_zone **head, void *ptr)
{
	t_zone	*zcur;
	t_head	*hcur;
	zcur = begin;
	while (zcur)
	{
		hcur = zcur->entry;
		while (hcur)
		{
			if (hcur->addr == ptr)
			{
				*head = zcur;
				return (hcur);
			}
			hcur = hcur->next;
		}
		zcur = zcur->next;
	}
	return (NULL);
}

t_head		*locate_head(t_head *head, void *ptr)
{
	t_head	*hcur;

	hcur = head;
	while (hcur)
	{
		if (hcur->addr == ptr)
			return (hcur);
		hcur = hcur->next;
	}
	return (NULL);
}
