/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:04 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/12 18:31:29 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Move the player up if he can, return 1 if can move, else 0
int	move_up(t_player player, int map_size)
{
	if (player.y + 1 > map_size)
		return (0);
	player.y += 1;
	return (1);
}

// Move the player down if he can, return 1 if can move, else 0
int	move_down(t_player player)
{
	if (player.y - 1 < 0)
		return (0);
	player.y -= 1;
	return (1);
}

// Move the player left if he can, return 1 if can move, else 0
int	move_left(t_player player)
{
	if (player.x - 1 < 0)
		return (0);
	player.x -= 1;
	return (1);
}

// Move the player right if he can, return 1 if can move, else 0
int	move_right(t_player player, int map_size)
{
	if (player.x + 1 > map_size)
		return (0);
	player.x += 1;
	return (1);
}
