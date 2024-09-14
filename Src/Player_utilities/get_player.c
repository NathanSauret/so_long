/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:36:36 by nathan            #+#    #+#             */
/*   Updated: 2024/09/15 01:49:53 by nathan           ###   ########.fr       */
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

void	get_player(t_player *player, t_map *map)
{
	int	*player_location;

	player_location = get_player_location(map);
	if (!player_location)
		exit_error(1, map);
	player->y = player_location[0];
	player->x = player_location[1];
	free(player_location);
	player->direction = 'r';
}
