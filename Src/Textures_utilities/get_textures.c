/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:30:31 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 16:45:32 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_image_into_struct(t_all *all, char *path)
{
	int			tsz;
	t_textures	*tex;
	void		*image;

	tsz = all->win->tile_size;
	tex = all->tex;
	image = mlx_xpm_file_to_image(all->win->mlx, path, &tsz, &tsz);
	if (!image)
	{
		write(2, "Error: Texture not found: ", 27);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit_error(-1, all);
	}
	return (image);
}

static void	set_textures_struct(t_all *all)
{
	t_textures	*tex;

	tex = all->tex;
	tex->wall_path = "Textures/wall.xpm";
	tex->wall = NULL;
	tex->bg_path = "Textures/background.xpm";
	tex->bg = NULL;
	tex->eopen_path = "Textures/exit_green.xpm";
	tex->eopen = NULL;
	tex->eclose_path = "Textures/exit_red.xpm";
	tex->eclose = NULL;
	tex->coin_path = "Textures/coin.xpm";
	tex->coin = NULL;
}

void	get_textures(t_all *all, t_textures *tex, t_win *win)
{
	all->tex = tex;
	all->win = win;
	set_textures_struct(all);
	tex->wall = load_image_into_struct(all, tex->wall_path);
	tex->bg = load_image_into_struct(all, tex->bg_path);
	tex->eopen = load_image_into_struct(all, tex->eopen_path);
	tex->eclose = load_image_into_struct(all, tex->eclose_path);
	tex->coin = load_image_into_struct(all, tex->coin_path);
}
