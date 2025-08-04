/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:33:54 by apaz-pri          #+#    #+#             */
/*   Updated: 2024/10/10 17:33:59 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../../libft/libft.h"

int		p_intlen(int num);
int		ft_printf(char const *format, ...);
int		ft_print_str(char *str);
int		ft_print_int(int nbr);
int		ft_print_float(int nbr);
int		ft_print_unsig_int(unsigned int n);
int		ft_puthex(unsigned int nbr, char *base);
int		ft_print_hex(unsigned int n, char *word);
int		ft_print_pointer(unsigned long long pointer);
int		ft_putpointer(unsigned long long pointer);
void	ft_print_char(int c);

#endif