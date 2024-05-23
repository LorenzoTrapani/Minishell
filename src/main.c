/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:16:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/21 16:45:47 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char	*shell;
	// t_builtin	ptr;
	// ptr = (t_builtin){0};
	// builtin_pwd(&ptr);
	// builtin_env(&ptr);
	while (42)
	{
		shell = readline("Minishell > ");
		parse_line(shell);

	}

}
