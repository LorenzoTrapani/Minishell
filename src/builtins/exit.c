/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:54 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/04 20:36:06 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	ft_uatoi(const char *str)
{
	int					i;
	int					sign;
	unsigned int		n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int	numeric_check(t_list *shell)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = shell;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		while (tmp->str[i])
		{
			if (tmp->str[i] == '-' || tmp->str[i] == '+')
				i++;
			if (!ft_isdigit(tmp->str[i]))
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	builtin_exit(t_list *shell)
{
	long long	exit_code;

	exit_code = 0;
	ft_printf(1, "exit\n");
	shell->size = ft_lstsize(shell);
	if (shell->size == 1) // da cambiare in futuro gestione ctrl + D quando si fanno segnali(adesso segfaulta)
		exit(exit_code);
	if (shell->size > 2)
	{
		ft_printf(1, "minishell: exit: too many arguments\n");
		return (1);
	}
	if (numeric_check(shell) == 0)
	{
		ft_printf(1, "minishell: exit: rrt: numeric argument required\n");
		exit_code = 2;
	}
	if (shell->size == 2 && exit_code != 2)
		exit_code = ft_uatoi(shell->next->str);
	exit(exit_code);
}
