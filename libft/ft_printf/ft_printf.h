/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:09:15 by lotrapan          #+#    #+#             */
/*   Updated: 2023/10/28 17:26:51 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunnbr(unsigned int nb);
int		ft_puthexlow(unsigned int nb);
int		ft_puthexupp(unsigned int nb);
int		ft_putperc(char c);
int		ft_puthex(uintptr_t nb, int k);
int		ft_printf(const char *input, ...);

#endif