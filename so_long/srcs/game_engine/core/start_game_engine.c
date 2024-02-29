/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:22:02 by aradix            #+#    #+#             */
/*   Updated: 2024/02/29 09:52:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_game_engine(t_game *game)
{
	t_mlx		mlx;
	t_textures	textures;
	t_window	window;
	t_mlx_img	frame;
	t_animation	anim;

	if (!initialize_display_connection(game, &mlx))
		return (MLX_INIT_FAILED);
	if (!load_textures(&mlx, &textures))
		return (clean_mlx(&mlx, LOAD_TEXTURES_FAILED));
	if (!create_new_window(&mlx, &window, game->map))
		return (clean_mlx(&mlx, MLX_WINDOW_FAILED));
	if (!create_new_frame(&mlx, &frame, &window))
		return (clean_mlx(&mlx, MLX_IMAGE_FAILED));
	prerender(game, &anim);
	start_game_loop(game, &mlx);
	return (clean_mlx(&mlx, SUCCESS));
}
