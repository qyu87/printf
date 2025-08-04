/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfoo <qfoo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:41:52 by qfoo              #+#    #+#             */
/*   Updated: 2025/08/04 18:09:26 by qfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// printf.c
int	check_specifier(char c, va_list arg_list);
int	ft_printf(const char *format, ...);
// putalnum.c
int	ft_putchar(char c);
int	ft_putstr(char *c);
int	count_digit(long num);
int	ft_putnbr(long num);
int	ft_putui(unsigned long num);
// puthex.c
int	ft_puthex(unsigned long num, char c);
int	ft_putptr(void *ptr);

#endif