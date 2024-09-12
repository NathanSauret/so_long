/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:17:14 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/12 18:34:09 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

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
}	t_map;

// exit_error.c
void	exit_error(int reason, t_map *map, t_player *player);

// get_mapc.
void	get_map(t_map *map, char *map_name);

// parsing.c
int		parsing(t_map *map);

#endif