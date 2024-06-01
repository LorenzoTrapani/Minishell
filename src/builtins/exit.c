/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:54 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/01 20:07:12 by lotrapan         ###   ########.fr       */
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

int	builtin_exit(char **av)
{
	int	exit_code;

	exit_code = 0;
	ft_printf(1, "exit\n");
	if ((av == NULL) || !av[1])
		exit_code = 0;
	else if (av[1] && numeric_check(av[1]) && !av[2])
		exit_code = ft_atoi(av[1]);
	else if (av[2] && numeric_check(av[2]))
	{
		ft_printf(1, "minishell: exit: too many arguments\n");	
		return (1);
	}
	else
	{
		ft_printf(1, "minishell: exit: rrt: numeric argument required\n");
		exit_code = 2;
	}
	free_mtx(av);
	exit(exit_code);
}
