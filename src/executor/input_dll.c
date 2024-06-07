/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_dll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:22:37 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/07 19:52:24 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dll_input_size(t_input *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	dll_input_addback(t_input **lst, t_input *new)
{	
	t_input	*last;

	if (!lst || !new)
		return ;
	last = dll_input_last(*lst);
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->prev = last;
	new->next = NULL;
	last->next = new;
}

t_input	*dll_input_last(t_input *lst)
{
	t_input	*new;

	if (!lst)
		return (NULL);
	new = lst;
	while (new->next != NULL)
		new = new->next;
	return (new);
}

t_input	*dll_input_new(char *content)
{
	t_input	*new;

	new = ft_calloc(1, sizeof(t_input));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}