/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:54:18 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 17:05:12 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_all *all)
{
	t_map	*map;
	int		px;
	int		py;

	map = &all->map;
	px = all->player.x;
	py = all->player.y;
	all->player.direction = 'u';
	if (py - 1 < 0 || py - 1 >= map->width)
		return ;
	if (map->map[py - 1][px] == '1')
		return ;
	if (map->map[py - 1][px] == 'C')
		map->nb_coins -= 1;
	if (all->player.is_on_exit)
		map->map[py][px] = 'E';
	else
		map->map[py][px] = '0';
	if (map->map[py - 1][px] == 'E')
		all->player.is_on_exit = 1;
	else
		all->player.is_on_exit = 0;
	map->map[py - 1][px] = 'P';
	all->player.y -= 1;
	all->player.nb_move += 1;
}

static void	move_down(t_all *all)
{
	t_map	*map;
	int		px;
	int		py;

	map = &all->map;
	px = all->player.x;
	py = all->player.y;
	all->player.direction = 'd';
	if (py + 1 < 0 || py + 1 >= map->width)
		return ;
	if (map->map[py + 1][px] == '1')
		return ;
	if (map->map[py + 1][px] == 'C')
		map->nb_coins -= 1;
	if (all->player.is_on_exit)
		map->map[py][px] = 'E';
	else
		map->map[py][px] = '0';
	if (map->map[py + 1][px] == 'E')
		all->player.is_on_exit = 1;
	else
		all->player.is_on_exit = 0;
	map->map[py + 1][px] = 'P';
	all->player.y += 1;
	all->player.nb_move += 1;
}

static void	move_left(t_all *all)
{
	t_map	*map;
	int		px;
	int		py;

	map = &all->map;
	px = all->player.x;
	py = all->player.y;
	all->player.direction = 'l';
	if (px - 1 < 0 || px - 1 >= map->width)
		return ;
	if (map->map[py][px - 1] == '1')
		return ;
	if (map->map[py][px - 1] == 'C')
		map->nb_coins -= 1;
	if (all->player.is_on_exit)
		map->map[py][px] = 'E';
	else
		map->map[py][px] = '0';
	if (map->map[py][px - 1] == 'E')
		all->player.is_on_exit = 1;
	else
		all->player.is_on_exit = 0;
	map->map[py][px - 1] = 'P';
	all->player.x -= 1;
	all->player.nb_move += 1;
}

static void	move_right(t_all *all)
{
	t_map	*map;
	int		px;
	int		py;

	map = &all->map;
	px = all->player.x;
	py = all->player.y;
	all->player.direction = 'r';
	if (px + 1 < 0 || px + 1 >= map->width)
		return ;
	if (map->map[py][px + 1] == '1')
		return ;
	if (map->map[py][px + 1] == 'C')
		map->nb_coins -= 1;
	if (all->player.is_on_exit)
		map->map[py][px] = 'E';
	else
		map->map[py][px] = '0';
	if (map->map[py][px + 1] == 'E')
		all->player.is_on_exit = 1;
	else
		all->player.is_on_exit = 0;
	map->map[py][px + 1] = 'P';
	all->player.x += 1;
	all->player.nb_move += 1;
}

void	moves(int keysym, t_all *all)
{
	if (keysym == 'w' || keysym == 0xff52)
		move_up(all);
	else if (keysym == 's' || keysym == 0xff54)
		move_down(all);
	else if (keysym == 'a' || keysym == 0xff51)
		move_left(all);
	else if (keysym == 'd' || keysym == 0xff53)
		move_right(all);
	ft_printf("\e[1;1H\e[2Jmoves: %d\n", all->player.nb_move);
}
