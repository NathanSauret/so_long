/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:15:22 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 16:54:22 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (i == 0 || i == (map.height - 1))
			{
				if (map.map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == (map.width - 1))
			{
				if (map.map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
