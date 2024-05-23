/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:49:54 by lotrapan          #+#    #+#             */
/*   Updated: 2023/10/28 17:40:15 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexupp(unsigned int nb)
{
	char		*b;
	int			i;

	i = 0;
	b = "0123456789ABCDEF";
	if (nb >= 16)
	{
		i += ft_puthexupp(nb / 16);
		i += ft_puthexupp(nb % 16);
	}
	else
		i += ft_putchar(b[nb]);
	return (i);
}

int	ft_puthex(uintptr_t nb, int k)
{
	char		*b;
	int			i;

	b = "0123456789abcdef";
	i = 0;
	if (!k && !nb)
		return (ft_putstr("(nil)"));
	if (!k)
		i += ft_putstr("0x");
	if (nb >= 16)
	{
		i += ft_puthex(nb / 16, 1);
		i += ft_puthex(nb % 16, 1);
	}
	else
		i += ft_putchar(b[nb]);
	return (i);
}

int	ft_putperc(char c)
{
	c = '%';
	write(1, &c, 1);
	return (1);
}
