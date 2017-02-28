/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 19:55:23 by ssicard           #+#    #+#             */
/*   Updated: 2016/01/04 09:50:42 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_alloc_mem(int x, int y)
{
	int **grid;
	int i;

	grid = (int**)malloc(y * sizeof(int*));
	i = 0;
	if (grid == NULL)
		return (NULL);
	while (i <= y)
	{
		grid[i] = (int*)malloc(x * sizeof(int));
		if (grid[i] == NULL)
			return (NULL);
		i = i + 1;
	}
	return (grid);
}
