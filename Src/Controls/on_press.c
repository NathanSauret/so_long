/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:12:21 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 12:49:39 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_keypress(int keysym, t_all *all)
{
	if (keysym == 65307)
		terminate(all);
	moves(keysym, all);
	// display_using_pixels(all);
	display(all);
	return (0);
}
