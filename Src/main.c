/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:59:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/15 01:54:07 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map		map;
	t_player	player;

	if (argc != 2)
		exit_error(1, NULL);
	get_map(&map, argv[1]);
	get_player(&player, &map);
	ft_printf("x: %d | y: %d\n", player.x, player.y);
	ft_printf("direction: %c\n", player.direction);
	free_map(&map);
	return (0);
}
