/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 09:24:45 by ssicard           #+#    #+#             */
/*   Updated: 2017/03/05 10:28:03 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/malloc.h"

void		check_fusion_exec(t_zone *test, t_head *found)
{
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
			zone_size = (found->size <= TMAX_SIZE) ? (TZMAX_SIZE)\
						: (SZMAX_SIZE);
			munmap(test, zone_size);
			if (zone_size <= TZMAX_SIZE)
				g_e.tiny = NULL;
			else
				g_e.small = NULL;
		}
	}
	else
		check_fusion_exec(test, found);
}

void		free_exec(t_head *found)
{
	if (found && found->prev && found->next)
	{
		found->prev->next = found->next;
		found->next->prev = found->prev;
		munmap(found, found->size + sizeof(*found));
	}
	else if (found && found->prev && !found->next)
	{
		found->prev->next = NULL;
		munmap(found, found->size + sizeof(*found));
	}
	else if (found && !found->prev && found->next)
	{
		found->next->prev = NULL;
		g_e.large = found->next;
		munmap(found, found->size + sizeof(*found));
	}
	else if (found && !found->prev && !found->next)
	{
		munmap(found, found->size + sizeof(*found));
		g_e.large = NULL;
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
	free_exec(found);
}

void		*new_zone_alloc(t_zone **zcur, size_t size)
{
	size_t	zone_size;

	zone_size = (size <= TMAX_SIZE) ? (TZMAX_SIZE) : (SZMAX_SIZE);
	(*zcur)->next = init_ts(zcur, zone_size);
	new_alloc_end(&(*zcur)->next, &((*zcur)->next->entry), size);
	return (((*zcur)->next)->entry->addr);
}
