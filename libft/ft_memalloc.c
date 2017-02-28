/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:27:29 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/02 20:15:25 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *new;

	new = malloc(sizeof(size_t) * size);
	if (!new || !size)
		return (NULL);
	while (--size)
		new[size] = 0;
	new[0] = 0;
	return (new);
}
