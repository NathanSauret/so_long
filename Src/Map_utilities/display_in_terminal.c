/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_in_terminal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:37:53 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/15 00:19:20 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_in_terminal(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%c ", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
