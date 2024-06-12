/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/12 18:42:44 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int signal_status = 0;

static void	handle_sigint()
{
	printf("\nMinishell > ");
} */

int	signal_handle(char *str)
{
	if (str == NULL)
	{
		ft_printf(1, "exit\n");
		exit (0);
	}
	/* if (signal_status == 130)
		return (0);
	return (1); */
	return (0);
}

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
	//signal(SIGINT, handle_sigint);
	//signal(SIGQUIT, SIG_IGN);
	while (42)
	{
		line = readline("Minishell > ");
		if (!signal_handle(line))
		{
			shell.cmd_line = fake_parse(line);
			exec_main(&shell);
			//dll_input_clear(&shell.cmd_line);
		}
		free(line);
		//ft_lstclear((**shell), free);
	}
}
