/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/01 19:18:17 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	char_rep_check(char *str, char c)
{
	int	i;

	i = 1;
	while(str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void	builtin_echo(char **av)
{
	int		i;
	bool	flag;

	if (av[1] == NULL)
	{
		ft_printf(1, "\n");
		return ;
	}
	i = 1;
	flag = false;
	if (av[i][0] == '-' && char_rep_check(av[1], 'n'))
	{
		flag = true;
		i++;
	}	
	while (av[i])
	{
		ft_printf(1, "%s", av[i]);
		if (av[i + 1])
			ft_printf(1, " ");
		i++;
	}
	if (!flag)
		ft_printf(1, "\n");
	return ;	
}
