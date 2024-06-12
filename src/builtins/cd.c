/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:44:34 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/12 19:00:19 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	str_replace_env(t_list *envp, char *str)
{
	char	*new;

	i = 0;
	tmp = envp;
	if (!new)
		return ;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, str, 3) == 0)
		{
			ft_strlcpy_skip(tmp->content, new, ft_strlen(new) + 1, 4);
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

static int	update_envp(t_all *shell)
{
	str_replace_env(shell->envp, "PWD");
	return (0);
}

static int	cd_home(char *home_dir)
{
	if (chdir(home_dir) == 0)
		return (0);
	else
		return(ft_printf(1, "minishell: cd: " "%s: Error home\n", home_dir));
}
int	builtin_cd(t_all *shell, t_input *cmd_line)
{
	char	*dir;
	char	*old_pwd;

	dir = NULL;
	old_pwd = NULL;
	if (!cmd_line->next)
		return (cd_home(find_word_in_env(shell->envp, "HOME=")));
	if (dll_input_size(cmd_line) > 2)
		return (ft_printf(1, "minishell: cd: too many arguments\n"));
	cmd_line = cmd_line->next;
	dir = cmd_line->content;
	old_pwd = getcwd(NULL, 0);
	if (chdir(dir) == 0)
		return (update_envp(shell, old_pwd));
	else
		return(ft_printf(1, "minishell: cd: " "%s: No such file or directory\n", dir));
}
