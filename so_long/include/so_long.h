/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:48 by aradix            #+#    #+#             */
/*   Updated: 2024/01/29 09:53:55 by aradix           ###   ########.fr       */
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
# define MALLOC_ERROR 1
# define INVALID_ARG_NUMBERS 2
# define INVALID_FILE_EXTENSION 3
# define CANNOT_READ_MAP_FILE 4
# define MAP_NOT_CLOSED 5
# define INVALID_LINE_SIZE 6
# define INVALID_MAP_CHARACTER 7
# define DUPLICATE_EXIT 8
# define DUPLICATE_PLAYER 9
# define NO_COLLECTIBLE_FOUND 10
# define NO_EXIT_FOUND 11
# define NO_PLAYER_FOUND 12
# define UNPLAYABLE_MAP 13

/* */

# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	const char	*map;
	size_t		cols;
	size_t		rows;
	size_t		collectibles_count;
	size_t		exit_position;
	size_t		player_position;
}				t_game;

# include <stdbool.h>
# include <stdio.h> // ---

int				print_error(short err_id);

/* PARSING */
short			parsing(t_game *game, int ac, char **av);
bool			check_file_extension(const char *filepath);
short			check_map_validity(t_game *game, char *map_content);
short			check_map_playability(t_game game);

#endif
