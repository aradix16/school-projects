/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:19 by aradix            #+#    #+#             */
/*   Updated: 2024/02/29 10:54:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/* ERROR */
int		print_error(short err);

/* PARSING */
short	parsing(t_game *game, int ac, char **av);
bool	check_map_extension(const char *filepath);
short	read_and_store_map(t_map *map, int fd);
short	check_map_validity(t_game *game, t_map *map);
short	check_map_playability(t_game *game, t_map *map);

/* GAME ENGINE */
short	start_game_engine(t_game *game);
bool	initialize_display_connection(t_game *game, t_mlx *mlx);
bool	load_textures(t_mlx *mlx, t_textures *textures);
bool	create_new_window(t_mlx *mlx, t_window *window, t_map *map);
bool	create_new_frame(t_mlx *mlx, t_mlx_img *frame, t_window *window);
short	clean_mlx(t_mlx *mlx, short state);
void	clean_textures(t_mlx *mlx, t_textures *textures);
void	start_game_loop(t_game *game, t_mlx *mlx);
int		stop_game_loop(t_game *game);
int		handle_key_press(int key, t_game *game);
void	update_player_position(t_game *game, t_map *map, t_coordinate move);
int		render(t_game *game);
void	draw_map(t_game *game);
float	get_boundaries(int player_pos, int window_size, int map_size);
void	draw_texture_tile(t_game *game, t_coordinate start_pos,
			int *texture_data);

int		player_animation(t_game *game);

void	prerender(t_game *game, t_animation *player_animation);

void	draw_player(t_game *game, t_coordinate position);

t_nsec	get_current_time(void);
int		get_diff_ms(t_nsec nano, t_nsec t0);

#endif
