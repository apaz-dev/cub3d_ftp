/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:06:34 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 18:04:11 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_lines(char *file)
{
	int		fd;
	char	*buf;
	int		lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(1, "No se pudo abrir el archivo\n");
		exit(1);
	}
	buf = get_next_line(fd);
	lines = 1;
	while (buf != NULL)
	{
		lines++;
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	close(fd);
	return (lines);
}

static int load_map(t_map *map)
{
	char	*line;
	size_t	i;
	
	i = 0;
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		map->data[i] = ft_strdup(line);
		if (map->data[i] == NULL)
		{
			free_array((void **)map->data);
			return (ft_printf_fd(1, "Error copiando la linea del mapa\n"), 1);
		}
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	map->data[i] = NULL;
	return (0);
}

int	open_map(t_map *map, char *file)
{
	map->lines = get_lines(file);
	map->path = file;
	map->data = malloc((map->lines + 1) * sizeof(char *));
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (ft_printf_fd(1, "Error\nNo se pudo abrir el archivo %s\n", file), 1);
	load_map(map);
	close(map->fd);
	return (0);
}