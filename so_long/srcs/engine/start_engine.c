/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 18:18:58 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_engine(t_game *game)
{
	t_mlx		mlx;
	t_texture	texture[NB_TEXTURES];
	t_window	window;
	t_frame		frame;

	game->mlx = &mlx;
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (MLX_INIT_FAILED);
	if (!load_textures(&mlx, texture))
		return (clean_mlx(&mlx, LOAD_TEXTURES_FAILED));
	if (!create_window(&mlx, &window, game->map))
		return (clean_mlx(&mlx, MLX_WINDOW_FAILED));
	if (!new_frame(game, &mlx, &frame, &window))
		return (clean_mlx(&mlx, MLX_IMAGE_FAILED));
	start_game_loop(game, &mlx);
	return (clean_mlx(&mlx, SUCCESS));
}
