/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:25:06 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/01/02 17:59:27 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	gft_strlen(const char *str);
size_t	gnl_ft_strlcpy(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
char	*gnl_ft_strchr(const char *str, int c);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);
char	*gnl_ft_strjoin(char *s1, char *s2);
void	*gnl_ft_alloc(size_t count, size_t size);

#endif
