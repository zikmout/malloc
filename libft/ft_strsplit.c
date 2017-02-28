/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:25:34 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 14:28:36 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		beg;
	int		end;
	char	**tab;

	tab = NULL;
	i = 0;
	j = 0;
	if (s && (tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s) / 2 + 2))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			beg = i;
			while (s[i] && s[i] != c)
				i++;
			end = i;
			if (end > beg)
				tab[j++] = ft_strsub(s, beg, (end - beg));
		}
		tab[j] = NULL;
	}
	return (tab);
}
