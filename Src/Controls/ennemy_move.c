/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:13:30 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/26 11:37:27 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_ennemy_direction(t_all *all, int id, int go_x, int go_y)
{
	int	x;
	int	y;

	x = all->ennemies.x[id];
	y = all->ennemies.y[id];
	if (go_y < y)
		all->ennemies.direction[id] = 'u';
	if (go_y > y)
		all->ennemies.direction[id] = 'd';
	if (go_x < x)
		all->ennemies.direction[id] = 'l';
	if (go_x > x)
		all->ennemies.direction[id] = 'r';
}

static void	replace_previous_tile(t_all *all, int id)
{
	int	x;
	int	y;

	x = all->ennemies.x[id];
	y = all->ennemies.y[id];
	if (all->ennemies.is_on_exit[id])
	{
		all->map.map[y][x] = 'E';
		all->ennemies.is_on_exit[id] = 0;
	}
	else if (all->ennemies.is_on_coin[id])
	{
		all->map.map[y][x] = 'C';
		all->ennemies.is_on_coin[id] = 0;
	}
	else
		all->map.map[y][x] = '0';
}

static void	update_new_tile(t_all *all, int id, int go_x, int go_y)
{
	if (all->map.map[go_y][go_x] == 'E')
		all->ennemies.is_on_exit[id] = 1;
	else if (all->map.map[go_y][go_x] == 'C')
		all->ennemies.is_on_coin[id] = 1;
	all->map.map[go_y][go_x] = 'X';
}

static void	update_ennemy_location(t_all *all, int id, int go_x, int go_y)
{
	int	x;
	int	y;

	x = all->ennemies.x[id];
	y = all->ennemies.y[id];
	if (go_y < y)
		all->ennemies.y[id] -= 1;
	if (go_y > y)
		all->ennemies.y[id] += 1;
	if (go_x < x)
		all->ennemies.x[id] -= 1;
	if (go_x > x)
		all->ennemies.x[id] += 1;
}

void	ennemy_move(t_all *all, int id, int go_x, int go_y)
{
	update_ennemy_direction(all, id, go_x, go_y);
	if (all->map.map[go_y][go_x] == 'P')
	{
		replace_previous_tile(all, id);
		update_new_tile(all, id, go_x, go_y);
		update_ennemy_location(all, id, go_x, go_y);
		game_over(all);
	}
	else if (go_x > 0 && go_x < all->map.width
		&& go_y > 0 && go_y < all->map.height
		&& all->map.map[go_y][go_x] != '1'
		&& all->map.map[go_y][go_x] != 'X')
	{
		replace_previous_tile(all, id);
		update_new_tile(all, id, go_x, go_y);
		update_ennemy_location(all, id, go_x, go_y);
	}
}
