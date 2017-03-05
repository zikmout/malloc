/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:18:01 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/01 11:46:45 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_atoi(const char *str)
{
	int is_negative;
	int nb;

	is_negative = 0;
	nb = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v')
			|| (*str == '\n') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		is_negative = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (is_negative == 1)
		return (-nb);
	else
		return (nb);
}
