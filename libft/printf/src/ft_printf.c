/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:35:57 by apaz-pri          #+#    #+#             */
/*   Updated: 2024/10/10 17:36:00 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_choose(va_list args, char format)
{
	if (format == 'c')
	{
		ft_print_char(va_arg(args, int));
		return (1);
	}
	if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (format == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long long)));
	if (format == 'd')
		return (ft_print_float(va_arg(args, int)));
	if (format == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_unsig_int(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		formatt;
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	formatt = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			formatt += ft_choose(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			counter++;
		}
	}
	return (counter + formatt);
}
