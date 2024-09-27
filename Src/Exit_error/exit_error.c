/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:35:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/27 16:42:02 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Reasons:
// -1. No message
//  0. Basic Error

void	free_structs(t_all *all)
{
	if (all->map.map)
		free_map(&all->map);
	delete_sprites(all);
	delete_textures(all);
	if (all->ennemies.direction)
	{
		free(all->ennemies.direction);
		free(all->ennemies.x);
		free(all->ennemies.y);
		free(all->ennemies.is_on_exit);
		free(all->ennemies.is_on_coin);
	}
}

void	exit_error(int reason, t_all *all)
{
	if (reason == 0)
		write(2, "Error\n", 7);
	free_structs(all);
	mlx_destroy_display(all->win.mlx);
	free(all->win.mlx);
	exit(1);
}
