/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:10:35 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/27 16:50:42 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_values(t_map map, t_map *map_copy, char **the_map)
{
	map_copy->map = the_map;
	map_copy->height = map.height;
	map_copy->width = map.width;
	map_copy->nb_coins = map.nb_coins;
}

void	dup_map(t_map map, t_map *map_copy)
{
	int		i;
	int		j;
	char	**the_map;
	char	*line;

	the_map = malloc(sizeof(char *) * map.height + 1);
	if (!the_map)
		return ;
	i = 0;
	while (i < map.height)
	{
		line = malloc(sizeof(char) * map.width + 1);
		j = 0;
		while (j < map.width)
		{
			line[j] = map.map[i][j];
			j++;
		}
		the_map[i] = line;
		i++;
	}
	set_values(map, map_copy, the_map);
}
