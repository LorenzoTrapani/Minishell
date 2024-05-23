/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:36:58 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:31:43 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (*start != '\0' && ft_strchr(set, *start) != NULL)
		start++;
	while (end > start && ft_strchr(set, *end) != NULL)
		end--;
	return (ft_substr(s1, start - s1, end - start + 1));
}
/*int	main()
{
	char s1[] = "daje ";
	char s2[] = "dje ";
	printf("%s", ft_strtrim(s1, s2));
	return (0);
}*/