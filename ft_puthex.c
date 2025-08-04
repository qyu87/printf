/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfoo <qfoo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:48:21 by qfoo              #+#    #+#             */
/*   Updated: 2025/08/04 16:54:38 by qfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, char c)
{
	char	*hex = "0123456789ABCDEF";
	int	count;

	count = 0;
    if (c == 'x')
    {
		hex = "0123456789abcdef";
	} 
	if (num > 16)
	{
		count += ft_puthex((num / 16), c);
	}
	ft_putchar(hex[num % 16]);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int	count;

	address = (unsigned long)ptr;
    if (!ptr)
    {
        write(1, "(nil)", 5);
        return (5);
    }
	write(1, "0x", 2);
	count = ft_puthex(address, 'x') + 2;
	return (count);
}

// int	main(void)
// {
// 	void	*ptr = "1234567";
// 	int	count;

// 	printf("%p\n", ptr);
// 	count = ft_putptr(ptr);
// 	printf("\n%d\n", count);
// 	return (0);
// }