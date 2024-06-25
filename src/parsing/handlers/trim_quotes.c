/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:34:50 by mgalmari          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:53 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_quotes(char *content)
{
	char	*new_content;
	char	*to_trim;
	int		len;

	len = ft_strlen(content) - 2;
	if (len < 0 || !content)
		return (NULL);
	else if (len == 0)
		return (ft_strdup(""));
	to_trim = ft_calloc(2, sizeof(char));
	if (!to_trim)
		return (NULL);
	to_trim[0] = content[0];
	new_content = ft_strtrim(content, to_trim);
	free(to_trim);
	return (new_content);
}

t_all	handle_trim_quotes(t_all all_info)
{
	t_input *tmp;

	tmp = all_info.cmd_line;
	while (tmp)
	{
		if (tmp->token == D_QUOTE || tmp->token == S_QUOTE)
			tmp->content = trim_quotes(tmp->content);
		if (!tmp->content)
			return (set_clear_all(&all_info), (t_all){0});
		tmp = tmp->next;
	}
	all_info = assign_quote_as_words_token(all_info);
	return (all_info);
}
