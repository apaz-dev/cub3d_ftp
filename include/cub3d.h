/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:46:32 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/10/23 12:01:23 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}			t_window;

typedef struct map
{
	int		fd;
	int		width;
	int		height;
	char	**path;
	int		lines;
	int		end;
}			t_map;

typedef struct player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		rotated;
	int		move_x;
	int		move_y;

}			t_player;

typedef struct game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
}				t_game;

#endif