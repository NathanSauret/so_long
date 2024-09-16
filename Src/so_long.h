/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:14 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/16 17:41:01 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

// player direction can be u (up), d (down), r (right) or l (left)
typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
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
	void	*mlx_win;
	int		height;
	int		width;
	int		tile_size;
}	t_win;

typedef struct s_all
{
	t_win		*win;
	t_map		*map;
	t_player	*player;
	void		**textures;
}	t_all;

// ALL_UTILITIES
// set_all.c
void	set_all(t_all *all, t_win *win, t_map *map, t_player *player);

// EXIT_ERROR
// exit_error.c
void	free_structs(t_map *map, t_all *all);
void	exit_error(int reason, t_map *map, t_all *all);

// MAP_UTILITIES
// display_in_terminal.c
void	display_in_terminal(t_map *map);
// dup_map.c
void	dup_map(t_map *map, t_map *map_copy);
// free_map.c
void	free_map(t_map *map);
// get_map.c
void	get_map(t_map *map, char *map_name);


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
void	parsing(t_map *map);

// PLAYER_UTILITIES
// get_player.c
void	get_player(t_player *player, t_map *map);

// WINDOW
// init_window.c
void	init_window(t_win *win, t_map *map);

#endif