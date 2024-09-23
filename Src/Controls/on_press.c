/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:12:21 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/23 15:55:15 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_keypress(int keysym, t_all *all)
{
	if (keysym == 65307)
		terminate(all);
	moves(keysym, all);
	if (all->player.frame == 0)
		ennemies_turn(all);
	ft_printf("x:%d | y:%d\n", all->ennemies.x[0], all->ennemies.y[0]);
	ft_printf("os coin:%d\n", all->ennemies.is_on_coin[0]);
	display(all);
	// ft_printf("\e[1;1H\e[2Jmoves: %d\n", all->player.nb_move);
	return (0);
}
