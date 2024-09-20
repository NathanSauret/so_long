/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:40:00 by nathan            #+#    #+#             */
/*   Updated: 2024/09/20 15:46:02 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	tear_down_the_wall(t_all *all)
{
	if (all->tex.walls.ul)
		mlx_destroy_image(all->win.mlx, all->tex.walls.ul);
	if (all->tex.walls.u)
		mlx_destroy_image(all->win.mlx, all->tex.walls.u);
	if (all->tex.walls.ur)
		mlx_destroy_image(all->win.mlx, all->tex.walls.ur);
	if (all->tex.walls.l)
		mlx_destroy_image(all->win.mlx, all->tex.walls.l);
	if (all->tex.walls.r)
		mlx_destroy_image(all->win.mlx, all->tex.walls.r);
	if (all->tex.walls.dl)
		mlx_destroy_image(all->win.mlx, all->tex.walls.dl);
	if (all->tex.walls.d)
		mlx_destroy_image(all->win.mlx, all->tex.walls.d);
	if (all->tex.walls.dr)
		mlx_destroy_image(all->win.mlx, all->tex.walls.dr);
	if (all->tex.walls.square)
		mlx_destroy_image(all->win.mlx, all->tex.walls.square);
	if (all->tex.walls.round)
		mlx_destroy_image(all->win.mlx, all->tex.walls.round);
}

void	delete_textures(t_all *all)
{
	if (all->tex.bg)
		mlx_destroy_image(all->win.mlx, all->tex.bg);
	if (all->tex.coin)
		mlx_destroy_image(all->win.mlx, all->tex.coin);
	if (all->tex.eclose)
		mlx_destroy_image(all->win.mlx, all->tex.eclose);
	if (all->tex.eopen)
		mlx_destroy_image(all->win.mlx, all->tex.eopen);
	tear_down_the_wall(all);
}
