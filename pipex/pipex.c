/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:07:54 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/20 11:56:41 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pipex *pipex, char **envp, char **av)
{
	pipex->ep = envp;
	pipex->fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd[1] == -1)
		ft_error(pipex, 7);
	if (av[2][0] == '\0' || av[3][0] == '\0'
		|| ft_isspace(av[2][0]) || ft_isspace(av[3][0]))
		ft_error(pipex, 8);
	pipex->cmd1 = ft_split(av[2], ' ');
	pipex->cmd2 = ft_split(av[3], ' ');
	if (!pipex->cmd1 || !pipex->cmd2)
		ft_error(pipex, 8);
}

char	*get_path(t_pipex *pipex, char *cmd)
{
	char	*path;
	char	*part_path;
	char	*path_env;
	int		i;
	char	**paths;

	i = 0;
	path_env = find_path_in_env(pipex);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_array(paths);
	return (NULL);
}

void	child_exe(t_pipex *pipex)
{
	char	*path;

	dup2(pipex->pipefd[1], STDOUT_FILENO);
	close(pipex->pipefd[0]);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[0]);
	pipex->part_cmd1 = pipex->cmd1[0];
	path = get_path(pipex, pipex->part_cmd1);
	if (!path)
		ft_error(pipex, 3);
	if (execve(path, pipex->cmd1, pipex->ep) == -1)
		ft_error(pipex, 6);
}

void	child2_exe(t_pipex *pipex)
{
	char	*path;

	dup2(pipex->pipefd[0], STDIN_FILENO);
	close(pipex->pipefd[1]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[1]);
	pipex->part_cmd2 = pipex->cmd2[0];
	path = get_path(pipex, pipex->part_cmd2);
	if (!path)
		ft_error(pipex, 3);
	if (execve(path, pipex->cmd2, pipex->ep) == -1)
		ft_error(pipex, 6);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	pipex = (t_pipex){0};
	if (ac != 5)
		ft_error(&pipex, 1);
	pipex.fd[0] = open(av[1], O_RDONLY, 0777);
	if (pipex.fd[0] == -1)
		ft_error(&pipex, 2);
	init(&pipex, envp, av);
	if (pipe(pipex.pipefd) == -1)
		ft_error(&pipex, 4);
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		child_exe(&pipex);
	pipex.child2 = fork();
	if (pipex.child2 == -1 || pipex.child1 == -1)
		ft_error(&pipex, 5);
	if (pipex.child2 == 0)
		child2_exe(&pipex);
	close(pipex.pipefd[0]);
	close(pipex.pipefd[1]);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
	cleanup(&pipex);
	return (0);
}
