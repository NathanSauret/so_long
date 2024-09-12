/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:35:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/12 18:23:12 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Reasons:
// 0. Basi Error
// 1. Wrong number of arguments

static void	free_structs(t_map *map, t_player *player)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < map->height)
			free(map->map[i++]);
		free(map);
	}
	if (player)
		free(player);
}

void	exit_error(int reason, t_map *map, t_player *player)
{
	if (reason == 0)
		write(2, "Error\n", 7);
	else if (reason == 1)
		write(2, "Error: The program needs one argument: map file\n", 49);
	free_structs(map, player);
	exit(1);
}
