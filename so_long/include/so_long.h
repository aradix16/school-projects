/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:48 by aradix            #+#    #+#             */
/*   Updated: 2024/01/24 12:57:28 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define VALID_CHAR "10"

# define ERR_ID_1 "Invalid number of arguments"
# define ERR_ID_2 "Invalid map descriptor file extension"
# define ERR_ID_3 "Can't read map descriptor file"
# define ERR_ID_4 "Map have a wrong format"

# include "libft.h"

typedef struct s_game
{
	char	*map;
	size_t	map_x;
	size_t	map_y;
	size_t	map_size;
}			t_game;

# include <stdbool.h>
# include <stdio.h> // ---

int			print_error(short err_id);

short		parsing(t_game *game, int ac, char **av);
short		parse_map(t_game *game, char *map);
bool		is_boundary_line_valid(t_game *game);
bool		is_inner_line_valid(t_game *gamemiddle_line_valid);

#endif
