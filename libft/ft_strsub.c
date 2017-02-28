/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:10:06 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:20:30 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	start1;
	size_t	i;

	start1 = 0;
	if (s)
	{
		ptr = (char *)malloc(sizeof(*s) * (len + 1));
		if (ptr == NULL)
			return (NULL);
		i = 0;
		start1 = (size_t)start;
		while (len > i && s[start])
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
