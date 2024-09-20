/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:57:24 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 16:52:54 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static void	color_tile(t_all *all, int tile_x, int tile_y, int color)
// {
// 	t_win	*win;
// 	int		i;
// 	int		j;

// 	win = all->win;
// 	if (tile_x < 0 || tile_x > win->width || tile_y < 0 || tile_y > win->height)
// 		return ;
// 	i = tile_y * win->tile_size;
// 	while (i < (tile_y * win->tile_size) + win->tile_size)
// 	{
// 		j = tile_x * win->tile_size;
// 		while (j < (tile_x * win->tile_size) + win->tile_size)
// 		{
// 			mlx_pixel_put(win->mlx, win->win, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

static void	choose_wall(t_all *all, int i, int j)
{
	t_win	w;
	t_map	m;
	int		ts;
	void	*image;

	w = all->win;
	m = all->map;
	ts = w.tile_size;
	if (i > 0 && i < m.height - 1 && j > 0 && j < m.width - 1)
		image = get_wall(all, i, j);
	else
		image = all->tex.walls.square;
	mlx_put_image_to_window(w.mlx, w.win, image, j * ts, i * ts);
}

static void	*get_frame(t_all *all)
{
	if (all->player.frame == 0)
	{
		all->player.frame = 1;
		if (all->player.direction == 'u')
			return (all->ps.u1);
		else if (all->player.direction == 'd')
			return (all->ps.d1);
		else if (all->player.direction == 'l')
			return (all->ps.l1);
		else if (all->player.direction == 'r')
			return (all->ps.r1);
	}
	else
	{
		all->player.frame = 0;
		if (all->player.direction == 'u')
			return (all->ps.u2);
		else if (all->player.direction == 'd')
			return (all->ps.d2);
		else if (all->player.direction == 'l')
			return (all->ps.l2);
		else if (all->player.direction == 'r')
			return (all->ps.r2);
	}
	return (NULL);
}

static void	choose_player_sprite(t_all *all, int i, int j)
{
	t_win		w;
	int			ts;
	void		*sprite;

	w = all->win;
	ts = w.tile_size;
	sprite = get_frame(all);
	mlx_put_image_to_window(w.mlx, w.win, sprite, j * ts, i * ts);
}

static void	choose_what_to_display(t_all *all, int i, int j)
{
	t_win		w;
	t_map		m;
	t_textures	t;
	int			ts;

	w = all->win;
	m = all->map;
	t = all->tex;
	ts = w.tile_size;
	if (m.map[i][j] == '1')
		choose_wall(all, i, j);
	else if (m.map[i][j] == '0')
		mlx_put_image_to_window(w.mlx, w.win, t.bg, j * ts, i * ts);
	else if (m.map[i][j] == 'C')
		mlx_put_image_to_window(w.mlx, w.win, t.coin, j * ts, i * ts);
	else if (m.map[i][j] == 'P')
		choose_player_sprite(all, i, j);
	else if (m.map[i][j] == 'E')
	{
		if (m.nb_coins == 0)
			mlx_put_image_to_window(w.mlx, w.win, t.eopen, j * ts, i * ts);
		else
			mlx_put_image_to_window(w.mlx, w.win, t.eclose, j * ts, i * ts);
	}
}

int	display(t_all *all)
{
	t_map		map;
	int			i;
	int			j;

	map = all->map;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			choose_what_to_display(all, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
