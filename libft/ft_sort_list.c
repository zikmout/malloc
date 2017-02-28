/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 13:23:55 by ssicard           #+#    #+#             */
/*   Updated: 2017/02/15 12:07:26 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_merge(t_list *lg, t_list *ld)
{
	if (lg == NULL)
		return (ld);
	else if (ld == NULL)
		return (lg);
	else if (ft_strcmp(lg->content, ld->content) <= 0)
	{
		lg->next = ft_merge(lg->next, ld);
		return (lg);
	}
	else
	{
		ld->next = ft_merge(lg, ld->next);
		return (ld);
	}
}

t_list	*ft_split(t_list *list)
{
	t_list *aux;

	if (list == NULL || list->next == NULL)
		return (NULL);
	else
	{
		aux = list->next;
		list->next = aux->next;
		aux->next = ft_split(aux->next);
		return (aux);
	}
}

void	ft_make_sort(t_list **head)
{
	t_list *aux;

	if (*head != NULL)
		if ((*head)->next != NULL)
		{
			aux = ft_split(*head);
			ft_make_sort(head);
			ft_make_sort(&aux);
			*head = ft_merge(*head, aux);
		}
}
