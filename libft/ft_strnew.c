/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:06:08 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:34:17 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	size_t	i;

	string = (char *)malloc(sizeof(*string) * size + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}
