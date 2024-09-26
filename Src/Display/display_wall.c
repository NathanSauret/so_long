/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:57:27 by nathan            #+#    #+#             */
/*   Updated: 2024/09/26 12:25:26 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	*get_neighborhood(t_all *all, int nei[4], int i, int j)
{
	nei[0] = 0;
	nei[1] = 0;
	nei[2] = 0;
	nei[3] = 0;
	if (i - 1 >= 0 && all->map.map[i - 1][j] == '1')
		nei[0] = 1;
	if (i + 1 < all->map.height && all->map.map[i + 1][j] == '1')
		nei[1] = 1;
	if (j - 1 >= 0 && all->map.map[i][j - 1] == '1')
		nei[2] = 1;
	if (j + 1 < all->map.width && all->map.map[i][j + 1] == '1')
		nei[3] = 1;
	return (nei);
}

static void	*get_wall(t_all *all, int i, int j)
{
	int	nei[4];

	get_neighborhood(all, nei, i, j);
	if (!nei[0] && nei[1] && !nei[2] && nei[3])
		return (all->tex.walls.ul);
	if (!nei[0] && nei[1] && !nei[2] && !nei[3])
		return (all->tex.walls.u);
	if (!nei[0] && nei[1] && nei[2] && !nei[3])
		return (all->tex.walls.ur);
	if (!nei[0] && !nei[1] && !nei[2] && nei[3])
		return (all->tex.walls.l);
	if (!nei[0] && !nei[1] && nei[2] && !nei[3])
		return (all->tex.walls.r);
	if (nei[0] && !nei[1] && !nei[2] && nei[3])
		return (all->tex.walls.dl);
	if (nei[0] && !nei[1] && !nei[2] && !nei[3])
		return (all->tex.walls.d);
	if (nei[0] && !nei[1] && nei[2] && !nei[3])
		return (all->tex.walls.dr);
	if (!nei[0] && !nei[1] && !nei[2] && !nei[3])
		return (all->tex.walls.round);
	return (all->tex.walls.square);
}

void	display_wall(t_all *all, int i, int j)
{
	t_win	w;
	t_map	m;
	int		ts;
	void	*image;

	w = all->win;
	m = all->map;
	ts = w.tile_size;
	image = NULL;
	if (i > 0 && i < m.height - 1 && j > 0 && j < m.width - 1)
		image = get_wall(all, i, j);
	else
		image = all->tex.walls.square;
	if (image != NULL)
		mlx_put_image_to_window(w.mlx, w.win, image, j * ts, i * ts);
}
