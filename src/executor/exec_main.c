/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:18:28 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/17 17:55:01 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_all *shell, t_input *cmd_line)
{
	char	*path;
	char	**cmd;
	char	**envp;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	cmd = cmd_line->args;
	envp = lst_to_mtx(shell->envp);
	path = get_path(shell, cmd[0]);
	if ((!path) || (execve(path, cmd, envp) == -1))
	{
		ft_printf(2, "%s: command not found\n", cmd[0]);
		free_all(shell);
		close_exec_fd();
		free_mtx(envp);
		exit(127);
	}
}

void	child_exe(t_all *shell, t_input *current)
{
	if (is_builtin(current))
	{
		exec_builtin(shell);
		if (shell && shell->std_fd_in > 2)
			close(shell->std_fd_in);
		if (shell && shell->std_fd_out > 2)
			close(shell->std_fd_out);
		free_pipes(shell);
		free_all(shell);
		close_exec_fd();
		exit(g_status_code);
	}
	else
		exec_command(shell, current);
}

void	pipe_init(t_all *shell, t_input *current, int i, int num_pipes)
{
	if (i > 0 && shell->pipes)
		dup2(shell->pipes[i - 1][0], STDIN_FILENO);
	if (num_pipes > 0 && shell->pipes)
		dup2(shell->pipes[i][1], STDOUT_FILENO);
	if (current->fd_in > 2)
	{
		dup2(current->fd_in, STDIN_FILENO);
		close(current->fd_in);
	}
	if (current->fd_out > 2)
	{
		dup2(current->fd_out, STDOUT_FILENO);
		close(current->fd_out);
	}
	close_pipes(shell);
}

int	count_pipe(t_input *cmd_line)
{
	int		i;
	t_input	*tmp;

	i = 0;
	tmp = cmd_line;
	while (tmp)
	{
		if (tmp->token == PIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_input	*find_next_block(t_input *current)
{
	while (current)
	{
		if (current->token == PIPE)
			return (current->next);
		current = current->next;
	}
	return (NULL);
}

void	exec_main(t_all *shell)
{
	int		i;
	int		cmd_num;
	int		num_pipes;
	pid_t	pid;
	t_input	*current;
	t_input	*cmd;

	i = 0;
	current = shell->cmd_line;
	cmd_num = count_commands(current);
	num_pipes = count_pipe(shell->cmd_line);
	shell->std_fd_in = dup(STDIN_FILENO);
	shell->std_fd_out = dup(STDOUT_FILENO);
	handle_redirect(shell);
	shell = create_pipe(shell, num_pipes);
	if (cmd_num == 1 && is_builtin(current))
		return (pipe_init(shell, current, i, num_pipes),
				exec_builtin(shell));
	signal(SIGINT, handle_sigint_exec);
	while (current)
	{
		cmd = find_cmd_in_block(current);
		if (cmd)
		{
			pid = fork();
			if (pid == -1)
			{
				ft_printf(2, "Error: fork\n");
				exit(1);
			}
			if (pid == 0)
			{
				pipe_init(shell, current, i, num_pipes); //forse qui?
				child_exe(shell, current);
			}
		}
		current = find_next_block(current);
		num_pipes--;
		i++;
	}
	close_pipes(shell);
	while (wait(&g_status_code) != -1)
	{
		if (WIFEXITED(g_status_code))
			g_status_code = WEXITSTATUS(g_status_code);
		else if (WIFSIGNALED(g_status_code))
			handle_signal_child(WTERMSIG(g_status_code));
	}
	free_pipes(shell);
	dup2(shell->std_fd_in, STDIN_FILENO);
	dup2(shell->std_fd_out, STDOUT_FILENO);
	close(shell->std_fd_in);
	close(shell->std_fd_out);
	close_exec_fd();
}
