/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:12:45 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 12:26:57 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(t_all *all)
{
	int	i;
	int	len;

	i = 0;
	while (i < all->map.height)
	{
		len = 0;
		while (all->map.map[i][len])
			len++;
		if (i != (all->map.height - 1))
			len--;
		if (len != all->map.width)
			return (0);
		i++;
	}
	return (1);
}
