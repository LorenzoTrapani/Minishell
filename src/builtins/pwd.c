/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:51 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/07 17:58:12 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	/* if (ft_lstsize(cmd) > 1)
	{
		ft_printf(2, "minishell: pwd: too many arguments\n");
		return ;
	} */
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_printf(2, "minishell: pwd: working directory not found\n");
		return ;
	}
	ft_printf(1, "%s\n", pwd);
	free(pwd);
}
