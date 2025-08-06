/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:45:38 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/08/06 15:21:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extension(char *file, char *ext)
{
	int	from = ft_strlen(file) - 4;
	if (from < 0 || ft_strncmp(&file[from], ext, 4) != 0)
		return (true);
	return (false);
}

char	*read_map_file(char *filename)
{
	int		fd;
	char	*file;
	char	*tmp;
	char	*old;

	if (check_extension(filename, ".cub"))
	{
		printf("Error\nInvalid file extension\n");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	file = malloc(1);
	if (!file)
		exit(EXIT_FAILURE);
	file[0] = '\0';
	tmp = get_next_line(fd);
	while (tmp)
	{
		old = file;
		file = ft_strjoin(file, tmp);
		free(old);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (file);
}

void	load_map(char *filename)
{
	char	*file;
	char	**map;
	int		i;

	file = read_map_file(filename);
	map = ft_split(file, '\n');
	i = 0;
	while (map[i])
	{
		printf("Line %d: %s\n", i, map[i]);
		i++;
	}
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	free(file);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("la extension tiene que ser\n./cub3d <map_file.cub>\n");
		return (1);
	}
	load_map(argv[1]);
	return (0);
}