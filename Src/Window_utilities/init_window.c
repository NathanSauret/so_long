/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:27:01 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 15:27:33 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_win *win, t_map *map)
{
	win->tile_size = 40;
	win->width = win->tile_size * map->width;
	win->height = win->tile_size * map->height;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, "so_long");
}
