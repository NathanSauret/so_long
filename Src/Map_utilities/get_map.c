/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:10:37 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/27 16:09:44 by nsauret          ###   ########.fr       */
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

static char	**get_the_map(t_all *all, char *map_name, int height)
{
	int		fd;
	char	**the_map;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_error(0, NULL);
	the_map = malloc(sizeof(char *) * height);
	if (!the_map)
		exit_error(0, NULL);
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd, 1);
		if (!line)
		{
			close(fd);
			exit_error(1, all);
		}
		the_map[i++] = line;
	}
	get_next_line(fd, 0);
	close(fd);
	return (the_map);
}

static int	get_map_width(t_all *all, char *map_name)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_error(0, NULL);
	line = get_next_line(fd, 1);
	if (!line)
		exit_error(1, all);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	get_next_line(fd, 0);
	close(fd);
	free(line);
	return (len);
}

void	get_map(t_all *all, char *map_name)
{
	char	*extension;

	extension = get_file_extension(map_name);
	if (!extension
		|| !ft_strnstr(extension, ".ber", ft_strlen(map_name))
		|| ft_strlen(extension) != 4)
	{
		write(2, "Error:\nThe map extension must be '.ber'\n", 41);
		exit_error(-1, all);
	}
	all->map.height = get_map_height(map_name, all);
	all->map.map = get_the_map(all, map_name, all->map.height);
	all->map.width = get_map_width(all, map_name);
	all->map.nb_coins = get_nb_coins(all);
	parsing(all);
}
