/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:14 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/27 17:25:29 by nsauret          ###   ########.fr       */
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
	int		frame;
}	t_player;

typedef struct s_ennemies
{
	int		nb_ennemies;
	int		*x;
	int		*y;
	char	*direction;
	int		*is_on_exit;
	int		*is_on_coin;
}	t_ennemies;

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

typedef struct s_walls
{
	char	*ul_path;
	void	*ul;
	char	*u_path;
	void	*u;
	char	*ur_path;
	void	*ur;
	char	*l_path;
	void	*l;
	char	*r_path;
	void	*r;
	char	*dl_path;
	void	*dl;
	char	*d_path;
	void	*d;
	char	*dr_path;
	void	*dr;
	char	*round_path;
	void	*round;
	char	*square_path;
	void	*square;
}	t_walls;

typedef struct s_textures
{
	t_walls	walls;
	char	*bg_path;
	void	*bg;
	char	*eopen_path;
	void	*eopen;
	char	*eclose_path;
	void	*eclose;
	char	*coin_path;
	void	*coin;
}	t_textures;

typedef struct s_player_sprites
{
	char	*u1_path;
	void	*u1;
	char	*u2_path;
	void	*u2;
	char	*d1_path;
	void	*d1;
	char	*d2_path;
	void	*d2;
	char	*l1_path;
	void	*l1;
	char	*l2_path;
	void	*l2;
	char	*r1_path;
	void	*r1;
	char	*r2_path;
	void	*r2;
}	t_player_sprites;

typedef struct s_ennemy_sprites
{
	char	*u_path;
	void	*u;
	char	*d_path;
	void	*d;
	char	*l_path;
	void	*l;
	char	*r_path;
	void	*r;
}	t_ennemy_sprites;

typedef struct s_all
{
	t_map				map;
	t_player			player;
	t_player_sprites	ps;
	t_ennemies			ennemies;
	t_ennemy_sprites	es;
	t_win				win;
	t_textures			tex;
}	t_all;

// CONTROLS
// ennemy_move.c
void	ennemy_move(t_all *all, int id, int go_x, int go_y);
// kill_or_be_killed.c
void	kill_or_be_killed(t_all *all, int go_x, int go_y);
// on_press.c
int		on_keypress(int keysym, t_all *all);
// player_move.c
void	player_move(t_all *all, int go_x, int go_y);

// DISPLAY
// display_player.c
void	display_player(t_all *all, int i, int j);
// display_wall.c
void	display_wall(t_all *all, int i, int j);
// display_ennemi.c
void	display_ennemy(t_all *all, int i, int j);
// display.c
void	color_tile(t_all *all, int tile_x, int tile_y, int color);
int		display(t_all *all);

// ENNEMIES_UTILITIES
// get_ennemies.c
void	get_ennemies(t_all *all);

// EXIT_ERROR
// delete_sprites.c
void	delete_sprites(t_all *all);
// delete_textures.c
void	delete_textures(t_all *all);
// exit_error.c
void	free_structs(t_all *all);
void	exit_error(int reason, t_all *all);

// GAME_END
// game_end.c
void	are_ya_wining_son(t_all *all);
void	game_over(t_all *all);

// MAP_UTILITIES
// display_in_terminal.c
void	display_in_terminal(t_map map);
// dup_map.c
void	dup_map(t_map map, t_map *map_copy);
// free_map.c
void	free_map(t_map *map);
// free_tabstr.c
void	free_tabstr(char **tab);
// get_map_height.c
int		get_map_height(char *map_name, t_all *all);
// get_map.c
void	get_map(t_all *all, char *map_name);
// get_nb_coins.c
int		get_nb_coins(t_all *all);

// PARSING
// are_coins_reachable.c
int		are_coins_reachable(t_all *all);
// check_characters.c
int		check_characters(t_all *all);
// check_walls.c
int		check_walls(t_all *all);
// is_exit_reachable.c
int		is_exit_reachable(t_all *all);
// is_rectangular.c
int		is_rectangular(t_all *all);
// parsing.c
void	parsing(t_all *all);

// PLAYER_UTILITIES
// get_player.c
void	get_player(t_all *all);

// TEXTURES_UTILITIES
// get_ennemy_sprites.c
void	set_ennemies_sprites_struct(t_all *all);
void	get_ennemies_sprites(t_all *all);
// get_player_sprites.c
void	set_player_sprites_struct(t_all *all);
void	get_player_sprites(t_all *all);
// get_textures.c
void	*load_image_into_struct(t_all *all, char *path);
void	set_textures_struct(t_all *all);
void	get_textures(t_all *all);

// WINDOW
// init_window.c
void	init_window(t_all *all);
// destroy_window.c
int		destroy_window(t_all *all);

// MAIN
// main.c
int		terminate(t_all *all);

#endif