/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:41:03 by nathan            #+#    #+#             */
/*   Updated: 2024/09/24 15:21:54 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_sprites(t_all *all)
{
	if (all->ps.u1)
		mlx_destroy_image(all->win.mlx, all->ps.u1);
	if (all->ps.u2)
		mlx_destroy_image(all->win.mlx, all->ps.u2);
	if (all->ps.d1)
		mlx_destroy_image(all->win.mlx, all->ps.d1);
	if (all->ps.d2)
		mlx_destroy_image(all->win.mlx, all->ps.d2);
	if (all->ps.l1)
		mlx_destroy_image(all->win.mlx, all->ps.l1);
	if (all->ps.l2)
		mlx_destroy_image(all->win.mlx, all->ps.l2);
	if (all->ps.r1)
		mlx_destroy_image(all->win.mlx, all->ps.r1);
	if (all->ps.r2)
		mlx_destroy_image(all->win.mlx, all->ps.r2);
	if (all->es.u)
		mlx_destroy_image(all->win.mlx, all->es.u);
	if (all->es.d)
		mlx_destroy_image(all->win.mlx, all->es.d);
	if (all->es.l)
		mlx_destroy_image(all->win.mlx, all->es.l);
	if (all->es.r)
		mlx_destroy_image(all->win.mlx, all->es.r);
}
