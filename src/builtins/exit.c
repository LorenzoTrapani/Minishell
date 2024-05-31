/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:54 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/31 18:28:42 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int numeric_check(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_exit(char **av)
{
	if (av == NULL)
	{
		ft_printf(1, "exit\n");
		exit(0);
	}
	ft_printf(1, "exit\n");
	if (!av[1])
		exit(0);
	if (av[1] && numeric_check(av[1]) && !av[2])
		exit(ft_atoi(av[1]));
	if (av[2] && numeric_check(av[2]))
	{
		ft_printf(1, "bash: exit: too many arguments\n");	
		exit(1);
	}
	else
	{
		ft_printf(1, "bash: exit: rrt: numeric argument required\n");
		exit(2);
	}
}