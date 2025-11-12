/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:46:32 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/11/12 12:48:46 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ERROH 1
# define GOOD 2

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

typedef struct filemap
{
	char	**data; //malloc
	int		fd;
	int		width;
	int		height;
	char	*path; //malloc
	int		lines;
	int		end;
}			t_filemap;

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

typedef struct texture
{
	char	*no; //malloc
	char	*so; //malloc
	char	*we; //malloc
	char	*ea; //malloc
	int		*f;  //malloc
	int		*c;  //malloc
}			t_texture;

typedef struct game
{
	t_window	window;
	t_filemap	filemap;
	t_texture	texture;
	t_player	player;
}				t_game;

/////////////////////////////   INIT     ///////////////////////////////////////
void	init_game(t_game *game);

/////////////////////////////   PARSER     ///////////////////////////////////////
int		parser(t_game *game, char **argv);

//////////////////////////////   MAPA     ///////////////////////////////////////
int		open_map(t_filemap *map, char *file);
int		add_data(t_game *game, char **map);

/////////////////////////////   EXIT     ////////////////////////////////////////
void	bye_game(t_game *game, int code);
void 	free_array(void **ar);
void	free_filemap(t_game *game, t_filemap *map);

#endif