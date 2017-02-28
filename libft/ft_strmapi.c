/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:59:59 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:34:36 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	i;
	char	*dup;

	if (s != NULL || f != NULL)
	{
		dup = ft_strdup(s);
		i = 0;
		while (s[i] != '\0')
		{
			dup[i] = f(i, s[i]);
			i++;
		}
		return (dup);
	}
	else
		return (NULL);
}
