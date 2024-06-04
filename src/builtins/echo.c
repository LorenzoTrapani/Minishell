/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/04 20:33:41 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	char_rep_check(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void	print_echo(t_list *tmp)
{
	while (tmp)
	{
		ft_printf(1, "%s", tmp->str);
		if (tmp->next)
			ft_printf(1, " ");
		tmp = tmp->next;
	}
}

void	builtin_echo(t_list *shell)
{
	t_list	*tmp;
	bool	flag;

	tmp = shell;
	flag = false;
	if (!tmp->next)
	{
		ft_printf(1, "\n");
		return ;
	}
	tmp = tmp->next;
	while (tmp && tmp->str[0] == '-')
	{
		if (char_rep_check(tmp->str, 'n') && !flag)
			flag = true;
		else
			break ;
		tmp = tmp->next;
	}
	print_echo(tmp);
	if (!flag)
		ft_printf(1, "\n");
	return ;
}
