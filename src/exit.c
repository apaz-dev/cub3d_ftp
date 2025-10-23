/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:56:39 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 18:02:43 by apaz-pri         ###   ########.fr       */
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

void	bye_game(t_game *game, int code)
{
	if (!game)
		return ;
	free_array((void **)game->map.data);
	if (game->map.fd > 0)
		close(game->map.fd);
	exit(code);
}