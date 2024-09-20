/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:15:22 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 12:29:04 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (i == 0 || i == (all->map.height - 1))
			{
				if (all->map.map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == (all->map.width - 1))
			{
				if (all->map.map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
