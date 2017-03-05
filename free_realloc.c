#include "libft/libft.h"
#include "includes/malloc.h"

void		*realloc(void *ptr, size_t size)
{
	t_zone	*test;
	t_head	*found;
	void	*ret;
	size_t	old_size;

	if (ptr == NULL)
		return (malloc(size));
	found = locate(g_e.tiny, &test, ptr);
	if (!found)
		found = locate(g_e.small, &test, ptr);
	if (!found)
		found = locate_head(g_e.large, ptr);
	if (!found)
		return (NULL);
	old_size = (found && found->empty != 0) ? ((size_t)found->empty) : (found->size);
	if (found && test)
	{
		if (found && size == 0)
		{
			free(ptr);
			return (NULL);
		}
		else if (found && size > 0)
		{
			if (found->size >= size)
			{
				found->empty = (int)size;
				return (found->addr);
			}
			else if (found->size < size)
			{
				ret = malloc(size);
				ft_memcpy(ret, found->addr, old_size);
				free(found->addr);
				return (ret);
			}
		}
		else
			return (NULL);
	}
	return (NULL);
}

int			free_zone(t_zone *to_free, size_t zone_size)
{
	return (munmap(to_free, zone_size));
}

void		check_fusion(t_zone *test, t_head *found)
{
	size_t	zone_size;

	zone_size = 0;
	if (found->prev && found->next && found->prev->empty == 1 && \
			found->next->empty == 1)
	{
		found->prev->empty = 1;
		found->prev->next = found->next->next;
		found->prev->size = found->prev->size + found->size + found->next->size;
		if (found->next->next)
			found->next->next->prev = found->prev;
		test->zleft = test->zleft + sizeof(*found) + sizeof(*found);
		if (found->prev && !found->prev->prev && !found->prev->next)
		{
			zone_size = (found->size <= TMAX_SIZE) ? (TZMAX_SIZE) : (SZMAX_SIZE);
			free_zone(test, zone_size);
			(zone_size <= TZMAX_SIZE) ? (g_e.tiny = NULL) : (g_e.small = NULL);
		}
	}
	else
	{ //can be reduced here
		if (found->prev && found->next && found->prev->empty == 1)
		{
			found->prev->next = found->next;
			found->prev->size = found->prev->size + found->size;
			found->next->prev = found->prev;
			test->zleft = test->zleft + sizeof(*found);
			found->next->empty = 1;
		}
		if (found->next && found->prev && found->next->empty == 1)
		{
			found->empty = 1;
			found->size = found->size + found->next->size;
			if (found->next->next)
			{
				found->next = found->next->next;
				found->next->next->prev = found;
			}
			else
				found->next = NULL;
		}
	}
}

void		free(void *ptr)
{
	t_zone	*test;
	t_head	*found;

	test = NULL;
	found = locate(g_e.tiny, &test, ptr);
	if (found)
	{
		check_fusion(test, found);
		return ;
	}
	found = locate(g_e.small, &test, ptr);
	if (found)
	{
		check_fusion(test, found);
		return ;
	}
	found = locate_head(g_e.large, ptr);
	if (found)
	{
		if (found->prev && found->next)
		{
			found->prev->next = found->next;
			found->next->prev = found->prev;
			munmap(found, found->size + sizeof(*found));
		}
		else if (found->prev && !found->next)
		{
			found->prev->next = NULL;
			munmap(found, found->size + sizeof(*found));
		}
		else if (!found->prev && found->next)
		{
			found->next->prev = NULL;
			g_e.large = found->next;
			munmap(found, found->size + sizeof(*found));
		}
		else if (!found->prev && !found->next)
		{
			munmap(found, found->size + sizeof(*found));
			g_e.large = NULL;
		}
	}
}

void		*new_zone_alloc(t_zone **zcur, size_t size)
{
	size_t	zone_size;

	zone_size = (size <= TMAX_SIZE) ? (TZMAX_SIZE) : (SZMAX_SIZE);
	(*zcur)->next = init_ts(zcur, zone_size);
	new_alloc_end(&(*zcur)->next, &((*zcur)->next->entry), size);
	return (((*zcur)->next)->entry->addr);
}
