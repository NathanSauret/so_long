/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:26:41 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 17:42:59 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parsing(t_map *map)
{
	if (!is_rectangular(map))
	{
		write(2, "Error: The map must be rectangular\n", 35);
		exit_error(-1, map, NULL);
	}
	if (!check_characters(map))
		exit_error(-1, map, NULL);
	if (!check_walls(map))
	{
		write(2, "Error: The map must be surrounded by walls\n", 44);
		exit_error(-1, map, NULL);
	}
	if (!is_exit_reachable(map))
	{
		write(2, "Error: The exit must be reachable\n", 35);
		exit_error(-1, map, NULL);
	}
	if (!are_coins_reachable(map))
	{
		write(2, "Error: All the collectibles must be reachable\n", 47);
		exit_error(-1, map, NULL);
	}
}
