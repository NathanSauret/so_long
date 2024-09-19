/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:36:36 by nathan            #+#    #+#             */
/*   Updated: 2024/09/19 16:51:35 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_player_location(t_map map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map[i][j] == 'P')
			{
				player->y = i;
				player->x = j;
			}
			j++;
		}
		i++;
	}
}

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

static void	set_player_struct(t_all *all)
{
	t_player_sprites	*ps;

	ps = all->ps;
	ps->u1_path = "Textures/Player/u1.xpm";
	ps->u1 = NULL;
	ps->u2_path = "Textures/Player/u1.xpm";
	ps->u2 = NULL;
	ps->d1_path = "Textures/Player/u1.xpm";
	ps->d1 = NULL;
	ps->d2_path = "Textures/Player/u1.xpm";
	ps->d2 = NULL;
	ps->l1_path = "Textures/Player/u1.xpm";
	ps->l1 = NULL;
	ps->l2_path = "Textures/Player/u1.xpm";
	ps->l2 = NULL;
	ps->r1_path = "Textures/Player/u1.xpm";
	ps->r1 = NULL;
	ps->r2_path = "Textures/Player/u1.xpm";
	ps->r2 = NULL;
}

static void	get_player_sprites(t_all *all)
{
	t_player_sprites	*ps;

	ps = all->ps;
	ps->u1 = load_image_into_struct(all, ps->u1_path);
	ps->u2 = load_image_into_struct(all, ps->u2_path);
	ps->d1 = load_image_into_struct(all, ps->d1_path);
	ps->d2 = load_image_into_struct(all, ps->d2_path);
	ps->l1 = load_image_into_struct(all, ps->l1_path);
	ps->l2 = load_image_into_struct(all, ps->l2_path);
	ps->r1 = load_image_into_struct(all, ps->r1_path);
	ps->r2 = load_image_into_struct(all, ps->r2_path);
}

void	get_player(t_all *all, t_player *player)
{
	t_map				map;
	t_player_sprites	ps;

	all->player = player;
	all->ps = &ps;
	map = all->map;
	get_player_location(map, player);
	player->direction = 'r';
	player->is_on_exit = 0;
	player->nb_move = 0;
	player->frame = 0;
	set_player_struct(all);
	get_player_sprites(all);
}
