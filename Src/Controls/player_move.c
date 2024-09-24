/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:54:18 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/24 16:37:15 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_player_direction(t_all *all, int go_x, int go_y)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (go_y < y)
		all->player.direction = 'u';
	if (go_y > y)
		all->player.direction = 'd';
	if (go_x < x)
		all->player.direction = 'l';
	if (go_x > x)
		all->player.direction = 'r';
}

static void	replace_previous_tile(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (all->player.is_on_exit)
	{
		all->map.map[y][x] = 'E';
		all->player.is_on_exit = 0;
	}
	else
		all->map.map[y][x] = '0';
}

static void	update_new_tile(t_all *all, int go_x, int go_y)
{
	if (all->map.map[go_y][go_x] == 'E')
		all->player.is_on_exit = 1;
	else if (all->map.map[go_y][go_x] == 'C')
		all->map.nb_coins -= 1;
	all->map.map[go_y][go_x] = 'P';

}

static void	update_player_location(t_all *all, int go_x, int go_y)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (go_y < y)
		all->player.y -= 1;
	if (go_y > y)
		all->player.y += 1;
	if (go_x < x)
		all->player.x -= 1;
	if (go_x > x)
		all->player.x += 1;
}

void	player_move(t_all *all, int go_x, int go_y)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	update_player_direction(all, go_x, go_y);
	if (all->map.map[go_y][go_x] == 'X')
		kill_or_be_killed(all, go_x, go_y);
	else if (go_x > 0 && go_x < all->map.width
		&& go_y > 0 && go_y < all->map.height
		&& all->map.map[go_y][go_x] != '1'
		&& all->map.map[go_y][go_x] != 'X')
	{
		replace_previous_tile(all);
		update_new_tile(all, go_x, go_y);
		update_player_location(all, go_x, go_y);
		all->player.nb_move += 1;
	}
}
