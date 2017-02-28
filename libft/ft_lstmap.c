/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:42:10 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/25 12:42:12 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		if (!tmp)
			return (NULL);
		if (lst->next)
			tmp->next = ft_lstmap(lst->next, f);
	}
	return (tmp);
}
