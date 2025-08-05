/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-pri <apaz-pri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:45:38 by apaz-pri          #+#    #+#             */
/*   Updated: 2025/08/05 13:04:26 by apaz-pri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	true = No tiene la extension correcta
	false = L extension es igual q la de `ext`
*/
bool	check_extension(char *file, char *ext)
{
	int	from;

	from = ft_strlen(file) - 4; // 17
	if (ft_strncmp(&file[from], ext, -1) != 0)
		return (true);
	return (false);
}

/*

	ejemplo.cub = `
	hola
	final
	`

	*file = "hola\nfinal"

	Hay que convertir file[] en file[][] separando por los '\n' para que quede algo asi

	file[0][] = "hola"
	file[1][] = "Final"

	Usar ft_split(file, '\n');
*/
void	load_map(char *argv)
{
	int		fd;
	char	*tmp;
	char	*file;

	file = malloc(1);
	if (!file)
		exit(EXIT_FAILURE);
	file[0] = '\0';
	if (check_extension(argv, ".cub"))
	{
		printf("Error\n");
		return ;
	}
	fd = open(argv, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp != 0)
	{
		file = ft_strjoin(file, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	load_map(argv[1]);
	(void)argc;
	return (0);
}