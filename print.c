/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 08:43:04 by ssicard           #+#    #+#             */
/*   Updated: 2017/03/05 08:43:25 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/malloc.h"
#include "ft_printf/includes/printf.h"

void		show_tiny_small(void)
{
	t_head	*cur;

	if (g_e.tiny)
	{
		cur = g_e.tiny->entry;
		ft_printf("TINY: %p\n", g_e.tiny);
		while (cur)
		{
			ft_printf("%p - %p : %zu octets\n", cur->addr, \
					cur->addr + cur->size, cur->size);
			cur = cur->next;
		}
	}
	if (g_e.small)
	{
		cur = g_e.small->entry;
		ft_printf("SMALL: %p\n", g_e.small);
		while (cur)
		{
			ft_printf("%p - %p : %zu octets\n", cur->addr, \
					cur->addr + cur->size, cur->size);
			cur = cur->next;
		}
	}
}

void		show_alloc_mem(void)
{
	t_head *cur;

	show_tiny_small();
	if (g_e.large)
	{
		cur = g_e.large;
		ft_printf("LARGE: %p\n", g_e.large);
		while (cur)
		{
			ft_printf("%p - %p : %zu octets\n", cur->addr, \
					cur->addr + cur->size, cur->size);
			cur = cur->next;
		}
	}
}

t_head		*list_find_end(t_head *begin)
{
	if (!begin->next)
		return (begin);
	else
		return (list_find_end(begin->next));
}

void		init_all(size_t size)
{
	size_t	zone_size;

	zone_size = 0;
	zone_size = (size <= TMAX_SIZE) ? (TZMAX_SIZE) : (SZMAX_SIZE);
	if (!g_e.tiny && zone_size == TZMAX_SIZE)
		init_ts(&g_e.tiny, TZMAX_SIZE);
	if (!g_e.small && zone_size == SZMAX_SIZE)
		init_ts(&g_e.small, SZMAX_SIZE);
}

t_zone		*init_ts(t_zone **begin, size_t zone_size)
{
	void	*ptr;
	t_head	*head;
	t_zone	*zone;

	head = NULL;
	ptr = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, \
			MAP_ANON | MAP_PRIVATE, -1, 0);
	zone = ptr;
	head = ptr + sizeof(*(*begin));
	head->addr = ptr + sizeof(*zone) + sizeof(*head);
	head->empty = 1;
	head->size = zone_size - sizeof(*zone) - sizeof(*head);
	head->next = NULL;
	head->prev = NULL;
	zone->entry = head;
	zone->zleft = head->size;
	zone->next = NULL;
	if (*begin)
		return (zone);
	*begin = zone;
	return (NULL);
}
