/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <ssicard@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 16:44:34 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/07 16:46:35 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		if (tmp->next)
			ft_lstdel(&tmp->next, del);
		ft_lstdelone(alst, del);
	}
}
