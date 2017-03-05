/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:32:51 by ssicard           #+#    #+#             */
/*   Updated: 2016/01/26 15:12:27 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_spl(int tmp, int len, char *str, char *pad)
{
	while (tmp-- - len > 0)
		str = ft_strjoin(str, pad);
	return (str);
}
