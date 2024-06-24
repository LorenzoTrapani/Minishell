/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/17 18:55:05 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *enum_to_str(int enume)
{
	if (enume == CMD)
		return (ft_strdup("command"));
	else if (enume == ARG)
		return (ft_strdup("argument"));
	else if (enume == FILE_W)
		return (ft_strdup("file"));
	else if (enume == EOF_DEL)
		return (ft_strdup("heredoc_del"));
	else if (enume == WORDS)
		return (ft_strdup("word"));
	else if (enume == DOLLAR_SIGN)
		return (ft_strdup("dollar sign"));
	else if (enume == PIPE)
		return (ft_strdup("pipe"));
	else if (enume == R_INPUT)
		return (ft_strdup("red. input"));
	else if (enume == R_OUTPUT)
		return (ft_strdup("red. output"));
	else if (enume == D_RED_INPUT)
		return (ft_strdup("d. red. input"));
	else if (enume == D_RED_OUTPUT)
		return (ft_strdup("d. red. output"));
	else if (enume == D_QUOTE)
		return (ft_strdup("double quote"));
	else if (enume == S_QUOTE)
		return (ft_strdup("single quote"));
	return (NULL);
}

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
	}
	free_mtx(shell.ep_copy);
	ft_lstclear((&shell.envp), free);
}
