/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:26:09 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:31:20 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;	
	size_t	lensrc;
	size_t	i;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (size <= lendst)
		return (lensrc + size);
	while (src[i] && (lendst + i) < size - 1)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	if (lendst + i < size)
		dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
/*int	main()
{
	//char src[] = "daje roma da";
	char dst[14] = "a";
	//size_t size = 21;
	size_t p = ft_strlcat(dst, "lorem ipsum dolor sit amet", 15);
	printf("%zu", p);
	return (0);
}*/