/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <apaz-pri@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:25:22 by jose              #+#    #+#             */
/*   Updated: 2024/10/15 16:25:24 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_hex(unsigned int n, char *word)
{
	int		c;

	c = 0;
	c += ft_puthex(n, word);
	return (c);
}

int	ft_print_pointer(unsigned long long pointer)
{
	int		c;

	c = 2;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	c += ft_putpointer(pointer);
	return (c);
}

int	p_intlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_print_float(int nbr)
{
	int		c;

	c = 0;
	if (nbr == -2147483648)
		c += 11;
	else
		c += p_intlen(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	ft_print_unsig_int((unsigned int)nbr);
	return (c);
}
