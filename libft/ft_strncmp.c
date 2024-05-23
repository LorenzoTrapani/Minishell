/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:04:48 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:31:29 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		else
			i++;
	}
	return (0);
}
/*int main()
{
	char s1[200] = "";
	char s2[0] = "";
	int d = ft_strncmp(s1, s2, 6);
	printf("%d", d);
	return 0;
}*/