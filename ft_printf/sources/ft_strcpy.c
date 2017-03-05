/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:00:57 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:01:26 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	return (dst);
}
