/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exit_reachable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:16:26 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/23 13:10:19 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	*get_player_location(t_map map)
{
	int	i;
	int	j;
	int	*p_location;

	p_location = malloc(sizeof(int) * 2 + 1);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map[i][j] == 'P')
			{
				p_location[0] = i;
				p_location[1] = j;
				return (p_location);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

static int	search_for_exit(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'E')
		return (1);
	map->map[i][j] = '1';
	if ((i - 1) >= 0 && map->map[i - 1][j] != '1' && map->map[i - 1][j] != 'X')
	{
		if (search_for_exit(map, i - 1, j) == 1)
			return (1);
	}
	if ((i + 1) >= 0 && map->map[i + 1][j] != '1' && map->map[i + 1][j] != 'X')
	{
		if (search_for_exit(map, i + 1, j) == 1)
			return (1);
	}
	if ((j - 1) >= 0 && map->map[i][j - 1] != '1' && map->map[i][j - 1] != 'X')
	{
		if (search_for_exit(map, i, j - 1) == 1)
			return (1);
	}
	if ((j + 1) >= 0 && map->map[i][j + 1] != '1' && map->map[i][j + 1] != 'X')
	{
		if (search_for_exit(map, i, j + 1) == 1)
			return (1);
	}
	return (0);
}

int	is_exit_reachable(t_all *all)
{
	int		*p_location;
	t_map	map_copy;
	int		res;

	dup_map(all->map, &map_copy);
	p_location = get_player_location(map_copy);
	if (search_for_exit(&map_copy, p_location[0], p_location[1]))
		res = 1;
	else
		res = 0;
	free(p_location);
	free_map(&map_copy);
	return (res);
}
