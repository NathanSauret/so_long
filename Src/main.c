/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:59:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 17:42:28 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	color_tile(t_win *win, int tile_x, int tile_y, int color)
{
	int		i;
	int		j;

	if (tile_x < 0 || tile_x > win->width || tile_y < 0 || tile_y > win->height)
		return (0);
	i = tile_y * win->tile_size;
	while(i < (tile_y * win->tile_size) + win->tile_size)
	{
		j = tile_x * win->tile_size;
		while(j < (tile_x * win->tile_size) + win->tile_size)
		{
			mlx_pixel_put(win->mlx, win->mlx_win, j, i, color);
			j++;
		}
		i++;
	}
	return (1);
}

// static int	display_image(t_all *all)
// {
// 	path = "../Textures/exit_green.xpm";
// 	datas->img = mlx_xpm_file_to_image(datas->win->mlx, path, &datas->win->tile_size, &datas->win->tile_size);
// 	ft_printf("%s\n", datas->img);
// 	mlx_put_image_to_window(datas->win->mlx, datas->win->mlx_win, &datas->img, 0, 0);
// 	return (1);
// }

static int	display(t_all *all)
{
	t_map	*map;
	t_win	*win;
	int		i;
	int		j;

	map = all->map;
	win = all->win;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			color_tile(win, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_player	player;
	t_win		win;
	t_all		all;

	if (argc != 2)
		exit_error(1, NULL, NULL);
	get_map(&map, argv[1]);
	get_player(&player, &map);
	init_window(&win, &map);
	set_all(&all, &win, &map, &player);
	mlx_loop_hook(win.mlx, &display, &all);

	mlx_loop(win.mlx);
	free_structs(&map, &all);
	return (0);
}
