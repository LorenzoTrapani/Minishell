/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:50:33 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:31:32 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while ((i < len) && (big[i] != '\0'))
	{
		k = 0;
		while ((big[i + k] == little[k]) && (i + k < len))
		{
			if (little[k + 1] == '\0')
				return ((char *)big + i);
			k++;
		}
		i++;
	}
	return (0);
}
/*int	main()
{
	char big[] = "lorem ipsum dolor sit amet";
	char little[] = "ipsumm";
	
	printf("%s", ft_strnstr(big, little, 30));
	return (0);
}*/