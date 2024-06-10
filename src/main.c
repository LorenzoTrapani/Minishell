/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/09 21:16:31 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		status = 130;
	}
} */

int main(int ac, char **av, char **envp)
{
	char	*line;
	t_all	shell;

	shell = (t_all){0};
	if (ac != 1)
	{
		ft_printf(2, "error: wrong number of arguments\n");
		return (0);
	}
	(void)av;
	shell_struct_init(&shell, envp);
	//signal(SIGINT, handle_sig);
	//signal(SIGQUIT, SIG_IGN);
	while (42)
	{
		line = readline("Minishell > ");
		if (!line)
			break ;
		shell.cmd_line = fake_parse(line);
		exec_main(&shell);
		free(line);
		//ft_lstclear((**shell), free);
	}
}