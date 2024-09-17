/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:14 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/17 15:43:42 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

// player direction can be u (up), d (down), r (right) or l (left)
typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
	int		is_on_exit;
	int		nb_move;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		nb_coins;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		tile_size;
}	t_win;

typedef struct s_textures
{
	int		nb_textures;
	char	**paths;
	void	**textures;
}	t_textures;

typedef struct s_all
{
	t_map		*map;
	t_player	*player;
	t_win		*win;
	t_textures	*tex;
}	t_all;

// CONTROLS
// moves.c
void	moves(int keysym, t_all *all);
// on_press.c
int		on_keypress(int keysym, t_all *all);

// DISPLAY
// display.c
int		display_using_pixels(t_all *all);
int		display(t_all *all);

// EXIT_ERROR
// exit_error.c
void	free_structs(t_all *all);
void	exit_error(int reason, t_all *all);

// MAP_UTILITIES
// display_in_terminal.c
void	display_in_terminal(t_map *map);
// dup_map.c
void	dup_map(t_map *map, t_map *map_copy);
// free_map.c
void	free_map(t_map *map);
// get_map.c
void	get_map(t_all *all, t_map	*map, char *map_name);


// PARSING
// are_coins_reachable.c
int		are_coins_reachable(t_map *map);
// check_characters.c
int		check_characters(t_map *map);
// check_walls.c
int		check_walls(t_map *map);
// is_exit_reachable.c
int		is_exit_reachable(t_map *map);
// is_rectangular.c
int		is_rectangular(t_map *map);
// parsing.c
void	parsing(t_all *all);

// PLAYER_UTILITIES
// get_player.c
void	get_player(t_all *all, t_player *player);

// TEXTURES_UTILITIES
// get_textures.c
void	get_textures(t_all *all, t_textures *tex);

// WINDOW
// init_window.c
void	init_window(t_all *all, t_win *win);
// destroy_window.c
int		destroy_window(t_all *all);

// MAIN
// main.c
int		terminate(t_all *all);

#endif