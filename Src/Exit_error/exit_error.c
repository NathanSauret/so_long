/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:35:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/15 01:49:30 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Reasons:
// -1. No message
// 0. Basic Error
// 1. Wrong number of arguments

static void	free_structs(t_map *map)
{
	if (map)
	{
		free_map(map);
	}
}

void	exit_error(int reason, t_map *map)
{
	if (reason == 0)
		write(2, "Error\n", 7);
	else if (reason == 1)
		write(2, "Error: The program needs one argument: map file\n", 49);
	free_structs(map);
	exit(1);
}
