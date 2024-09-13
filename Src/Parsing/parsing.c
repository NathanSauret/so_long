/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:26:41 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/13 16:16:42 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parsing(t_map *map)
{
	if (!is_rectangular(map))
	{
		write(2, "Error: the map is not rectangular\n", 35);
		exit(1);
	}
	if (!check_characters(map))
		exit(1);
	if (!check_walls(map))
		exit(1);
	if (!is_exit_reachable(map))
		exit(1);
	if (!are_coins_reachable(map))
		exit(1);
}
