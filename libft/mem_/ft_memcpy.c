/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:01:51 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	i = 0;
	p = (unsigned char *) dest;
	q = (unsigned char *) src;
	if (p == NULL && q == NULL)
		return (NULL);
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (p);
}
/*int main()
{
	char s[10] = "forse";
	char d[10] = "manyjdj";
	char *p = ft_memcpy(s, d, 3);
	printf("%s", p);
	return 0;
}*/