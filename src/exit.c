/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:56:39 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/24 11:46:15 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(void **ar)
{
	size_t	i;

	if (ar == NULL)
		return ;
	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	if (ar)
		free(ar);
}

void	free_filemap(t_game *game, t_filemap *map)
{
	if (!game || !map)
		return ;
	if (map->data)
		free_array((void **)map->data);
	if (map->fd > 0)
		close(map->fd);
	if (map->path)
		free(map->path);
}

void	bye_game(t_game *game, int code)
{
	if (!game)
		return ;
	free_array((void **)game->filemap.data);
	if (game->filemap.fd > 0)
		close(game->filemap.fd);
	exit(code);
}