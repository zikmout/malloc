/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:23:29 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:16:26 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	if (str == NULL || to_find == NULL)
		return (NULL);
	if (to_find[0] == '\0')
		return (char *)str;
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
			while ((str[i + j] == to_find[j]) || (to_find[j] == '\0'))
			{
				if (to_find[j] == '\0')
					return ((char *)&(str[i]));
				j++;
			}
		i++;
	}
	return (NULL);
}
