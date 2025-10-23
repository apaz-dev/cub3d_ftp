/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:04:44 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 18:53:10 by apaz-pri         ###   ########.fr       */
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

int	parser(t_game *game, char **argv)
{
	if (check_extension(argv[1], ".cub"))
		return (ft_printf_fd(1, \
			"La extension del archivo tiene que ser .cub\n"), 1);
	if (open_map(&game->map, argv[1]) != 0)
		return (1);
	if (add_data(game, &game->map) != 0)
		return (1);
	return (0);
}