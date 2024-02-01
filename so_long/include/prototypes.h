/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:41 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 15:32:44 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int		error_handler(t_game *game, short err);

/* PARSING */
short	parsing(t_game *game, int ac, char **av);
bool	extension_checker(const char *filepath);
short	validity_checker(t_map *map, t_state *state, char *map_content);
short	playability_checker(t_map *map, t_state state);

/* GAME ENGINE */
short	start_engine(t_game *game);
/* bool	load_textures(t_mlx *mlx, t_texture *texture); */
bool	load_textures(t_mlx *mlx, t_texture *texture);
bool	create_window(t_mlx *mlx, t_window *window, t_map *map);
bool	new_frame(t_game *game, t_mlx *mlx, t_frame *frame, t_window *window);
void	draw_frame(t_game *game, t_frame *frame);
int		render_frame(t_mlx *mlx);
void	start_game_loop(t_game *game, t_mlx *mlx);
int		stop_game_loop(t_game *game);
int		key_press_event(int key, t_game *game);
int		update_event(t_game *game);
void	update_player_position(t_map *map, t_state *state, size_t direction);
bool	check_player_position(t_map *map, t_state *state);
void	clean_textures(t_mlx *mlx, t_texture *texture, int i);
short	clean_mlx(t_mlx *mlx, short state);

#endif
