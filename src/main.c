/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:45:38 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 12:38:11 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf_fd(1, "La extension tiene que ser\n./cub3d <map_file.cub>\n"), 1);
	init_game(&game);
	(void)argv;
	return (0);
}
