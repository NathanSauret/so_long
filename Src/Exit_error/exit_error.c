/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:35:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 15:46:30 by nathan           ###   ########.fr       */
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
	if (all->ps.u1)
		delete_sprites(all);
	if (all->tex.bg)
		delete_textures(all);
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
