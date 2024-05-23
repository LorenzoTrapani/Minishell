/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:01:55 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/18 19:31:04 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int i)
{
	size_t	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static void	ft_digit(char *str, int n, int len)
{
	int	i;

	i = len - 1;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = intlen(n);
	if (n == -2147483648)
		return (ft_strdup ("-2147483648"));
	if (n == 0)
		return (ft_strdup ("0"));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_digit(str, n, len);
	return (str);
}
/*int main()
{
	int n = -248;
	char *str = ft_itoa(n);
	printf("%s\n", str);
	return (0);
}*/