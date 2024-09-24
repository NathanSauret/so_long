/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ennemies_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:08:10 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/24 15:18:38 by nsauret          ###   ########.fr       */
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

void	set_ennemies_sprites_struct(t_all *all)
{
	t_ennemy_sprites	*es;

	es = &all->es;
	es->u_path = "Textures/Ennemy/ennemy_up.xpm";
	es->u = NULL;
	es->d_path = "Textures/Ennemy/ennemy_down.xpm";
	es->d = NULL;
	es->l_path = "Textures/Ennemy/ennemy_left.xpm";
	es->l = NULL;
	es->r_path = "Textures/Ennemy/ennemy_right.xpm";
	es->r = NULL;
}

void	get_ennemies_sprites(t_all *all)
{
	t_ennemy_sprites	*es;

	es = &all->es;
	es->u = load_image_into_struct(all, es->u_path);
	es->d = load_image_into_struct(all, es->d_path);
	es->l = load_image_into_struct(all, es->l_path);
	es->r = load_image_into_struct(all, es->r_path);
}
