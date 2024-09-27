/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:28:49 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/27 16:25:56 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*get_endgame_image(t_all *all, char *path)
{
	int		size;
	void	*image;

	size = 512;
	image = mlx_xpm_file_to_image(all->win.mlx, path, &size, &size);
	if (!image)
	{
		write(2, "Error:\nTexture not found: ", 27);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		terminate(all);
	}
	return (image);
}

void	are_ya_wining_son(t_all *all)
{
	int		i;
	void	*image;
	int		x;
	int		y;

	image = get_endgame_image(all, "Textures/win.xpm");
	ft_printf("Great Job!\n");
	x = (all->win.width / 2) - 256;
	y = (all->win.height / 2) - 256;
	i = 0;
	while (i < 3000)
	{
		mlx_clear_window(all->win.mlx, all->win.win);
		mlx_put_image_to_window(all->win.mlx, all->win.win, image, x, y);
		i++;
	}
	mlx_destroy_image(all->win.mlx, image);
	terminate(all);
}

void	game_over(t_all *all)
{
	int		i;
	void	*image;
	int		x;
	int		y;

	image = get_endgame_image(all, "Textures/game_over.xpm");
	ft_printf("Game Over\n");
	x = (all->win.width / 2) - 256;
	y = (all->win.height / 2) - 256;
	i = 0;
	while (i < 3000)
	{
		mlx_clear_window(all->win.mlx, all->win.win);
		mlx_put_image_to_window(all->win.mlx, all->win.win, image, x, y);
		i++;
	}
	mlx_destroy_image(all->win.mlx, image);
	terminate(all);
}
