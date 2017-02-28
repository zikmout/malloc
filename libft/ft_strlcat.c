/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:09:03 by ssicard           #+#    #+#             */
/*   Updated: 2016/01/03 11:09:10 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		slen;
	size_t		dlen;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	while (dst[i] != '\0')
		i++;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size < dlen)
		return (slen + size);
	return (slen + dlen);
}
