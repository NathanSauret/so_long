/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:30:31 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/20 17:11:18 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_image_into_struct(t_all *all, char *path)
{
	int			tsz;
	void		*image;

	tsz = all->win.tile_size;
	image = mlx_xpm_file_to_image(all->win.mlx, path, &tsz, &tsz);
	if (!image)
	{
		write(2, "Error: Texture not found: ", 27);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit_error(-1, all);
	}
	return (image);
}

static void	set_wall_textures(t_all *all)
{
	all->tex.walls.ul_path = "Textures/ul.xpm";
	all->tex.walls.ul = NULL;
	all->tex.walls.u_path = "Textures/u.xpm";
	all->tex.walls.u = NULL;
	all->tex.walls.ur_path = "Textures/ur.xpm";
	all->tex.walls.ur = NULL;
	all->tex.walls.l_path = "Textures/l.xpm";
	all->tex.walls.l = NULL;
	all->tex.walls.r_path = "Textures/r.xpm";
	all->tex.walls.r = NULL;
	all->tex.walls.dl_path = "Textures/dl.xpm";
	all->tex.walls.dl = NULL;
	all->tex.walls.d_path = "Textures/d.xpm";
	all->tex.walls.d = NULL;
	all->tex.walls.dr_path = "Textures/dr.xpm";
	all->tex.walls.dr = NULL;
	all->tex.walls.round_path = "Textures/round.xpm";
	all->tex.walls.round = NULL;
	all->tex.walls.square_path = "Textures/square.xpm";
	all->tex.walls.square = NULL;
}

void	set_textures_struct(t_all *all)
{
	all->tex.bg_path = "Textures/background.xpm";
	all->tex.bg = NULL;
	all->tex.eopen_path = "Textures/exit_green.xpm";
	all->tex.eopen = NULL;
	all->tex.eclose_path = "Textures/exit_red.xpm";
	all->tex.eclose = NULL;
	all->tex.coin_path = "Textures/coin.xpm";
	all->tex.coin = NULL;
	set_wall_textures(all);
}

void	get_textures(t_all *all)
{
	t_walls	*walls;

	walls = &all->tex.walls;
	walls->ul = load_image_into_struct(all, walls->ul_path);
	walls->u = load_image_into_struct(all, walls->u_path);
	walls->ur = load_image_into_struct(all, walls->ur_path);
	walls->l = load_image_into_struct(all, walls->l_path);
	walls->r = load_image_into_struct(all, walls->r_path);
	walls->dl = load_image_into_struct(all, walls->dl_path);
	walls->d = load_image_into_struct(all, walls->d_path);
	walls->dr = load_image_into_struct(all, walls->dr_path);
	walls->square = load_image_into_struct(all, walls->square_path);
	walls->round = load_image_into_struct(all, walls->round_path);
	all->tex.bg = load_image_into_struct(all, all->tex.bg_path);
	all->tex.eopen = load_image_into_struct(all, all->tex.eopen_path);
	all->tex.eclose = load_image_into_struct(all, all->tex.eclose_path);
	all->tex.coin = load_image_into_struct(all, all->tex.coin_path);
}
