/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:31 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 21:53:55 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_engine(t_game *game)
{
	t_mlx		mlx;
	t_window	window;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (MLX_INIT_FAILED);
	game->mlx = &mlx;
	if (!create_window(&window, &mlx, game->map))
		return (clean_mlx(&mlx, MLX_WINDOW_FAILED));
	game_loop(game, &mlx);
	return (clean_mlx(game->mlx, SUCCESS));
}
