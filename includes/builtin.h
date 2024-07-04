/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:24:46 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/04 19:04:48 by lotrapan         ###   ########.fr       */
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
int					builtin_env(t_all *shell);
void				print_env(t_list *envp);
/*------------------EXIT------------------*/
int					builtin_exit(t_all *shell, t_input *cmd_line);
unsigned int		ft_uatoi(const char *str);
int					numeric_check(t_input *cmd_line);
/*------------------PWD------------------*/
void				builtin_pwd(void);
/*------------------CD------------------*/
int					builtin_cd(t_all *shell, t_input *cmd_line);
/*------------------UNSET------------------*/
int					builtin_unset(t_input *cmd, t_list *envp);
void				del_env_variable(t_list **envp, char *word);
int					unset_syntax(char *str);
/*------------------EXPORT------------------*/
int					builtin_export(t_all *shell);
void	            print_export(t_list *envp);
void            	export_add(t_all *shell);
/*------------------EXPORT_UTILS------------------*/
int					equal_check(char *str);
int					doppelganger_check(t_list *envp, char *str, int len);
void				change_node_env(t_list **envp, char *key, int eq);
/*------------------EXEC_MAIN------------------*/
void				exec_command(t_all *shell, t_input *cmd_line);
int					exec_main(t_all *shell);
/*------------------EXEC_UTILS------------------*/
void				exec_builtin(t_all *shell);
bool				is_builtin(t_all *shell);
int	                count_commands(t_input *cmd_line);
t_all           	*init_pipe(t_all *shell, int cmd_num);
/*------------------EXEC_FREE------------------*/
void				close_pipes(t_all *shell);
void 				free_pipes(t_all *shell);
/*------------------SIGNAL------------------*/
int					signal_handle(char *str);
/*------------------ENVP_UTILS------------------*/
void				add_node_env(t_list **envp, char *str);
t_list				*change_env_variable(t_list *envp, char *var, char *new);
char				*find_word_in_env(t_list *envp, char *word);
t_list				*find_node_in_env(t_list *envp, char *word, int len);
/*------------------UTILS------------------*/
char				*get_path(t_all *shell, char *cmd);
char				**lst_to_mtx(t_list *envp);
void				print_mtx(char **mtx);
int					ft_strcmp(const char *s1, const char *s2);


int					dll_input_size(t_input *lst);
t_input				*dll_input_last(t_input *lst);
void				dll_input_addback(t_input **lst, t_input *new);
t_input				*dll_input_new(char *content);

#endif