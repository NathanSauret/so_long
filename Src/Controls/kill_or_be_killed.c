/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_or_be_killed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:35:36 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/26 11:31:34 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_ennemy_id(t_all *all, int go_x, int go_y)
{
	int	id;

	id = 0;
	while (id < all->ennemies.nb_ennemies)
	{
		if (all->ennemies.x[id] == go_x && all->ennemies.y[id] == go_y)
			return (id);
		id++;
	}
	exit_error(0, all);
	return (-1);
}

void	kill_or_be_killed(t_all *all, int go_x, int go_y)
{
	int		id;
	char	player_dir;
	char	ennemy_dir;

	id = get_ennemy_id(all, go_x, go_y);
	player_dir = all->player.direction;
	ennemy_dir = all->ennemies.direction[id];
	if (player_dir == ennemy_dir)
	{
		all->map.map[go_y][go_x] = '0';
		all->ennemies.x[id] = -1;
		all->ennemies.y[id] = -1;
		return ;
	}
	all->map.map[all->player.y][all->player.x] = '0';
	game_over(all);
}
