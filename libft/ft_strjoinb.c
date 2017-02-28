/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:59:18 by ssicard           #+#    #+#             */
/*   Updated: 2016/02/02 09:59:46 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinb(char const c, char *s1)
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
	*(str + nb) = c;
	nb++;
	while (s1[i])
	{
		*(str + nb) = s1[i++];
		nb++;
	}
	*(str + nb) = '\0';
	free(s1);
	return (str);
}
