/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:12:21 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/24 15:24:24 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_turn(int keysym, t_all *all)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (keysym == 'w' || keysym == 0xff52)
		player_move(all, x, y - 1);
	else if (keysym == 's' || keysym == 0xff54)
		player_move(all, x, y + 1);
	else if (keysym == 'a' || keysym == 0xff51)
		player_move(all, x - 1, y);
	else if (keysym == 'd' || keysym == 0xff53)
		player_move(all, x + 1, y);
}

static void	ennemies_turn(t_all *all)
{
	int	id;
	int	direction;
	int	x;
	int	y;

	id = 0;
	while (id < all->ennemies.nb_ennemies)
	{
		x = all->ennemies.x[id];
		y = all->ennemies.y[id];
		if (x != -1 && y != -1)
		{
			direction = rand() % 4;
			if (direction == 0)
				ennemy_move(all, id, x, y - 1);
			else if (direction == 1)
				ennemy_move(all, id, x, y + 1);
			else if (direction == 2)
				ennemy_move(all, id, x - 1, y);
			else if (direction == 3)
				ennemy_move(all, id, x + 1, y);
		}
		id++;
	}
}

int	on_keypress(int keysym, t_all *all)
{
	if (keysym == 65307)
		terminate(all);
	player_turn(keysym, all);
	if (all->player.frame == 0)
		ennemies_turn(all);
	display(all);
	ft_printf("\e[1;1H\e[2Jmoves: %d\n", all->player.nb_move);
	return (0);
}
