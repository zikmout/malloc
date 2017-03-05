/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:17:20 by ssicard           #+#    #+#             */
/*   Updated: 2016/01/26 20:03:05 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(unsigned long long int nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != LONG_MIN)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb != LONG_MIN)
	{
		ft_putchar(nb + '0');
	}
}
