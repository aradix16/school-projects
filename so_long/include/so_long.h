/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:48 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 14:16:45 by aradix           ###   ########.fr       */
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
# define MLX_INIT_FAILED 14
# define MLX_WINDOW_FAILED 15
# define MLX_TEXTURES_ERROR 16
/* */
# define WALL_TEXTURE "wall.xpm"
/* */
# define ESC 65307

# define TILE_SIZE 100

/* */
# define GREEN 65280;

# include "libft.h"
# include "mlx.h"

typedef struct s_image
{
	void		*ptr;
	int			*data;
}				t_image;

typedef struct s_texture
{
	void		*ptr;
	int			width;
	int			height;
}				t_texture;

typedef struct s_window
{
	int			x;
	int			y;
}				t_window;

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	t_window	*w;
	t_image		*i;
}				t_mlx;

typedef struct s_map
{
	char		*map;
	size_t		cols;
	size_t		rows;
}				t_map;

typedef struct s_game
{
	size_t		collectibles_count;
	size_t		exit_position;
	size_t		player_position;
	t_map		*map;
}				t_game;

# include <stdbool.h>
# include <stdio.h> // ---

int				print_error(short err_id);

/* PARSING */
short			parsing(t_game *game, int ac, char **av);
bool			extension_checker(const char *filepath);
short			validity_checker(t_game *game, char *map);
short			playability_checker(t_game game);

/* ENGINE */
short			start_engine(t_game *game);
bool			create_window(t_window *window, t_mlx *mlx, t_map *map);
bool			load_textures(t_texture *texture, t_mlx *mlx);
void			game_loop(t_game *game, t_mlx *mlx, t_window *window);
int				close_window(void);

#endif
