/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfoo <qfoo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:58:33 by qfoo              #+#    #+#             */
/*   Updated: 2025/08/04 17:42:00 by qfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// 1. create variable arg list (va list)
// 2. initialise arg list (va start)
// 3. loop thru format
// 	=> write all char in format 
// 	=> if got specifier then check which type 
// 	=> match specifier to arg from list 
//	=> increment arg (va arg)
// 4. write everything (write then meet specifier then write spec)
// 5. return +ve if correct

int	check_specifier(char c, va_list arg_list)
{
	if (c == 'c')
		ft_putchar((char)va_arg(arg_list, int));
	else if (c == 's')
		ft_putstr(va_arg(arg_list, char *));
	else if (c == 'p')
		ft_putptr(va_arg(arg_list, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg_list, int));
	else if (c == 'u')
		ft_putui(va_arg(arg_list, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(arg_list, unsigned int), c);
	else if (c == 'X')
		ft_puthex(va_arg(arg_list, unsigned int), c);
	else if (c == '%')
		ft_putchar('%');
	// else
	// 	ft_putchar(c);
	return (0);
}

int ft_printf(const char *format, ...)
{
	int i;
	int	count;
	va_list arg_list;

	va_start(arg_list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_specifier(format[i + 1], arg_list);
			i++;
			count--;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg_list);
	count += i;
	return (count);
}

int	main(void)
{
	int	count = 0;
	int	c = '!';
	// char	*str = "nice";
	int	num = 123456789;

	count = ft_printf("mine = %d%c\n", num, c);
	printf("ori. = %d%c\n", num, c);
	printf("%d", count);
	return (0);
}
