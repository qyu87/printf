/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfoo <qfoo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:48:21 by qfoo              #+#    #+#             */
/*   Updated: 2025/08/04 10:48:21 by qfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_puthex(unsigned long num, char c)
{
	char	*hex = "0123456789ABCDEF";

    if (c == 'x')
        hex = "0123456789abcdef";
	if (num > 16)
		ft_puthex((num / 16), c);
	ft_putchar(hex[num % 16]);

}

int	ft_putptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
    if (!ptr)
    {
        write(1, "(nil)", 5);
        return (5);
    }
	write(1, "0x", 2);
	ft_puthex(address);
}

