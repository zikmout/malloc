/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_realloc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 09:22:52 by ssicard           #+#    #+#             */
/*   Updated: 2017/03/05 09:28:57 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/malloc.h"

void		*realloc_exec1(size_t s, size_t old_s, void *ret, t_head *found)
{
	if (found->size >= s)
	{
		found->empty = (int)s;
		return (found->addr);
	}
	else if (found->size < s)
	{
		ret = malloc(s);
		ft_memcpy(ret, found->addr, old_s);
		free(found->addr);
		return (ret);
	}
	return (NULL);
}

t_head		*try_find(t_zone *test, void *ptr)
{
	t_head *found;

	found = NULL;
	found = locate(g_e.tiny, &test, ptr);
	if (!found)
		found = locate(g_e.small, &test, ptr);
	if (!found)
		found = locate_head(g_e.large, ptr);
	return (found);
}

void		*realloc(void *ptr, size_t size)
{
	t_zone	*test;
	t_head	*found;
	void	*ret;
	size_t	old_size;

	test = NULL;
	ret = NULL;
	if (ptr == NULL)
		return (malloc(size));
	found = try_find(test, ptr);
	if (!found)
		return (NULL);
	old_size = (found &&\
			found->empty != 0) ? ((size_t)found->empty) : (found->size);
	if (found && test && size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (found && test && size > 0)
		return (realloc_exec1(size, old_size, ret, found));
	else
		return (NULL);
}
