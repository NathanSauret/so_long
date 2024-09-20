/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:57:27 by nathan            #+#    #+#             */
/*   Updated: 2024/09/20 17:19:52 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// neighborhood is [up, down, left, right]
static int	*get_neighborhood(t_all *all, int nei[4], int i, int j)
{
	nei[0] = 0;
	nei[1] = 0;
	nei[2] = 0;
	nei[3] = 0;
	if (i - 1 > 0 && all->map.map[i - 1][j] == '1')
		nei[0] = 1;
	if (i + 1 < all->map.width -1 && all->map.map[i + 1][j] == '1')
		nei[1] = 1;
	if (j - 1 > 0 && all->map.map[i][j - 1] == '1')
		nei[2] = 1;
	if (j + 1 < all->map.height -1 && all->map.map[i][j + 1] == '1')
		nei[3] = 1;
	return (nei);
}

void	*get_wall(t_all *all, int i, int j)
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
