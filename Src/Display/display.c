/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:57:24 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 12:23:07 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	color_tile(t_all *all, int tile_x, int tile_y, int color)
{
	t_win	*win;
	int		i;
	int		j;

	win = all->win;
	if (tile_x < 0 || tile_x > win->width || tile_y < 0 || tile_y > win->height)
		return ;
	i = tile_y * win->tile_size;
	while (i < (tile_y * win->tile_size) + win->tile_size)
	{
		j = tile_x * win->tile_size;
		while (j < (tile_x * win->tile_size) + win->tile_size)
		{
			mlx_pixel_put(win->mlx, win->win, j, i, color);
			j++;
		}
		i++;
	}
}

int	display_using_pixels(t_all *all)
{
	t_map	*map;
	int		i;
	int		j;

	map = all->map;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				color_tile(all, j, i, 0xFFFFFF);
			else if (map->map[i][j] == '0')
				color_tile(all, j, i, 0x000000);
			else if (map->map[i][j] == 'P')
				color_tile(all, j, i, 0x0000FF);
			else if (map->map[i][j] == 'E')
			{
				if (all->map->nb_coins == 0)
					color_tile(all, j, i, 0x00FF00);
				else
					color_tile(all, j, i, 0xFF0000);
			}
			else if (map->map[i][j] == 'C')
				color_tile(all, j, i, 0xFFFF00);
			j++;
		}
		i++;
	}
	return (1);
}

int	display(t_all *all)
{
	t_map	*map;
	t_win	*win;
	void	**textures;
	// int		i;

	map = all->map;
	win = all->win;
	textures = all->tex->textures;
	mlx_put_image_to_window(win->mlx, win->win, &textures[0], 0, 0);
	return (1);
}
