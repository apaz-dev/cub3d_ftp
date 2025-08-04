/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <apaz-pri@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:25:33 by jose              #+#    #+#             */
/*   Updated: 2024/10/15 16:25:36 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putpointer(unsigned long long pointer)
{
	char	*base;
	int		c;

	base = "0123456789abcdef";
	c = 0;
	if (pointer >= 16)
	{
		c += ft_putpointer(pointer / 16);
		c += ft_putpointer(pointer % 16);
	}
	else
	{
		if (pointer < 10)
		{
			ft_putchar_fd(pointer + '0', 1);
			c++;
		}
		else
		{
			ft_putchar_fd(base[pointer % 16], 1);
			c++;
		}
	}
	return (c);
}

void	do_baseh(unsigned int nbr, unsigned int nbase, char *base, int *c)
{
	if (nbr < nbase)
	{
		ft_putchar_fd(base[nbr % nbase], 1);
		++(*c);
	}
	else
	{
		do_baseh(nbr / nbase, nbase, base, c);
		ft_putchar_fd(base[nbr % nbase], 1);
		++(*c);
	}
}

unsigned int	ft_len_errorsh(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] < 32)
			return (-1);
		i++;
	}
	i = 0;
	while (base[i] != 0)
		++i;
	return (i);
}

int	ft_puthex(unsigned int nbr, char *base)
{
	unsigned int	nbase;
	int				c;

	c = 0;
	nbase = ft_len_errorsh(base);
	if (nbase >= 2)
	{
		do_baseh(nbr, nbase, base, &c);
	}
	return (c);
}
