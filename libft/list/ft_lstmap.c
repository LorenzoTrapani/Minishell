/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:51:15 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	t_list	*n_list;

	p = lst;
	n_list = NULL;
	if (!p || !f || !del)
		return (NULL);
	while (p)
	{
		new = ft_lstnew((*f)(p->content));
		if (!new)
			break ;
		ft_lstadd_back(&n_list, new);
		p = p->next;
	}
	if (!new)
	{
		ft_lstclear(&n_list, del);
		return (NULL);
	}
	return (n_list);
}
