/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:59:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/27 14:12:12 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Src/so_long.h"

int	main(int argc, char *argv[])
{
	int			map_size;
	int			**map;
	t_character	character;

	map_size = 10;
	map = create_map(map_size);
	character.x = 0;
	character.y = 0;


	return (0);
}
