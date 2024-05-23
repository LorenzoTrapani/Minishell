/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:27:55 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buff1;
	unsigned char	*buff2;
	size_t			i;

	i = 0;
	buff1 = (unsigned char *)s1;
	buff2 = (unsigned char *)s2;
	while (i < n)
	{
		if (buff1[i] != buff2[i])
			return (buff1[i] - buff2[i]);
		else
			i++;
	}
	return (0);
}
/*int	main()
{
	char s1[10] = "ciaogss";
	char s2[10] = "ciaogss";
	int d = memcmp(s1, s2, 8);
	printf("%d", d);
	return 0;
}*/