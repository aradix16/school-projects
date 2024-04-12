/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:19 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 15:07:26 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

// ERROR
# include "struct.h"
int		print_error(short err);

// PARSING
short	parsing(t_game *game, int ac, char **av);
bool	check_map_extension(const char *filepath);
short	read_and_store_map(t_map *map, int fd);
short	check_map_validity(t_game *game, t_map *map);
short	check_map_playability(t_game *game, t_map *map);

// GAME ENGINE
// └── core
short	start_game_engine(t_game *game);
void	start_game_loop(t_game *game, t_graphics *graphics);
int		stop_game_loop(t_game *game);
// └── init
bool	initialize_display_connection(t_graphics *graphics);
bool	create_new_window(t_graphics *graphics, t_window *window,
			t_coordinate map_size);
bool	load_textures(t_graphics *graphics, t_textures *textures);
bool	create_new_frame_buffer(t_graphics *graphics, t_mlx_img *frame,
			t_coordinate window_size);
// └── cleanup
short	clean_mlx(t_graphics *graphics, short state);
void	clean_textures(t_xvar *mlx_ptr, t_textures *textures);
// └── events
int		on_key_press(int key, t_game *game);
int		on_key_release(int key, t_game *game);
int		on_mlx_loop(t_game *game);
// └── utils
t_nsec	get_current_time(void);
int		get_diff_ms(t_nsec nano, t_nsec t0);
bool	timeout(const t_nsec t0, const int duration);
// └── player
bool	player_sleep(t_game *game);
bool	player_move(t_game *game);
bool	player_animation(t_game *game);
// └── graphics
void	render(t_game *game, bool lazy_draw);
//      └── utils
void	get_boundaries(t_game *game, t_graphics *graphics);
//      └── draw
void	draw_player(t_game *game);
void	draw_map(t_game *game);
void	lazy_draw_map(t_game *game);
void	draw_texture_tile(t_game *game, t_coordinate start_pos,
			int *texture_data, short facing);

#endif
