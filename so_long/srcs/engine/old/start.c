/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:31 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 14:01:05 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_engine(t_game *game)
{
	t_mlx		mlx;
	t_window	window;
	t_image		image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (MLX_INIT_FAILED);
	game->mlx = &mlx;
	if (!create_window(&window, &mlx, game->map))
		return (clean_mlx(&mlx, MLX_WINDOW_FAILED));
	if (!new_image(&image, &mlx))
		return (clean_mlx(&mlx, MLX_WINDOW_FAILED));



	/* creer une image */
	/*  */


	game_loop(game, &mlx);
	return (clean_mlx(game->mlx, SUCCESS));
}
