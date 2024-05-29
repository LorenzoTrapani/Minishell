/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/29 14:04:10 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char	*shell;
	(void)shell;
	// t_builtin	ptr;
	// ptr = (t_builtin){0};
	// builtin_pwd(&ptr);
	// builtin_env(&ptr);
	while (42)
	{
		shell = readline("Minishell > ");
		// parse_line(shell);

	}

}