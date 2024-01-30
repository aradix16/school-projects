/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:41 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 21:54:16 by aradix           ###   ########.fr       */
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
bool	create_window(t_window *window, t_mlx *mlx, t_map *map);
void	game_loop(t_game *game, t_mlx *mlx);
int		stop_loop(t_game *game);
int		on_update(t_mlx *mlx);
int		on_key_press(int key, t_game *game);
short	clean_mlx(t_mlx *mlx, short state);

#endif
