/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:05:54 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/12 18:23:16 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i > 0 && i == n)
		i--;
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

/* int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!ptr1 || !ptr2)
		return(-1);
	while (((ptr1 && ptr1[i]) && (ptr2 && ptr2[i])) && i < n - 1)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
} */
/* int		main()
{
	const char s1[] = "test\200";
	const char s2[] = "test\0";
	size_t n = 6;

	ft_strncmp(s1, s2, n);
}
 */
