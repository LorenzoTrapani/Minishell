/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:24:46 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/12 18:38:21 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

typedef struct s_all t_all;
typedef struct	s_input t_input;

/*------------------ECHO------------------*/
void				builtin_echo(t_input *cmd_line);
void				print_echo(t_input *tmp);
int					char_rep_check(char *str, char c);
/*------------------ENV------------------*/
void				builtin_env(t_input *cmd_line, t_list *envp);
/*------------------EXIT------------------*/
int					builtin_exit(t_all *shell, t_input *cmd_line);
unsigned int		ft_uatoi(const char *str);
int					numeric_check(t_input *cmd_line);
/*------------------PWD------------------*/
void				builtin_pwd(void);
/*------------------CD------------------*/
int					builtin_cd(t_all *shell, t_input *cmd_line);
/*------------------EXEC------------------*/
bool				is_builtin(t_all *shell);
void				exec_builtin(t_all *shell);
int					exec_main(t_all *shell);
void				exec_command(t_all *shell, t_input *cmd_line);
/*------------------SIGNAL------------------*/
int					signal_handle(char *str);
/*------------------FREE------------------*/
void				cleanup(t_all *shell);
void				dll_input_clear(t_input **lst);
/*------------------FAKE_PARSE------------------*/
t_list				*set_env_lst(char **envp);
t_input   			*fake_parse(char *input);
void				shell_struct_init(t_all *shell, char **envp);
char				*find_word_in_env(t_list *envp, char *word);
/*------------------UTILS------------------*/
char				**lst_to_mtx(t_input *lst);
void				change_env_variable(t_list *envp, char *var, char *new);


int					dll_input_size(t_input *lst);
t_input				*dll_input_last(t_input *lst);
void				dll_input_addback(t_input **lst, t_input *new);
t_input				*dll_input_new(char *content);

#endif