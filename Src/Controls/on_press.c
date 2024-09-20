/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:12:21 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 15:51:17 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_keypress(int keysym, t_all *all)
{
	if (keysym == 65307)
		terminate(all);
	moves(keysym, all);
	display(all);
	return (0);
}
