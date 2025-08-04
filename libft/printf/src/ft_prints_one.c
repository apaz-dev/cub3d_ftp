/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <apaz-pri@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:08 by jose              #+#    #+#             */
/*   Updated: 2024/10/15 16:26:09 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i += write(1, "(null)", 6);
	if (!str)
		return (6);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int nbr)
{
	int		c;

	c = 0;
	if (nbr == -2147483648)
		c += 11;
	else
		c += p_intlen(nbr);
	ft_putnbr_fd(nbr, 1);
	return (c);
}

int	ft_print_unsig_int(unsigned int n)
{
	int		c;

	c = 0;
	if (n == 0)
	{
		c++;
		ft_print_char('0');
	}
	else
	{
		if (n / 10 != 0)
			ft_print_unsig_int(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
		while (n > 0)
		{
			n /= 10;
			c++;
		}
	}
	return (c);
}
