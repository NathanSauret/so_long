/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:36:36 by nathan            #+#    #+#             */
/*   Updated: 2024/09/23 15:40:14 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_player_location(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] == 'P')
			{
				all->player.y = i;
				all->player.x = j;
			}
			j++;
		}
		i++;
	}
}

void	get_player(t_all *all)
{
	get_player_location(all);
	all->player.direction = 'r';
	all->player.is_on_exit = 0;
	all->player.nb_move = 0;
	all->player.frame = 0;
}
