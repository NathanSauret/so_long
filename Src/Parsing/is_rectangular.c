/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:12:45 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/13 16:13:17 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->height)
	{
		len = 0;
		while (map->map[i][len])
			len++;
		if (i != (map->height - 1))
			len--;
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}
