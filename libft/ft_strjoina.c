/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoina.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:00:01 by ssicard           #+#    #+#             */
/*   Updated: 2016/02/02 10:00:27 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoina(char *s1, char const c)
{
	char			*str;
	unsigned int	nb;
	int				i;

	i = 0;
	if (!s1)
		return (NULL);
	nb = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * nb + 1);
	if (!str)
		return (NULL);
	nb = 0;
	while (s1[i])
	{
		*(str + nb) = s1[i++];
		nb++;
	}
	*(str + nb) = c;
	nb++;
	*(str + nb) = '\0';
	free(s1);
	return (str);
}
