/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:15:42 by nathan            #+#    #+#             */
/*   Updated: 2024/09/24 20:32:35 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	return_error(t_all *all, char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd, 1);
	}
	close(fd);
	write(2, "Error: The map is empty\n", 25);
	exit_error(-1, all);
}

int	get_map_height(char *map_name, t_all *all)
{
	int		fd;
	int		nb_lines;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		perror(map_name);
		close(fd);
		exit_error(-1, all);
	}
	nb_lines = 0;
	line = get_next_line(fd, 1);
	if (ft_strlen(line) == 0)
		return_error(all, line, fd);
	while (line)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd, 1);
	}
	close(fd);
	return (nb_lines);
}
