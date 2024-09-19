/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:30:31 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/19 12:15:20 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_textures_paths(t_all *all)
{
	char	**paths;

	paths = malloc(sizeof(char *) * all->tex->nb_textures);
	if (!paths)
		exit_error(0, all);
	paths[0] = "../../Textures/wall.xpm";
	paths[1] = "../../Textures/wall.xpm";
	paths[2] = "../../Textures/wall.xpm";
	paths[3] = "../../Textures/wall.xpm";
	paths[4] = "../../Textures/wall.xpm";
	paths[5] = "../../Textures/wall.xpm";
	all->tex->paths = paths;
}

void	get_textures(t_all *all, t_textures *tex, t_win *win)
{
	int		tsz;
	int		i;
	char	*p;

	all->tex = tex;
	tsz = win->tile_size;
	tex->nb_textures = 6;
	tex->textures = malloc(sizeof(void *) * tex->nb_textures + 1);
	if (!tex->textures)
		exit_error(0, all);
	get_textures_paths(all);
	i = 0;
	while (i < tex->nb_textures)
	{
		p = tex->paths[i];
		tex->textures[i] = NULL;
		tex->textures[i] = mlx_xpm_file_to_image(win->mlx, p, &tsz, &tsz);
		i++;
	}
}
