/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:19 by aradix            #+#    #+#             */
/*   Updated: 2024/02/12 20:21:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/* ERROR */
int		print_error(short err);

/* PARSING */
short	parsing(t_game *game, int ac, char **av);
bool	check_extension(const char *filepath);
short	read_and_store_map(t_map *map, int fd);
short	check_map_validity(t_map *map, t_state *state);
short	check_map_playability(t_game *game, t_map *map, t_state *state);

/* ENGINE */
short	start_engine(t_game *game);
short	clean_mlx(t_mlx *mlx, short state);
bool	load_textures(t_mlx *mlx, t_texture *texture);
bool	create_window(t_mlx *mlx, t_window *window, t_map *map);
bool	new_frame(t_game *game, t_mlx *mlx, t_frame *frame, t_window *window);
void	start_game_loop(t_game *game);
int		stop_game_loop(t_game *game);
int		key_press_event(int key, t_game *game);
void	update_player_position(t_map *map, t_state *state, t_pos updated_pos);
int		render_frame(t_mlx *mlx);
void	draw_frame(t_game *game, t_frame *frame);

#endif
