/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:13 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/04 20:56:17 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	add_node(t_list **a, char *str)
{
	t_list	*new;
	t_list	*last_node;

	if (a == NULL)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->str = str;
	if (str[0] == '-')
		new->token = 1;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		new->next = NULL;
	}
	else
	{
		last_node = *a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
		new->prev = last_node;
	}
}

t_list   	*fake_parse(char *input)
{
	char	**av;
	int 	i;
	t_list	*parse_line = NULL; 

	i = 0;
	av = ft_split(input, ' ');
	while (av[i])
	{
		add_node(&parse_line, av[i]);
		i++;
	}
	free(av);
	return (parse_line);
}
int main()
{
	char	*line;
	t_list	shell;

	shell = (t_list){0};
	while (42)
	{
		line = readline("Minishell > ");
		shell = *fake_parse(line);
		if (shell.str == NULL)
			printf("Error\n");
		/*if (!av)
			builtin_exit(NULL); */
		if (ft_strncmp(shell.str, "exit", 5) == 0)
			builtin_exit(&shell);
		if (ft_strncmp(shell.str, "echo", 5) == 0)
			builtin_echo(&shell);
		if (line != NULL)
			free(line);
		//ft_lstclear((**shell), free);
	}
}