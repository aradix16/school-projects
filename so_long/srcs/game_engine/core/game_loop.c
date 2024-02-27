/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:55:39 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 20:15:57 by aradix           ###   ########.fr       */
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
	mlx_hook(mlx->window->ptr, 2, (1L << 0), handle_key_press, game);
	mlx_hook(mlx->window->ptr, 17, (1L << 17), stop_game_loop, game);
	mlx_loop(mlx->ptr);
}
