/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:26:41 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 12:34:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parsing(t_all *all)
{
	if (!is_rectangular(all))
	{
		write(2, "Error: The map must be rectangular\n", 35);
		exit_error(-1, all);
	}
	if (!check_characters(all))
		exit_error(-1, all);
	if (!check_walls(all))
	{
		write(2, "Error: The map must be surrounded by walls\n", 44);
		exit_error(-1, all);
	}
	if (!is_exit_reachable(all))
	{
		write(2, "Error: The exit must be reachable\n", 35);
		exit_error(-1, all);
	}
	if (!are_coins_reachable(all))
	{
		write(2, "Error: All the collectibles must be reachable\n", 47);
		exit_error(-1, all);
	}
}
