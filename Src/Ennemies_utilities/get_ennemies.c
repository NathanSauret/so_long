/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ennemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:15:43 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/23 15:42:40 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_number_ennemies(t_all *all)
{
	int			i;
	int			j;
	int			number_ennemies;

	number_ennemies = 0;
	i = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] == 'X')
				number_ennemies++;
			j++;
		}
		i++;
	}
	return (number_ennemies);
}

static void	get_ennemies_locations(t_all *all)
{
	t_ennemies	ennemies;
	int			i;
	int			j;
	int			index;

	ennemies = all->ennemies;
	index = 0;
	i = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] == 'X')
			{
				ennemies.x[index] = j;
				ennemies.y[index] = i;
				index++;
			}
			j++;
		}
		i++;
	}
}

static void	mallocs_ennemies(t_all *all)
{
	int	nb_ennemies;

	nb_ennemies = all->ennemies.nb_ennemies;
	all->ennemies.direction = malloc(sizeof(char) * nb_ennemies + 1);
	if (!all->ennemies.direction)
		exit_error(0, all);
	all->ennemies.x = malloc(sizeof(int) * nb_ennemies + 1);
	if (!all->ennemies.x)
		exit_error(0, all);
	all->ennemies.y = malloc(sizeof(int) * nb_ennemies + 1);
	if (!all->ennemies.y)
		exit_error(0, all);
	all->ennemies.is_on_exit = malloc(sizeof(int) * nb_ennemies + 1);
	if (!all->ennemies.is_on_exit)
		exit_error(0, all);
	all->ennemies.is_on_coin = malloc(sizeof(int) * nb_ennemies + 1);
	if (!all->ennemies.is_on_coin)
		exit_error(0, all);
}

void	get_ennemies(t_all *all)
{
	int	i;

	all->ennemies.nb_ennemies = get_number_ennemies(all);
	mallocs_ennemies(all);
	get_ennemies_locations(all);
	i = 0;
	while (i < all->ennemies.nb_ennemies)
	{
		all->ennemies.direction[i] = 'r';
		all->ennemies.is_on_exit[i] = 0;
		all->ennemies.is_on_coin[i] = 0;
		i++;
	}
}
