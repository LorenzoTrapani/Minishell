/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:18:39 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	size_t			i;

	i = 0;
	buff = (unsigned char *)s;
	while (i < n)
	{
		if (buff[i] != (unsigned char)c)
			i++;
		else
			return (buff + i);
	}
	return (0);
}
/*int	main()
{
	char *s = "daje roma daje";
	char c = 'r';
	char *p = ft_memchr(s, c, 4);
	printf("%s", p);
	return (0);
}*/