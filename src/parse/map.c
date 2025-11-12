/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:49:55 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/11/12 13:54:34 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Si la linea tiene los 2 caracteres primeros imprimibles (no numeros)
	y son NO, SO, WE, EA = TEXTURA
*/
int add_texture(t_texture *text, char *line, int s)
{
	if (line[s + 2] && ft_isprint(line[s + 2]) && !ft_isdigit(line[s + 2]))
		return (1);
	else
	{
		if (line[s] == 'N' && line[s + 1] == 'O')
			text->no = ft_strdup(&line[s + 3]);
		else if (line[s] == 'S' && line[s + 1] == 'O')
			text->so = ft_strdup(&line[s + 3]);
		else if (line[s] == 'W' && line[s + 1] == 'E')
			text->we = ft_strdup(&line[s + 3]);
		else if (line[s] == 'E' && line[s + 1] == 'A')
			text->ea = ft_strdup(&line[s + 3]);
		else
			return (1);
	}
	return (0);
}

int *color_to_int(char *line)
{
	char 	**rgb;
	int 	*color;
	int		i;

	rgb = ft_split(line, ',');
	if (!rgb)
		return (NULL);
	if (ft_splitlen(rgb) != 3)
		return (free_array((void **)rgb), NULL);
	color = malloc(sizeof(int) * 3);
	if (!color)
		return (free_array((void **)rgb), NULL);
	i = -1;
	while (rgb[++i])
	{
		color[i] = ft_atoi(rgb[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			free_array((void **)rgb);
			free(color);
			return (NULL);
		}
	}
	free_array((void **)rgb);
	return (color);
}

/*
	El primer caracter imprimible (no numero) es F o C = COLOR
*/
int add_color(t_texture *text, char *line, int s)
{
	if (line[s + 1] && (ft_isprint(line[s + 1]) && !ft_isdigit(line[s + 1])))
		return (1);
	else
	{
		if (line[s] == 'F')
			text->f = color_to_int(line + s + 2);
		else if (line[s] == 'C')
			text->c = color_to_int(line + s + 2);
		else
			return (1);
	}
	return (0);
}

int count_map_height(char **map, int s, t_game *game)
{
	int static_start;
	int i;

	static_start = s;
	while (map[s])
	{
		i = 0;
		while (ft_isospace(map[s][i]))
			i++;
		if (map[s][i] != '1')
			break;
		s++;
	}
	game->filemap.end = s;
	return (s - static_start);
}

size_t find_biggest_len(t_filemap fmap, int s)
{
	size_t	max;

	max = ft_strlen(fmap.data[s]);
	while (fmap.data[s])
	{
		if (ft_strlen(fmap.data[s]) > max)
			max = ft_strlen(fmap.data[s]);
		s++;
	}
	return (max);
}

static int copy_map(t_filemap fmap, int s, char **map)
{
	int i;
	int j;

	fmap.width = find_biggest_len(fmap, s);
	i = 0;
	while (i < fmap.height)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (fmap.width + 1));
		if (!map[i])
			return (ERROH);
		while (fmap.data[s][j] && fmap.data[s][j] != '\n')
		{
			map[i][j] = fmap.data[s][j];
			j++;
		}
		while (j < fmap.width)
			map[i][j++] = '\0';
		i++;
		s++;
	}
	map[i] = NULL;
	return (GOOD);
}

static void wallea(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->filemap.map[i])
	{
		j = 0;
		while (ft_isospace(game->filemap.map[i][j]))
			j++;
		while (game->filemap.map[i][j])
		{
			if (game->filemap.map[i][j] == ' ' 
				&& j != (int)ft_strlen(game->filemap.map[i]) - 1)
				game->filemap.map[i][j] = '1';
		}
		i++;
	}
}

int	add_map(t_game *game, int i, char **cfmap)
{
	game->filemap.height = count_map_height(cfmap, i, game);
	game->filemap.map = malloc(sizeof(char *) * (game->filemap.height + 1));
	if (!game->filemap.map)
		return (ERROH);
	if (copy_map(game->filemap, i, game->filemap.map) == 1)
		return (ERROH);
	wallea(game);
	return (GOOD);
}

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
		&& !ft_isdigit(map[i][j]))
		{
			if (add_texture(&game->texture, map[i], j) == 1)
				return (ft_printf_fd(1, "Error al añadir textura\n"), 1);
			return (-42);
		}
		else
		{
			if (add_color(&game->texture, map[i], j) == 1)
				return (ft_printf_fd(1, "Error al añadir color\n"), 1);
			return (-42);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (add_map(game, i, map) == 1)
			return (ft_printf_fd(1, "Error al añadir mapa\n"), -42);
		return (0);
	}
	return (99);
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
			else if (err == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}