/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:26:41 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/13 18:51:49 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parsing(t_map *map)
{
	if (!is_rectangular(map))
	{
		write(2, "Error: The map is not rectangular\n", 35);
		exit(1);
	}
	if (!check_characters(map))
		exit(1);
	if (!check_walls(map))
	{
		write(2, "Error: The map must be surrounded by walls\n", 44);
		exit(1);
	}
	if (!is_exit_reachable(map))
	{
		write(2, "Error: The exit must be reachable\n", 35);
		exit(1);
	}
	if (!are_coins_reachable(map))
	{
		write(2, "Error: All the collectibles must be reachable\n", 47);
		exit(1);
	}
}
