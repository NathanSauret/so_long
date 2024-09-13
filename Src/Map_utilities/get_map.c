/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:10:37 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/13 19:09:50 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static int	get_map_width(char *map_name)
// {
// 	int		fd;
// 	char	*line;
// 	int		len;

// 	fd = open(map_name, O_RDONLY);
// 	if (!fd)
// 		exit_error(0, NULL, NULL);
// 	line = get_next_line(fd);
// 	len = 0;
// 	while (line[len] && line[len] != '\n')
// 		len++;
// 	while (line)
// 		line = get_next_line(fd);
// 	close(fd);
// 	free(line);
// 	return (len);
// }

static int	get_map_height(char *map_name)
{
	int		fd;
	int		nb_lines;

	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_error(0, NULL, NULL);
	nb_lines = 0;
	while (get_next_line(fd))
		nb_lines++;
	close(fd);
	return (nb_lines);
}

static char	**get_the_map(char *map_name, int height)
{
	int		fd;
	char	**the_map;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_error(0, NULL, NULL);
	the_map = malloc(sizeof(char *) * height + 1);
	if (!the_map)
		exit_error(0, NULL, NULL);
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		the_map[i++] = line;
	}
	close(fd);
	return (the_map);
}

void	get_map(t_map *map, char *map_name)
{
	map->height = get_map_height(map_name);
	map->map = get_the_map(map_name, map->height);
	// map->width = get_map_width(map_name);
	parsing(map);
}
