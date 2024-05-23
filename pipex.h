/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:07:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/24 17:08:59 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

typedef struct s_pipex
{
	char	**ep;
	int		pipefd[2];
	int		fd[2];
	char	*part_cmd1;
	char	*part_cmd2;
	char	**cmd1;
	char	**cmd2;
	pid_t	child1;
	pid_t	child2;
}	t_pipex;

void	init(t_pipex *pipex, char **ep, char **av);
void	child_exe(t_pipex *pipex);
void	child2_exe(t_pipex *pipex);
void	free_array(char **str);
char	*find_path_in_env(t_pipex *pipex);
char	*get_path(t_pipex *pipex, char *cmd);
void	ft_error(t_pipex *pipex, int i);
void	cleanup(t_pipex *pipex);

#endif