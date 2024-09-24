/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:29:02 by nathan            #+#    #+#             */
/*   Updated: 2024/09/24 20:51:31 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_sprites_struct(t_all *all)
{
	t_player_sprites	*ps;

	ps = &all->ps;
	ps->u1_path = "Textures/Player/u1.xpm";
	ps->u1 = NULL;
	ps->u2_path = "Textures/Player/u2.xpm";
	ps->u2 = NULL;
	ps->d1_path = "Textures/Player/d1.xpm";
	ps->d1 = NULL;
	ps->d2_path = "Textures/Player/d2.xpm";
	ps->d2 = NULL;
	ps->l1_path = "Textures/Player/l1.xpm";
	ps->l1 = NULL;
	ps->l2_path = "Textures/Player/l2.xpm";
	ps->l2 = NULL;
	ps->r1_path = "Textures/Player/r1.xpm";
	ps->r1 = NULL;
	ps->r2_path = "Textures/Player/r2.xpm";
	ps->r2 = NULL;
}

void	get_player_sprites(t_all *all)
{
	t_player_sprites	*ps;

	ps = &all->ps;
	ps->u1 = load_image_into_struct(all, ps->u1_path);
	ps->u2 = load_image_into_struct(all, ps->u2_path);
	ps->d1 = load_image_into_struct(all, ps->d1_path);
	ps->d2 = load_image_into_struct(all, ps->d2_path);
	ps->l1 = load_image_into_struct(all, ps->l1_path);
	ps->l2 = load_image_into_struct(all, ps->l2_path);
	ps->r1 = load_image_into_struct(all, ps->r1_path);
	ps->r2 = load_image_into_struct(all, ps->r2_path);
}
