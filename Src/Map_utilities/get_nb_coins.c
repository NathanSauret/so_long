/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_coins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:31:24 by nathan            #+#    #+#             */
/*   Updated: 2024/09/20 12:35:55 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_nb_coins(t_all *all)
{
	int	nb_coins;
	int	i;
	int	j;

	nb_coins = 0;
	i = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] == 'C')
				nb_coins++;
			j++;
		}
		i++;
	}
	return (nb_coins);
}
