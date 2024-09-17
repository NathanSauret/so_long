/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:45:35 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/17 14:35:22 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy_window(t_all *all)
{
	mlx_destroy_window(all->win->mlx, all->win->win);
	mlx_destroy_display(all->win->mlx);
	return (1);
}
