/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:33:14 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/23 19:25:51 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*find_path_in_env(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->ep[i])
	{
		if (ft_strncmp(pipex->ep[i], "PATH=", 5) == 0)
			return (pipex->ep[i] + 5);
		i++;
	}
	return (NULL);
}

void	cleanup(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	free_array(pipex->cmd1);
	free_array(pipex->cmd2);
	free(pipex->part_cmd1);
	free(pipex->part_cmd2);
}

void	ft_error(t_pipex *pipex, int i)
{
	if (i == 1)
	{
		ft_putstr_fd("Error: wrong number of arguments.\n", 2);
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n", 2);
	}
	if (i == 2)
		ft_putstr_fd("Error: infile not found\n", 2);
	if (i == 3)
		ft_putstr_fd("Error: PATH not found\n", 2);
	if (i == 4)
		ft_putstr_fd("Error: pipe creation failed\n", 2);
	if (i == 5)
		ft_putstr_fd("Error: fork creation failed\n", 2);
	if (i == 6)
		ft_putstr_fd("Error: esteban failed\n", 2);
	if (i == 7)
		ft_putstr_fd("Error: outfile failed\n", 2);
	if (i == 8)
		ft_putstr_fd("Error: cmd not found\n", 2);
	cleanup(pipex);
	exit(1);
}
