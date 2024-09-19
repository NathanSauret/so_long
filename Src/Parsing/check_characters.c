/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:13:36 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 16:55:07 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_character_correct(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
	{
		write(2, "wrong character in map: ", 24);
		write(2, &c, 1);
		write(2, "\n", 1);
		return (0);
	}
	return (1);
}

static int	check_for_cep(int c_count, int e_count, int p_count)
{
	if (c_count == 0)
	{
		write(2, "Error: The map needs at least one coin\n", 40);
		return (0);
	}
	if (e_count == 0 || e_count > 1)
	{
		write(2, "Error: The map must contain one and only one exit\n", 51);
		return (0);
	}
	if (p_count == 0 || p_count > 1)
	{
		write(2, "Error: The map must contain one and only one player\n", 53);
		return (0);
	}
	return (1);
}

int	check_characters(t_map map)
{
	int	i;
	int	j;
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (!is_character_correct(map.map[i][j]))
				return (0);
			counts[0] += (map.map[i][j] == 'C');
			counts[1] += (map.map[i][j] == 'E');
			counts[2] += (map.map[i][j] == 'P');
			j++;
		}
		i++;
	}
	if (!check_for_cep(counts[0], counts[1], counts[2]))
		return (0);
	return (map.nb_coins = counts[0], 1);
}
