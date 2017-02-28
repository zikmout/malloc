/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:09:54 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/25 14:23:14 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back(t_list **head, void const *content, size_t content_size)
{
	t_list *new;

	new = ft_lstnew(content, content_size);
	if (*head == NULL)
		*head = new;
	else
		ft_list_end(*head)->next = new;
}
