/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:57:24 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/24 16:37:01 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	choose_what_to_display(t_all *all, int i, int j)
{
	t_win		w;
	t_textures	t;
	int			ts;

	w = all->win;
	t = all->tex;
	ts = w.tile_size;
	if (all->map.map[i][j] == '1')
		display_wall(all, i, j);
	else if (all->map.map[i][j] == '0')
		mlx_put_image_to_window(w.mlx, w.win, t.bg, j * ts, i * ts);
	else if (all->map.map[i][j] == 'C')
		mlx_put_image_to_window(w.mlx, w.win, t.coin, j * ts, i * ts);
	else if (all->map.map[i][j] == 'P')
		display_player(all, i, j);
	else if (all->map.map[i][j] == 'E')
	{
		if (all->map.nb_coins == 0)
			mlx_put_image_to_window(w.mlx, w.win, t.eopen, j * ts, i * ts);
		else
			mlx_put_image_to_window(w.mlx, w.win, t.eclose, j * ts, i * ts);
	}
	else if (all->map.map[i][j] == 'X')
		display_ennemy(all, i, j);
}

int	display(t_all *all)
{
	t_map		map;
	int			i;
	int			j;
	char		*text;

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
	text = "moves:";
	mlx_string_put(all->win.mlx, all->win.win, 10, 10, 0xFFFFFF, text);
	text = ft_itoa(all->player.nb_move);
	mlx_string_put(all->win.mlx, all->win.win, 75, 10, 0xFFFFFF, text);

	return (1);
}
