/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ennemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:51:44 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/23 15:54:35 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_ennemy_id(t_all *all, int i, int j)
{
	int	index;

	index = 0;
	while (index < all->ennemies.nb_ennemies)
	{
		if (j == all->ennemies.x[index] && i == all->ennemies.y[index])
			return (index);
		index++;
	}
	return (-1);
}

void	display_ennemy(t_all *all, int i, int j)
{
	int		ennemy_id;
	// void	*image;
	t_win	w;
	int		ts;

	w = all->win;
	ts = all->win.tile_size;
	ennemy_id = get_ennemy_id(all, i, j);
	if (ennemy_id == -1)
	{
		write(2, "Error\n", 7);
		terminate(all);
	}
	if (all->ennemies.direction[ennemy_id] == 'u')
		color_tile(all, j, i, 0x00FF00);
	else if (all->ennemies.direction[ennemy_id] == 'd')
		color_tile(all, j, i, 0x0000FF);
	else if (all->ennemies.direction[ennemy_id] == 'l')
		color_tile(all, j, i, 0xFF00FF);
	else if (all->ennemies.direction[ennemy_id] == 'r')
		color_tile(all, j, i, 0xFF0000);
	// image = NULL;
	// if (all->ennemies.direction[ennemy_id] == 'u')
	// 	image = all->es.u;
	// if (all->ennemies.direction[ennemy_id] == 'd')
	// 	image = all->es.d;
	// if (all->ennemies.direction[ennemy_id] == 'l')
	// 	image = all->es.l;
	// if (all->ennemies.direction[ennemy_id] == 'r')
	// 	image = all->es.r;
	// if (image)
	// 	mlx_put_image_to_window(w.mlx, w.win, image, j * ts, i * ts);
}
