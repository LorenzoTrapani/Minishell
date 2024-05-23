/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:05:02 by lotrapan          #+#    #+#             */
/*   Updated: 2023/10/30 14:15:54 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list args, const char s)
{
	int	i;

	i = 0;
	if (s == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'p')
		return (ft_puthex(va_arg(args, uintptr_t), 0));
	else if (s == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'u')
		return (ft_putunnbr(va_arg(args, unsigned int)));
	else if (s == 'x')
		return (ft_puthexlow(va_arg(args, unsigned int)));
	else if (s == 'X')
		return (ft_puthexupp(va_arg(args, unsigned int)));
	else if (s == '%')
		return (ft_putperc(s));
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i += ft_type(args, *input);
		}
		else
			i += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (i);
}

// int main()
// {
// 	int i = 0;
// 	//char *c = "fdf";
// 	i = ft_printf("%s %d %i %%\n", "-42", 2 ,2);
// 	ft_printf("%d\n", i);
// 	return (0);
// }