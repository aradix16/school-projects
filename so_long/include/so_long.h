/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:48 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 19:14:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERR_ID_1 "Invalid number of arguments"
# define ERR_ID_2 "Invalid map descriptor file extension"
# define ERR_ID_3 "Can't read map descriptor file"
# define ERR_ID_4 "Map have a wrong format"

/* */
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
/* */
# define INVALID_ARG_NUMBERS 2
# define INVALID_FILE_EXTENSION 3
# define CANNOT_READ_MAP_FILE 4
# define MAP_NOT_CLOSED 5
# define INVALID_LINE_SIZE 6
# define INVALID_MAP_CHARACTER 7
# define DUPLICATE_EXIT 8
# define DUPLICATE_PLAYER 9

# include "libft.h"

typedef struct s_map
{
	char		*map;
	size_t		col;
	size_t		row;
	size_t		exit_position;
	size_t		player_position;
	size_t		collectibles;
}				t_map;

typedef struct s_game
{
	t_map		m;
}				t_game;

# include <stdbool.h>
# include <stdio.h> // ---

int				print_error(short err_id);

/* PARSING */
short			parsing(t_game *game, int ac, char **av);
bool			check_file_extension(char *filepath);
short			check_map_validity(t_map *m, char *map);
short			check_map_playability(t_map *m);

#endif
