/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:18:28 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/07 22:31:02 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_in_env(t_list *envp)
{
	int	i;
	char *str;

	i = 0;
	while (envp)
	{
		str = (char *)envp->content;
		if (ft_strncmp(&str[i], "PATH=", 5) == 0)
			return (&str[i] + 5);
		envp = envp->next;
	}
	return (NULL);
}

char	*get_path(t_all *shell, char *cmd)
{
	char	*path;
	char	*part_path;
	char	*path_env;
	int		i;
	char	**possible_paths;

	i = 0;
	path_env = find_path_in_env(shell->envp); //prendo la riga dell PATH dall'env
	if (!path_env)
		return (NULL);
	possible_paths = ft_split(path_env, ':'); //mtx di tutte le path possibili
	if (!possible_paths)
		return (NULL);
	while (possible_paths[i])
	{
		part_path = ft_strjoin(possible_paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0) // contolla se esiste e se e' eseguibile 
			return (path);
		free(path);
		i++;
	}
	free_mtx(possible_paths);
	return (NULL);
}

void	exec_builtin(t_all *shell)
{
	if (ft_strncmp(shell->cmd_line->content, "exit", 4) == 0)
		builtin_exit(shell->cmd_line);
	if (ft_strncmp(shell->cmd_line->content, "echo", 4) == 0)
		builtin_echo(shell->cmd_line);
	if (ft_strncmp(shell->cmd_line->content, "env", 3) == 0)
		builtin_env(shell->cmd_line, shell->envp);
	if (ft_strncmp(shell->cmd_line->content, "pwd", 3) == 0)
		builtin_pwd();
	if (ft_strncmp(shell->cmd_line->content, "cd", 2) == 0)
		builtin_cd(shell->cmd_line);
}

bool	is_builtin(t_all *shell)
{
	if (ft_strncmp(shell->cmd_line->content, "exit", 4) == 0)
		return (true);
	if (ft_strncmp(shell->cmd_line->content, "echo", 4) == 0)
		return (true);
	if (ft_strncmp(shell->cmd_line->content, "env", 3) == 0)
		return (true);
	if (ft_strncmp(shell->cmd_line->content, "pwd", 3) == 0)
		return (true);
	if (ft_strncmp(shell->cmd_line->content, "cd", 2) == 0)
		return (true);
	return (false);
}

void	exec_command(t_all *shell, t_input *cmd_line)
{
	pid_t	pid;
	char	*path;
	char	**cmd;

	cmd = lst_to_mtx(cmd_line); //da gestire in futuro(pipe, redirect, ...)
	path = get_path(shell, cmd[0]);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmd, shell->ep_copy) == -1)
		{
			printf("%s: command not found\n", cmd[0]);
			exit(127);
		}
	}
	waitpid(pid, NULL, 0);
}

int	exec_main(t_all *shell)
{
	if (is_builtin(shell) /*&& no pipe*/)
		exec_builtin(shell);
	else if (!is_builtin(shell))
		exec_command(shell, shell->cmd_line);
	//fork
	//child_process
	return (1);
}