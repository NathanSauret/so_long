/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:16:05 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 17:44:31 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**set_textures_paths(void **textures, int nb_textures, t_map *map)
{
	char	**paths;

	paths = malloc(sizeof(char *) * nb_textures + 1);
	if (!paths)
	{
		free(textures);
		exit_error(0, map, NULL);
	}
	paths[0] = "../../Textures/exit_green.xpm";
	paths[1] = "../../Textures/exit_green.xpm";
	paths[2] = "../../Textures/exit_green.xpm";
	paths[3] = "../../Textures/exit_green.xpm";
	paths[4] = "../../Textures/exit_green.xpm";
	paths[5] = "../../Textures/exit_green.xpm";
	return (paths);
}

void	set_all(t_all *all, t_win *win, t_map *map, t_player *player)
{
	int		nb_textures;
	void	**textures;
	char	**paths;
	int		t_sz;
	int		i;

	nb_textures = 6;
	textures = malloc (sizeof(void) * nb_textures);
	if (!textures)
		exit_error(0, map, NULL);
	paths = set_textures_paths(textures, nb_textures, map);
	t_sz = win->tile_size;
	i = 0;
	while (i < nb_textures)
	{
		textures[i] = mlx_xpm_file_to_image(win->mlx, paths[i], &t_sz, &t_sz);
		i++;
	}
	ft_freetabstr(paths);
	all->win = win;
	all->map = map;
	all->player = player;
	all->textures = textures;
}
