/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:50:52 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/11/12 12:57:22 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_mlx(t_game *game)
{
	game->window.mlx = mlx_init();
	if (game->window.mlx == NULL)
	{
		ft_printf("Error initializing MLX\n");
		bye_game(game, EXIT_FAILURE);
	}
	game->window.win = mlx_new_window(game->window.mlx,
			WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (game->window.win == NULL)
	{
		ft_printf("Error creating window\n");
		bye_game(game, EXIT_FAILURE);
	}
}