#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_all t_all;
typedef struct	s_input t_input;
typedef struct	s_parsing t_parsing;

// --- Parsing --- //

// -Expansion- //
//Expand_with_quotes
int			check_dollar_sign(char *str);
void    	new_content_copy(char *new_content, char *content, char *env, int len);
char		*get_content_with_quotes(char *content, char *env);
//Expand
void		*expand_env(char *content, t_all all_info);
void		*expand_env_with_quotes(char *content, t_all all_info);
t_all		expand_dollar_sign(t_all all_info);
//Get_env
char		*get_expansion(t_list *envp, char *name_env);
char		*get_name_env(char *str);
char		*get_env(char *str, t_all all_info);
//Handling_env
int			find_len_env(t_list *envp, char *name_env);
char		*find_expansion_env(t_list *envp, char *name_env);

// Get_all_info
t_parsing	parse_input(t_parsing parsing);
t_input		*create_list_from_input(t_parsing parsing);
t_list		*create_list_from_envp(char **envp);
t_all		get_all_info(t_all all_info, char *line, char **envp);
// Get_arr_token
int			get_word_token(int token);
int			find_token(char *str);
int			first_token_check(t_parsing parsing);
int			*analyse_words_token(t_parsing parsing);
int			*get_arr_token(t_parsing parsing);
// Get_input_complete
t_all		trim_quotes_and_merge(t_all all_info);
t_all		get_input_complete(t_all all_info, char *line, char **envp);
// Get_merged_cmd_line
char		*get_new_content(t_input **cmd_line);
char		*merge_content(t_input *cmd_line, char *new_content);
t_input		*get_merged_cmd_line(t_input *cmd_line);
// Get_mtx_input
int			count_words(char *s);
int			word_len(char *s);
char		**new_string(char **mtx, char *s);
char		**get_mtx_from_input(t_parsing parsing);
// Handling_char
int			check_spaces(char c);
int			handle_quotes(char *s);
int			handle_operators(char *s);
int			handle_not_spaces(char *s);
int			get_len_word(char *str, int	index);
int			get_index_special_char(char *str, char c);
// Handling_merge_flag
int			find_merge_flag_quote(char *input, int i);
int			find_merge_flag_dollar_sign(char *input, int i);
int			find_which_merge_flag(char *input, int i, int token);
t_input		*switch_merge_flag(t_input *cmd_line, int token_nbr, int which_merge);
t_input		*handle_merge_flag(char *input, t_input *cmd_line, int token_nbr, int i);
t_input		*check_if_need_merge(t_parsing parsing, t_input *cmd_line);
// Handling_token
int			check_if_operator(int token);
// Trim_quotes
t_input		*handle_trim_quotes(t_input *cmd_line);
char		*trim_quotes(char *content);

// Free_exit_handling
void	free_parsing(t_parsing *parsing);
void	free_all(t_all *all);
void	close_all(t_all *all);

// Lst_input_handling
void		dll_input_addback(t_input **lst, t_input *new);
void		dll_input_addfront(t_input **lst, t_input *new);
void		dll_input_clear(t_input **lst);
t_input		*dll_input_last(t_input *lst);
t_input		*dll_input_new(char *content);
int			dll_input_size(t_input *lst);

#endif