/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:04:44 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 13:46:40 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_extension(char *file, char *ext)
{
	int	from = ft_strlen(file) - 4;
	if (from < 0 || ft_strncmp(&file[from], ext, 4) != 0)
		return (true);
	return (false);
}

int get_lines(char *file)
{
	int		fd;
	char	buf;
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

static int	open_map(t_game *game, char *file)
{
	size_t row;
	size_t col;
	size_t i;

	i = 0;
	row = 0;
	col = 0;
	game->map.lines = get_lines(file);
	game->map.path = file;
	game->map.data = malloc((game->map.lines + 1) * sizeof(char *));
	game->map.fd = open(file, O_RDONLY);
	if (game->map.fd < 0)
		return (ft_printf_fd(1, "Error\nNo se pudo abrir el archivo %s\n", file), 1);
	return (0);
}

int	parser(t_game *game, char **argv)
{
	if (check_extension(argv[1], ".cub"))
		return (ft_printf_fd(1, 
			"Error\nLa extension del archivo tiene que ser .cub\n"), 1);
	if (open_map(game, argv[1]) != 0)
		return (1);
	if (read_map(game) != 0)
		return (1);
	if (validate_map(game) != 0)
		return (1);
	return (0);
}