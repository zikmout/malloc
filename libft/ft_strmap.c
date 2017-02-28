/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:49:23 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:32:37 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ptr;

	if (s != NULL || f != NULL)
	{
		ptr = ft_strdup(s);
		i = 0;
		while (s[i] != '\0')
		{
			ptr[i] = f(s[i]);
			i++;
		}
		return (ptr);
	}
	else
		return (NULL);
}
