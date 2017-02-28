/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:06:58 by ssicard           #+#    #+#             */
/*   Updated: 2016/01/03 11:38:55 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*sc1;
	const char	*sc2;
	size_t		i;

	sc1 = s1;
	sc2 = s2;
	i = 0;
	while (i < n)
	{
		if (sc1[i] != sc2[i])
			return ((unsigned char)sc1[i] - (unsigned char)sc2[i]);
		i++;
	}
	return (0);
}
