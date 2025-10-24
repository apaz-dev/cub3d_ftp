/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:04:44 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/24 13:06:37 by apaz-pri         ###   ########.fr       */
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

static int parser_error(char *msg, int code, t_game *game)
{
	(void)code;
	ft_printf_fd(1, "Error en el parsing: %s\n", msg);
	free_filemap(game, &game->filemap);
	return (1);
}

int	parser(t_game *game, char **argv)
{
	if (check_extension(argv[1], ".cub"))	
		return (ft_printf_fd(1, \
			"La extension del archivo tiene que ser .cub\n"), 1);
	if (open_map(&game->filemap, argv[1]) != 0)
		return (parser_error("al abrir el mapa", 0, NULL));
	if (add_data(game, game->filemap.data) != 0)
		return (parser_error("al añadir datos", 45, game));
	return (0);
}