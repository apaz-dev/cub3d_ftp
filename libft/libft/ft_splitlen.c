/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:45:29 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/24 12:46:09 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_splitlen(char **split_out)
{
	size_t	out;

	if (!split_out)
		return (0);
	out = 0;
	while (split_out[out])
		out++;
	return (out);
}