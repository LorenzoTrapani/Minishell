/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:51:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/12 18:51:46 by lotrapan         ###   ########.fr       */
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
	while (av && av[i])
	{
		dll_input_addback(&parse_line, dll_input_new(av[i]));
		i++;
	}
	return (parse_line);
}

void	shell_struct_init(t_all *shell, char **envp)
{
	shell->envp = set_env_lst(envp);
	shell->ep_copy = envp;
}

static size_t	ft_strlcpy_skip(char *dst, const char *src, size_t size, int skip)
{
	size_t	i;

	if (size == 0 || !src[skip])
		return (ft_strlen(src));
	i = skip;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t)ft_strlen(src));
}

void	change_env_variable(t_list *envp, char *var, char *new)
{
	t_list	*tmp;
	int		len;

	tmp = envp;
	len = ft_strlen(var);
	if (!new)
		return ;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var, len) == 0)
		{
			ft_strlcpy_skip(tmp->content, new, ft_strlen(new) + 1, len + 1);
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}
