/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:14 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/15 01:49:46 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
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

// EXIT_ERROR
// exit_error.c
void	exit_error(int reason, t_map *map);

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

#endif