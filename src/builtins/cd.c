/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:44:34 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/07 21:57:31 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(t_input *cmd_line)
{
	// aggiungere casistica no argv
	char	*dir;

	dir = NULL;
	if (dll_input_size(cmd_line) > 2)
		return (ft_printf(1, "minishell: cd: too many arguments\n"));
	cmd_line = cmd_line->next;
	dir = (char *)cmd_line->content;
	if (chdir(dir) == 0)
		return (0);
	else
		return(ft_printf(1, "minishell: cd: " "%s: No such file or directory\n", dir));
}
