/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:08:50 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/09 20:53:34 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	handle_sigquit(int sig)
{
	printf("SIGQUIT: %d\n", sig);
	return ;
} 

 static void	handle_sigint(int sig)
{
	printf("\nSIGINT: %d\n", sig);
}
void	signal_handle(t_all *shell)
{
	static int	init = 0;

	if (shell->cmd_line == NULL) //CTRL + D
	{
		ft_printf(1, "exit\n");
		exit (0);
	}
	if (!init)
	{
		if (signal(SIGINT, handle_sigint) == SIG_ERR) // CTRL + C
		{
			printf("Cannot handle SIGINT\n");
    	    exit(2);
		}
		init = 1;
	}
	 if (signal(SIGQUIT, handle_sigquit) == SIG_ERR)  CTRL + 
	{
		printf("Cannot handle SIGQUIT\n");
        exit(20);
	} 
	return ;
} */