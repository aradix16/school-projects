/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:45:53 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 14:01:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_engine(t_game *game)
{
	t_mlx		mlx;
	t_window	window;
	t_texture	texture;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (MLX_INIT_FAILED);
	if (!create_window(&window, &mlx, game->map))
		return (MLX_WINDOW_FAILED);
	if (!load_textures(&texture, &mlx))
		return (MLX_TEXTURES_ERROR);
	game_loop(game, &mlx, &window);
	return (0);
}
