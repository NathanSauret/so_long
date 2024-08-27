/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:10:37 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/27 14:25:03 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_map(int **map, int map_size)
{
	int	i;

	while (i < map_size)
	{
		if (!map[i])
			break ;
		free(map[i++]);
	}
	free(map);
}

int	**create_map(int map_size)
{
	int	**map;
	int	*line;
	int	i;

	map = malloc(sizeof(int *) * map_size + 1);
	if (!map)
		exit(1);
	i = 0;
	while (i < map_size)
	{
		line = malloc(sizeof(int) * map_size + 1);
		if (!line)
		{
			free_map(map, map_size);
			exit(1);
		}
	}
	return (map);
}
