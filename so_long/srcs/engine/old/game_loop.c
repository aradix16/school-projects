/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:37:59 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 23:31:38 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stop_loop(t_game *game)
{
	mlx_loop_end(game->mlx->ptr);
	/* return (clean_mlx(game->mlx, SUCCESS)); */
	return (SUCCESS);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	mlx_hook(mlx->window->ptr, 2, (1L << 0), on_key_press, game);
	mlx_hook(mlx->window->ptr, 17, (1L << 17), stop_loop, game);
	mlx_loop_hook(mlx->ptr, on_update, mlx);
	mlx_loop(mlx->ptr);
}
