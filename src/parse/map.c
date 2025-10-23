/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:49:55 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 19:16:36 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Si el archivo empieza por caracter (no numero) y lo sigue otro caracter
	(no numero) = TEXTURA
	Si el archivo empieza por caracter (no numero) y no lo sigue otro caracter
	(no numero) = COLOR
	Si el archivo empieza por numero y lo sigue otro numero = MAPA
*/
static int what_is(t_game *game, int i, int j, char **map)
{
	while (ft_isspace(map[i][j]))
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1]) 
		&& !ft_isdigit(map[i][j + 1]))
		{
			if (add_texture(game, map[i][j]) == 1)
				return (ft_printf_fd(1, "Error al añadir textura\n"), -42);
			return (1);
		}
		else
		{
			if (add_color(game, map[i][j]) == 1)
				return (ft_printf_fd(1, "Error al añadir color\n"), -42);
			return (1);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (add_map(game, i, j, map) == 1)
			return (ft_printf_fd(1, "Error al añadir mapa\n"), -42);
		return (0);
	}
	return (0);
}

int add_data(t_game *game, char **map)
{
	int i;
	int j;
	int err;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			err = what_is(game, i, j, map);
			if (err == -42)
				break ;
			else if (err == 1)
				return (1);
			else
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}