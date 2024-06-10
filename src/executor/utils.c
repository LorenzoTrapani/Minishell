/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:51:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/09 20:54:41 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_mtx(t_input *lst)
{
	int		i;
	int		len;
	char	**mtx;

	i = 0;
	len = dll_input_size(lst);
	mtx = malloc(sizeof(char *) * (len + 1));
	if (!mtx)
		return (NULL);
	while (lst)
	{
		mtx[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
		
	}
	mtx[i] = NULL;
	return(mtx);
}

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
	shell->ep_copy = envp;
}