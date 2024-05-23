/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:14 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/24 15:40:07 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_array(char **buff, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static char	**ft_norm(char const *s, size_t words)
{
	char	**buff;

	if (!s)
		return (NULL);
	buff = malloc(sizeof(char *) * (words + 1));
	if (!buff)
		return (NULL);
	return (buff);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	size_t	word_len;
	size_t	i;
	size_t	words;

	words = ft_countword(s, c);
	buff = NULL;
	buff = ft_norm (s, words);
	i = 0;
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		buff[i] = ft_substr(s, 0, word_len);
		if (!(buff[i]))
			return (ft_free_array(buff, i));
		s += word_len;
		i++;
	}
	buff[i] = NULL;
	return (buff);
}
/* int main()
{
	//char *str = "          ";
	char **tab = ft_split("c                 ", ' ');
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
} */