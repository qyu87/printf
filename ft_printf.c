/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfoo <qfoo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:58:33 by qfoo              #+#    #+#             */
/*   Updated: 2025/07/21 11:29:59 by qfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
}

void	ft_putnbr(long num)
{
	char	c;

	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	if (num >= 0 && num <= 9)
	{
		c = num + '0';
		ft_putchar(c);
	}
}

void	ft_putdec(double num)
{
	char	c;

	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	
	
}

int	check_specifier(char c, va_list arg_list)
{
	if (c == 'c')
		ft_putchar((char)va_arg(arg_list, int));
	else if (c == 's')
		ft_putstr(va_arg(arg_list, char *));
	// else if (c == 'p')
	// 	ft_putptr(va_arg(arg_list, void *));
	// else if (c == 'd')
	// 	ft_putdec((double)(va_arg(arg_list, int)));
	else if (c == 'i')
		ft_putnbr(va_arg(arg_list, int));
	// else if (c == 'u')
	// 	ft_putundec(va_arg(arg_list, unsigned int));
	// else if (c == 'x')
	// 	ft_putlhexa(va_arg(arg_list, char *));
	// else if (c == 'X')
	// 	ft_putuhexa(va_arg(arg_list, char *));
	else if (c == '%')
		ft_putchar('%');
	else
		ft_putchar(c);
	return (0);
}

int ft_printf(const char *format, ...)
{
	int i;
	va_list arg_list;

	va_start(arg_list, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_specifier(format[i + 1], arg_list);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg_list);
	return (0);
}

int	main(void)
{
	int	c = '!';
	char	*str = "nice";
	int	num = -123456789;

	ft_printf("mine = hello%c, %s, %i%%end\n", c, str, num);
	printf("ori. = hello%c, %s, %i%%end\n", c, str, num);
	// ft_putnbr(num);
	return (0);
}
