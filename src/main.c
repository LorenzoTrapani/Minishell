/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/07 22:11:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*set_env_lst(char **envp)
{
	int	i;
	t_list *env; 

	i = 0;
	env = NULL;
	while (envp[i])
	{
		ft_lstadd_back(&env, ft_lstnew(envp[i]));
		i++;
	}
	return (env);
}

t_input   	*fake_parse(char *input)
{
	char	**av;
	int 	i;
	t_input	*parse_line;

	parse_line = NULL;
	i = 0;
	av = ft_split(input, ' ');
	while (av[i])
	{
		dll_input_addback(&parse_line, dll_input_new(av[i]));
		i++;
	}
	free(av);
	return (parse_line);
}

void	shell_struct_init(t_all *shell, char **envp)
{
	shell->envp = set_env_lst(envp);
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
	while (42)
	{
		line = readline("Minishell > ");
		shell.cmd_line = fake_parse(line);
		if (shell.cmd_line == NULL)
			printf("Error: CTRL+D\n"); //da gestire con i segnali
		exec_main(&shell);
		free(line);
		//ft_lstclear((**shell), free);
	}
}