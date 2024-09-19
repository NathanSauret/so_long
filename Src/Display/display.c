/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:57:24 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 17:07:55 by nsauret          ###   ########.fr       */
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

// static void	*get_frame(t_all *all)
// {
// 	if (all->player->frame == 0)
// 	{
// 		if (all->player->direction == 'u')
// 			return (all->tex->player->u1);
// 		else if (all->player->direction == 'd')
// 			return (all->tex->player->d1);
// 		else if (all->player->direction == 'l')
// 			return (all->tex->player->l1);
// 		else if (all->player->direction == 'r')
// 			return (all->tex->player->r1);
// 		all->player->frame = 1;
// 	}
// 	else
// 	{
// 		if (all->player->direction == 'u')
// 			return (all->tex->player->u2);
// 		else if (all->player->direction == 'd')
// 			return (all->tex->player->d2);
// 		else if (all->player->direction == 'l')
// 			return (all->tex->player->l2);
// 		else if (all->player->direction == 'r')
// 			return (all->tex->player->r2);
// 		all->player->frame = 0;
// 	}
// 	return (NULL);
// }

static void	choose_player_sprite(t_all *all, int i, int j)
{
	t_win		*w;
	int			ts;
	void		*sprite;

	w = all->win;
	ts = w->tile_size;
	// sprite = get_frame(all);
	sprite = all->ps->u1;
	mlx_put_image_to_window(w->mlx, w->win, sprite, j * ts, i * ts);
}

static void	choose_what_to_display(t_all *all, int i, int j)
{
	t_win		*w;
	t_map		m;
	t_textures	*t;
	int			ts;

	w = all->win;
	m = all->map;
	t = all->tex;
	ts = w->tile_size;
	if (m.map[i][j] == '1')
		mlx_put_image_to_window(w->mlx, w->win, t->wall, j * ts, i * ts);
	else if (m.map[i][j] == '0')
		mlx_put_image_to_window(w->mlx, w->win, t->bg, j * ts, i * ts);
	else if (m.map[i][j] == 'C')
		mlx_put_image_to_window(w->mlx, w->win, t->coin, j * ts, i * ts);
	else if (m.map[i][j] == 'P')
		choose_player_sprite(all, i, j);
	else if (m.map[i][j] == 'E')
	{
		if (m.nb_coins == 0)
			mlx_put_image_to_window(w->mlx, w->win, t->eopen, j * ts, i * ts);
		else
			mlx_put_image_to_window(w->mlx, w->win, t->eclose, j * ts, i * ts);
	}
}

int	display(t_all *all)
{
	t_win		*win;
	t_map		map;
	t_textures	*tex;
	int			i;
	int			j;

	win = all->win;
	map = all->map;
	tex = all->tex;
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
