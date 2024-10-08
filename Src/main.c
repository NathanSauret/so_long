/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:59:06 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/27 17:47:07 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

int	terminate(t_all *all)
{
	free_structs(all);
	destroy_window(all);
	free(all->win.mlx);
	exit (0);
}

static int	loop(t_all *all)
{
	if (all->player.is_on_exit && all->map.nb_coins == 0)
		are_ya_wining_son(all);
	return (0);
}

static int	define_hooks(t_all *all)
{
	t_win	*win;

	win = &all->win;
	mlx_hook(win->win, DestroyNotify, StructureNotifyMask, &terminate, all);
	mlx_hook(win->win, KeyPress, KeyPressMask, &on_keypress, all);
	mlx_loop_hook(win->mlx, &loop, all);
	display(all);
	return (0);
}

static void	set_default_values(t_all *all)
{
	srand(time(NULL));
	set_textures_struct(all);
	set_player_sprites_struct(all);
	set_ennemies_sprites_struct(all);
	all->map.map = NULL;
	all->ennemies.direction = NULL;
	all->win.mlx = mlx_init();
	all->win.tile_size = 64;
}

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 2)
	{
		write(2, "Error:\nThe program needs one argument: map file\n", 49);
		exit(1);
	}
	set_default_values(&all);
	get_map(&all, argv[1]);
	get_player(&all);
	get_player_sprites(&all);
	get_ennemies(&all);
	get_ennemies_sprites(&all);
	get_textures(&all);
	init_window(&all);
	define_hooks(&all);
	mlx_loop(all.win.mlx);
	return (0);
}
