/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:59:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/17 15:47:40 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	terminate(t_all *all)
{
	destroy_window(all);
	free_structs(all);
	return (0);
}

static int	loop(t_all *all)
{
	t_win		*win;

	win = all->win;
	display_using_pixels(all);
	// mlx_loop_hook(all->win->mlx, &display, all);
	if (all->player->is_on_exit && all->map->nb_coins == 0)
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
	mlx_hook(win->win, DestroyNotify, StructureNotifyMask, &terminate, &all);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask, &on_keypress, all);
	mlx_loop_hook(win->mlx, &loop, all);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_all		all;
	t_map		map;
	t_player	player;
	t_win		win;
	t_textures	tex;

	if (argc != 2)
	{
		write(2, "Error: The program needs one argument: map file\n", 49);
		exit_error(-1, NULL);
	}
	get_map(&all, &map, argv[1]);
	get_player(&all, &player);
	init_window(&all, &win);
	get_textures(&all, &tex);
	define_hooks(&all);
	mlx_loop(all.win->mlx);
	return (0);
}
