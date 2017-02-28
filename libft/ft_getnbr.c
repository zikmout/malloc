/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:00:25 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/07 17:00:32 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_getnbr2(long long nb, char *str)
{
	long long	tmp;
	long long	v;
	long long	s;

	tmp = nb;
	s = 1;
	while (tmp / 10 > 0 && nb != LONG_MIN)
	{
		s = s * 10;
		tmp = tmp / 10;
	}
	while (s > 0 && nb != LONG_MIN)
	{
		v = 0;
		v = nb / s;
		str = ft_strjoina(str, (v + '0'));
		nb = nb % s;
		s = s / 10;
	}
	return (str);
}

char			*ft_getnbr(long long nb)
{
	char		*str;

	str = ft_strdup("\0");
	if (nb == LONG_MIN)
		str = ft_strdup("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		str = ft_strjoina(str, '-');
		nb = -nb;
	}
	str = ft_getnbr2(nb, str);
	return (str);
}
