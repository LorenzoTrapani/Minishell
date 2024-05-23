/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:57:52 by lotrapan          #+#    #+#             */
/*   Updated: 2023/10/28 17:37:09 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		i++;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_putunnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_puthexlow(unsigned int nb)
{
	char		*b;
	int			i;

	b = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
	{
		i += ft_puthexlow(nb / 16);
		i += ft_puthexlow(nb % 16);
	}
	else
		i += ft_putchar(b[nb]);
	return (i);
}
