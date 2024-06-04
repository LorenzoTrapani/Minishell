/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:15:46 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/04 15:34:58 by lotrapan         ###   ########.fr       */
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
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>

// # define ECHO "echo";
# define CD "cd";
# define PWD "pwd";
# define EXPORT "export";
# define UNSET "unset";
# define ENV "env";
# define EXIT "exit";

typedef struct	s_all	t_all;

typedef struct	s_all
{
	
	t_list				*av;
	struct s_all		*next;
	struct s_all		*prev;	
}	t_all;

t_all   parse_line(char *input);

#endif