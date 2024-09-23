/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:27:04 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/23 15:55:19 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_all *all, int id)
{
	int	i;
	int	j;

	i = all->ennemies.y[id];
	j = all->ennemies.x[id];
	if (i - 1 > 0
		&& all->map.map[i - 1][j] != '1'
		&& all->map.map[i - 1][j] != 'X')
	{
		if (all->ennemies.is_on_exit[id])
			all->map.map[i][j] = 'E';
		else if (all->ennemies.is_on_coin[id])
		{
			all->map.map[i][j] = 'C';
			all->ennemies.is_on_coin[id] = 0;
		}
		else
			all->map.map[i][j] = '0';
		all->ennemies.y[id] -= 1;
		all->map.map[i - 1][j] = 'X';
		if (all->map.map[i - 1][j] == 'E')
			all->ennemies.is_on_exit[id] = 1;
		else if (all->map.map[i - 1][j] == 'C')
			all->ennemies.is_on_coin[id] = 1;
	}
	all->ennemies.direction[id] = 'u';
}

static void	move_down(t_all *all, int id)
{
	int	i;
	int	j;

	i = all->ennemies.y[id];
	j = all->ennemies.x[id];
	if (i + 1 < all->map.height
		&& all->map.map[i + 1][j] != '1'
		&& all->map.map[i + 1][j] != 'X')
	{
		if (all->ennemies.is_on_exit[id])
			all->map.map[i][j] = 'E';
		else if (all->ennemies.is_on_coin[id])
		{
			all->map.map[i][j] = 'C';
			all->ennemies.is_on_coin[id] = 0;
		}
		else
			all->map.map[i][j] = '0';
		all->ennemies.y[id] += 1;
		all->map.map[i + 1][j] = 'X';
		if (all->map.map[i + 1][j] == 'E')
			all->ennemies.is_on_exit[id] = 1;
		else if (all->map.map[i + 1][j] == 'C')
			all->ennemies.is_on_coin[id] = 1;
	}
	all->ennemies.direction[id] = 'd';
}

static void	move_left(t_all *all, int id)
{
	int	i;
	int	j;

	i = all->ennemies.y[id];
	j = all->ennemies.x[id];
	if (j - 1 > 0
		&& all->map.map[i][j - 1] != '1'
		&& all->map.map[i][j - 1] != 'X')
	{
		if (all->ennemies.is_on_exit[id])
			all->map.map[i][j] = 'E';
		else if (all->ennemies.is_on_coin[id])
		{
			all->map.map[i][j] = 'C';
			all->ennemies.is_on_coin[id] = 0;
		}
		else
			all->map.map[i][j] = '0';
		all->ennemies.x[id] -= 1;
		all->map.map[i][j - 1] = 'X';
		if (all->map.map[i][j - 1] == 'E')
			all->ennemies.is_on_exit[id] = 1;
		else if (all->map.map[i][j - 1] == 'C')
			all->ennemies.is_on_coin[id] = 1;
	}
	all->ennemies.direction[id] = 'l';
}

static void	move_right(t_all *all, int id)
{
	int	i;
	int	j;

	i = all->ennemies.y[id];
	j = all->ennemies.x[id];
	if (j + 1 < all->map.width
		&& all->map.map[i][j + 1] != '1'
		&& all->map.map[i][j + 1] != 'X')
	{
		if (all->ennemies.is_on_exit[id])
			all->map.map[i][j] = 'E';
		else if (all->ennemies.is_on_coin[id])
		{
			all->map.map[i][j] = 'C';
			all->ennemies.is_on_coin[id] = 0;
		}
		else
			all->map.map[i][j] = '0';
		all->ennemies.x[id] += 1;
		all->map.map[i][j + 1] = 'X';
		if (all->map.map[i][j + 1] == 'E')
			all->ennemies.is_on_exit[id] = 1;
		else if (all->map.map[i][j + 1] == 'C')
			all->ennemies.is_on_coin[id] = 1;
	}
	all->ennemies.direction[id] = 'r';
}

void	ennemies_turn(t_all *all)
{
	int	id;
	int	direction;

	id = 0;
	while (id < all->ennemies.nb_ennemies)
	{

		direction = rand() % 4;
		if (direction == 0)
			move_up(all, id);
		else if (direction == 1)
			move_down(all, id);
		else if (direction == 2)
			move_left(all, id);
		else if (direction == 3)
			move_right(all, id);
		id++;
	}
}
