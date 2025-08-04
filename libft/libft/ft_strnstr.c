/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:12:17 by apaz-pri          #+#    #+#             */
/*   Updated: 2024/09/26 10:37:20 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*str_tmp;
	char	*to_find_tmp;
	size_t	i;

	if (!ft_strlen(to_find))
		return ((char *)str);
	if (!ft_strlen(str) || len < ft_strlen(to_find))
		return (0);
	i = len - ft_strlen(to_find) + 1;
	while (i-- && *str)
	{
		str_tmp = (char *)str;
		to_find_tmp = (char *)to_find;
		while (*to_find_tmp && *to_find_tmp == *str_tmp)
		{
			++str_tmp;
			++to_find_tmp;
		}
		if (!*to_find_tmp)
			return ((char *)str);
		++str;
	}
	return (0);
}
