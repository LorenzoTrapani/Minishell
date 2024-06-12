/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:15:46 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/11 17:54:35 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "builtin.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>
# include <signal.h>


typedef struct	s_all	t_all;

typedef struct	s_input
{
	char			*content;
	int				token;
	struct s_input	*next;	
	struct s_input	*prev;
}	t_input;

typedef struct	s_all
{
	t_list			*envp;
	t_input			*cmd_line;	
	char			**ep_copy;
	int				exit_code;
}	t_all;

#endif