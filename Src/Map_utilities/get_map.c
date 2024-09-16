/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:10:37 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 17:43:28 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*get_file_extension(char *file_name)
{
	while (*file_name)
	{
		if (*file_name == '.')
			return (file_name);
		file_name++;
	}
	return (NULL);
}

static int	get_map_height(char *map_name)
{
	int		fd;
	int		nb_lines;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		perror(map_name);
		exit(1);
	}
	nb_lines = 0;
	line = get_next_line(fd, 1);
	if (ft_strlen(line) == 0)
	{
		write(2, "Error: The map is empty\n", 25);
		exit(1);
	}
	while (line)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd, 1);
	}
	close(fd);
	return (nb_lines);
}

static int	get_map_width(char *map_name)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_error(0, NULL, NULL);
	line = get_next_line(fd, 1);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	get_next_line(fd, 0);
	close(fd);
	free(line);
	return (len);
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
	the_map = malloc(sizeof(char *) * height);
	if (!the_map)
		exit_error(0, NULL, NULL);
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd, 1);
		the_map[i++] = line;
	}
	get_next_line(fd, 0);
	close(fd);
	return (the_map);
}

void	get_map(t_map *map, char *map_name)
{
	char	*extension;

	extension = get_file_extension(map_name);
	if (!extension
		|| !ft_strnstr(extension, ".ber", ft_strlen(map_name))
		|| ft_strlen(extension) != 4)
	{
		write(2, "Error: The map extension must be '.ber'\n", 41);
		exit(1);
	}
	map->height = get_map_height(map_name);
	map->map = get_the_map(map_name, map->height);
	map->width = get_map_width(map_name);
	parsing(map);
}
