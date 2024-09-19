/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:59:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 17:10:16 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	terminate(t_all *all)
{
	free_structs(all);
	destroy_window(all);
	if (all->win)
		free(all->win->mlx);
	exit (0);
}

static int	loop(t_all *all)
{
	t_win		*win;

	win = all->win;
	if (all->player->is_on_exit && all->map.nb_coins == 0)
	{
		ft_printf("\e[1;1H\e[2JGreat Job!\n");
		terminate(all);
	}
	return (0);
}

static int	define_hooks(t_all *all)
{
	t_win	*win;

	win = all->win;
	mlx_hook(win->win, DestroyNotify, StructureNotifyMask, &terminate, all);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask, &on_keypress, all);
	mlx_loop_hook(win->mlx, &loop, all);
	display(all);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_all				all;
	t_player			player;
	t_win				win;
	t_textures			tex;

	if (argc != 2)
	{
		write(2, "Error: The program needs one argument: map file\n", 49);
		exit_error(-1, NULL);
	}
	get_map(&all, argv[1]);
	// display_in_terminal(all.map);
	return (0);
	win.mlx = mlx_init();
	win.tile_size = 64;
	get_player(&all, &player);
	get_textures(&all, &tex, &win);
	init_window(&all, &win);
	define_hooks(&all);
	mlx_loop(all.win->mlx);
	return (0);
}
