/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:56:35 by apaz-pri          #+#    #+#             */
/*   Updated: 2024/09/26 10:25:26 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len2str(const char *s, char c)
{
	size_t	str;

	str = 0;
	while (*s)
	{
		if (*s != c)
		{
			++str;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_len2str(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}
