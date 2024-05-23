/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:04:06 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buff1;
	unsigned char	*buff2;

	buff1 = (unsigned char *)dest;
	buff2 = (unsigned char *)src;
	if (buff1 == NULL && buff2 == NULL)
		return (NULL);
	if (buff1 > buff2)
	{
		while (n > 0)
		{
			buff1[n - 1] = buff2[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(buff1, buff2, n);
	}
	return (dest);
}
/*int main()
{
	char src[] = "goku";
	char dest[] = "vegeta";
	ft_memmove(dest, src, 2);
	printf("%s", dest);
	return 0;
}*/