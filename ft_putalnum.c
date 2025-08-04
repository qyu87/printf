/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putalnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfoo <qfoo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:56:07 by qfoo              #+#    #+#             */
/*   Updated: 2025/08/04 17:37:30 by qfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

int count_digit(long num)
{
    int count;
    
    count = 0;
    if (num < 0)
    {
        count++;
        num = -num;
    }
    while (num > 9)
    {
        num /= 10;
        count++;
    }
    count++;
    return (count);
}

int	ft_putnbr(long num)
{
	char	c;
	int		count;

    count = count_digit(num);
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
	return (count);
}

int	ft_putui(unsigned long num)
{
	char	c;
	int		count;

	count = count_digit(num);
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
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	long	num = -12345678;
// 	int		count;

// 	count = ft_putnbr(num);
// 	printf("\nnumber of digits = %d\n", count);
// 	return (0);
// }
