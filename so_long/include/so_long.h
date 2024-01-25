/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:48 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 16:23:19 by aradix           ###   ########.fr       */
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
	size_t	e_pos;
	size_t	p_pos;
	size_t	c_counter;
}			t_game;

# include <stdbool.h>
# include <stdio.h> // ---

int			print_error(short err_id);

short		parsing(t_game *game, int ac, char **av);
bool		is_file_extension_valid(char *filepath);
bool		is_map_valid(t_game *game);
bool		is_map_playable(t_game *game);

#endif