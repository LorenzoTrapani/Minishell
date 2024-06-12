/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:38:02 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/12 18:07:13 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_all *shell)
{
	ft_lstclear(&shell->envp, *free);
	free_mtx(shell->ep_copy);
}

void	dll_input_clear(t_input **lst)
{
	t_input	*ptr;

	while (lst && *lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}