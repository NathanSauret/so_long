/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:36:36 by nathan            #+#    #+#             */
/*   Updated: 2024/09/17 15:43:50 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_player_location(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				player->y = i;
				player->x = j;
			}
			j++;
		}
		i++;
	}
}

void	get_player(t_all *all, t_player *player)
{
	t_map		*map;

	all->player = player;
	map = all->map;
	get_player_location(map, player);
	player->direction = 'r';
	player->is_on_exit = 0;
	player->nb_move = 0;
}
