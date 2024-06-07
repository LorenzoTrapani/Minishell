/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:51:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/07 22:16:19 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_mtx(t_input *lst)
{
	int		i;
	int		len;
	char	**mtx;

	i = 0;
	len = dll_input_size(lst);
	mtx = malloc(sizeof(char *) * (len + 1));
	if (!mtx)
		return (NULL);
	while (lst)
	{
		mtx[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
		
	}
	mtx[i] = NULL;
	return(mtx);
}