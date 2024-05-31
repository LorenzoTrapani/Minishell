/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/30 17:05:31 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char *message, bool flag)
{
	if (!flag)
		ft_printf(1, "%s", message);
	else
		ft_printf(1, "%s\n", message);
}