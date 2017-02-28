/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:46:27 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 12:19:51 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	beg;
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (((s[i] == ' ') || (s[i] == '\n') ||
					(s[i] == '\t')) && (s[i] != '\0'))
			i++;
		beg = i;
		len--;
		while (((s[len] == ' ') || (s[len] == '\n') ||
					(s[len] == '\t')) && len > i)
			len--;
		return (ft_strsub(s, beg, (len - beg + 1)));
	}
	else
		return (NULL);
}
