/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:45:52 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:27:54 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	stopp;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	stopp = (unsigned char)c;
	i = -1;
	while (n > ++i)
	{
		d[i] = s[i];
		if ((d[i] = s[i]) == stopp)
			return (dest + 1 + i);
	}
	return (NULL);
}
