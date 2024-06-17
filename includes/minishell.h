/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:15:46 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/17 18:43:34 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "builtin.h"
# include "parsing.h"
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


// # define ECHO "echo";
# define CD "cd";
# define PWD "pwd";
# define EXPORT "export";
# define UNSET "unset";
# define ENV "env";
# define EXIT "exit";


typedef struct	s_all	t_all;

typedef enum	e_quotes
{
	STAY,
	MERGE_PREV,
	MERGE_NEXT,
	MERGE_BOTH,
}	t_quotes;

typedef enum	e_token
{
	VOID,
	WORDS,
	ARG,
	CMD,
	FILE_W,
	EOF_DEL,
	DOLLAR_SIGN,
	PIPE,
	R_INPUT,
	R_OUTPUT,
	D_RED_INPUT,
	D_RED_OUTPUT,
	D_QUOTE,
	S_QUOTE,
}	t_token;

typedef struct	s_input
{
	char			*content;
	char			**args;
	int				token;
	int				merge;
	struct s_input	*next;	
	struct s_input	*prev;
}	t_input;

typedef struct	s_parsing
{
	char	*input;
	char	**mtx_from_input;
	int		*arr_token;
	int		size;
}	t_parsing;

typedef struct	s_all
{
	t_list			*envp;
	t_input			*cmd_line;	
	char			**ep_copy;
	int				exit_code;
}	t_all;

#endif
