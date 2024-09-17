/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:27:01 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/17 14:39:12 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_all *all, t_win *win)
{
	t_map	*map;

	all->win = win;
	map = all->map;
	win->tile_size = 64;
	win->width = win->tile_size * map->width;
	win->height = win->tile_size * map->height;
	win->mlx = mlx_init();
	if (!win->mlx)
		exit_error(0, all);
	win->win = mlx_new_window(win->mlx, win->width, win->height, "so_long");
	if (!win->win)
		exit_error(0, all);
}
