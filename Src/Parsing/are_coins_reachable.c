/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_coins_reachable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:16:57 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 17:20:43 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	*get_player_location(t_map *map)
{
	int	i;
	int	j;
	int	*p_location;

	p_location = malloc(sizeof(int) * 2 + 1);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
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

static int	search_for_coins(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'C')
		map->nb_coins -= 1;
	map->map[i][j] = '1';
	if ((i - 1) >= 0 && map->map[i - 1][j] != '1')
	{
		if (search_for_coins(map, i - 1, j) == 1)
			return (1);
	}
	if ((i + 1) >= 0 && map->map[i + 1][j] != '1')
	{
		if (search_for_coins(map, i + 1, j) == 1)
			return (1);
	}
	if ((j - 1) >= 0 && map->map[i][j - 1] != '1')
	{
		if (search_for_coins(map, i, j - 1) == 1)
			return (1);
	}
	if ((j + 1) >= 0 && map->map[i][j + 1] != '1')
	{
		if (search_for_coins(map, i, j + 1) == 1)
			return (1);
	}
	return (0);
}

int	are_coins_reachable(t_map map)
{
	int		*p_location;
	t_map	map_copy;
	int		res;

	dup_map(map, &map_copy);
	ft_printf("%d\n", map.nb_coins);
	p_location = get_player_location(&map_copy);
	search_for_coins(&map_copy, p_location[0], p_location[1]);
	if (map_copy.nb_coins == 0)
		res = 1;
	else
		res = 0;
	free(p_location);
	free_map(&map_copy);
	return (res);
}
