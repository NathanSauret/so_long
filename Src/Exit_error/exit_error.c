/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:35:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 17:42:17 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Reasons:
// -1. No message
// 0. Basic Error
// 1. Wrong number of arguments

void	free_structs(t_map *map, t_all *all)
{
	int	i;

	if (map)
		free_map(map);
	if (all && all->textures)
	{
		i = 0;
		while (all->textures[i])
			free(all->textures[i++]);
	}
}

void	exit_error(int reason, t_map *map, t_all *all)
{
	if (reason == 0)
		write(2, "Error\n", 7);
	else if (reason == 1)
		write(2, "Error: The program needs one argument: map file\n", 49);
	free_structs(map, all);
	exit(1);
}
