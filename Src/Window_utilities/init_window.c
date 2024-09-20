/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:27:01 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 12:16:24 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_all *all)
{
	t_map	map;
	t_win	*win;

	win = &all->win;
	map = all->map;
	win->width = win->tile_size * map.width;
	win->height = win->tile_size * map.height;
	if (!win->mlx)
		exit_error(0, all);
	win->win = mlx_new_window(win->mlx, win->width, win->height, "so_long");
	if (!win->win)
		exit_error(0, all);
}
