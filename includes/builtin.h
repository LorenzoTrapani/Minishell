/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:24:46 by lotrapan          #+#    #+#             */
/*   Updated: 2024/06/04 20:11:59 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTIN_H
# define BUILTIN_H

int					builtin_exit(t_list *shell);
int					check_bash_size(long nbr);
unsigned int		ft_uatoi(const char *str);
void				builtin_echo(t_list *shell);
int					char_rep_check(char *str, char c);
t_list   			*fake_parse(char *input);
int					numeric_check(t_list *shell);

#endif