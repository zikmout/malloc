/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 08:43:04 by ssicard           #+#    #+#             */
/*   Updated: 2017/03/05 11:55:48 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/malloc.h"
#include "ft_printf/includes/printf.h"

size_t		show_tiny(size_t counter)
{
	t_head	*cur;

	if (g_e.tiny)
	{
		cur = g_e.tiny->entry;
		ft_printf("TINY: 0x%X\n", g_e.tiny);
		while (cur)
		{
			ft_printf("0x%X - 0x%X : %zu octets\n", cur->addr, \
					cur->addr + cur->size, cur->size);
			counter = counter + cur->size;
			cur = cur->next;
		}
	}
	return (counter);
}

size_t		show_small(size_t counter)
{
	t_head	*cur;

	if (g_e.small)
	{
		cur = g_e.small->entry;
		ft_printf("SMALL: 0x%X\n", g_e.small);
		while (cur)
		{
			ft_printf("0x%X - 0x%X : %zu octets\n", cur->addr, \
					cur->addr + cur->size, cur->size);
			counter = counter + cur->size;
			cur = cur->next;
		}
	}
	return (counter);
}

void		show_alloc_mem(void)
{
	t_head	*cur;
	size_t	counter;

	counter = 0;
	counter = show_tiny(counter);
	counter = show_small(counter);
	if (g_e.large)
	{
		cur = g_e.large;
		ft_printf("LARGE: 0x%X\n", g_e.large);
		while (cur)
		{
			ft_printf("0x%X - 0x%X : %zu octets\n", cur->addr, \
					cur->addr + cur->size, cur->size);
			counter = counter + cur->size;
			cur = cur->next;
		}
	}
	ft_printf("Total : %zu octets\n", counter);
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
