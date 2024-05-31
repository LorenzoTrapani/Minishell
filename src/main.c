/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/31 18:24:55 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char	*shell;
	(void)shell;
	char	**av;
	// t_builtin	ptr;
	// ptr = (t_builtin){0};
	// builtin_pwd(&ptr);
	// builtin_env(&ptr);
	while (42)
	{
		shell = readline("Minishell > ");
		av = ft_split(shell, ' ');
		if (!av)
			builtin_exit(NULL);
		if (ft_strncmp(av[0], "exit", 5) == 0)
			builtin_exit(av);
		if (ft_strncmp(av[0], "echo", 5) == 0)
			builtin_echo(av[0] + 5, true);
		free(shell);
		// parse_line(shell);

	}

}