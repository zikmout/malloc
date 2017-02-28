/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ibull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:29:28 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/02 20:17:51 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ibull(unsigned long long n, int base, int min)
{
	static char		buf[INT_UNS_DIGITS + 2];
	char			*ret;
	char			c;

	c = (min == 1) ? ('a') : ('A');
	if (base < 0)
		return (NULL);
	ret = buf + INT_UNS_DIGITS + 1;
	if (n == 0)
	{
		*--ret = '0';
		return (ret);
	}
	while (n != 0)
	{
		if (base > 10 && n % base >= 10 && n % base <= 15)
			*--ret = c + n % base - 10;
		else
			*--ret = '0' + n % base;
		n /= base;
	}
	return (ret);
}
