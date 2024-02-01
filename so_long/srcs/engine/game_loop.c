/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:13:03 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 14:06:28 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stop_game_loop(t_game *game)
{
	mlx_loop_end(game->mlx->ptr);
	return (SUCCESS);
}

void	start_game_loop(t_game *game, t_mlx *mlx)
{
	mlx_hook(mlx->window->ptr, 2, (1L << 0), key_press_event, game);
	mlx_hook(mlx->window->ptr, 17, (1L << 17), stop_game_loop, game);
	mlx_loop_hook(mlx->ptr, render_frame, game->mlx);
	mlx_loop(mlx->ptr);
}
