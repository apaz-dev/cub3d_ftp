/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:41:32 by apaz-pri          #+#    #+#             */
/*   Updated: 2024/09/26 09:30:48 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nint;
	int				s;

	i = 0;
	nint = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nint = (nint * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(nint * s));
}
