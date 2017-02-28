/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:43:51 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:14:22 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	if (str == NULL || to_find == NULL)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	j = 0;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == to_find[0])
		{
			while (((to_find[j]) && str[i + j] == to_find[j]) && (i + j) < n)
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&(str[i]));
			}
		}
		i++;
	}
	return (NULL);
}
