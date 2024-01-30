/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:31 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 23:42:21 by aradix           ###   ########.fr       */
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


	/* creer une image */
	image.ptr = mlx_new_image(game->mlx->ptr, window.width, window.height);
	image.data = mlx_get_data_addr(image.ptr, &bits_per_pixel, &size_line,
			&endian);
	mlx.image = &image;
	render(game);
	/*  */


	game_loop(game, &mlx);
	return (clean_mlx(game->mlx, SUCCESS));
}

// todo
// creer une image DONE
// render la map
//
// dans le loop si je up down left right  DONE
// move le player  DONE
// re render la map
