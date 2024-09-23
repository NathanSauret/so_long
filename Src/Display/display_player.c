/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:47:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/23 12:50:33 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	display_player(t_all *all, int i, int j)
{
	t_win		w;
	int			ts;
	void		*sprite;

	w = all->win;
	ts = w.tile_size;
	sprite = get_frame(all);
	mlx_put_image_to_window(w.mlx, w.win, sprite, j * ts, i * ts);
}
