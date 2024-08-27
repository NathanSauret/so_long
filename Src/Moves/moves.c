/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:04 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/27 14:05:51 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Move the character up if he can, return 1 if can move, else 0
int	move_up(t_character character, int map_size)
{
	if (character.y + 1 > map_size)
		return (0);
	character.y += 1;
	return (1);
}

// Move the character down if he can, return 1 if can move, else 0
int	move_down(t_character character)
{
	if (character.y - 1 < 0)
		return (0);
	character.y -= 1;
	return (1);
}

// Move the character left if he can, return 1 if can move, else 0
int	move_left(t_character character)
{
	if (character.x - 1 < 0)
		return (0);
	character.x -= 1;
	return (1);
}

// Move the character right if he can, return 1 if can move, else 0
int	move_right(t_character character, int map_size)
{
	if (character.x + 1 > map_size)
		return (0);
	character.x += 1;
	return (1);
}
