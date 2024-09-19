/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:35:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 11:27:06 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Reasons:
// -1. No message
//  0. Basic Error

void	free_structs(t_all *all)
{
	int	i;

	if (all->map)
		free_map(all->map);
	if (all->tex)
	{
		i = 0;
		while (i < all->tex->nb_textures)
			free(all->tex->textures[i++]);
		free(all->tex->textures);
		free(all->tex->paths);
	}
}

void	exit_error(int reason, t_all *all)
{
	if (reason == 0)
		write(2, "Error\n", 7);
	free_structs(all);
	exit(1);
}
