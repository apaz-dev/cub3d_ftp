/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:05:54 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 12:37:14 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_player(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->moved = 0;
	player->rotated = 0;
	player->move_x = 0;
	player->move_y = 0;
}

static void init_map(t_map *map)
{
	map->fd = 0;
	map->width = 0;
	map->height = 0;
	map->path = NULL;
	map->lines = 0;
	map->end = 0;
}

void init_game(t_game *game)
{
	game->window.mlx = NULL;
	game->window.win = NULL;
	game->window.width = WIN_WIDTH;
	game->window.height = WIN_HEIGHT;
	init_player(&game->player);
	init_map(&game->map);
}
