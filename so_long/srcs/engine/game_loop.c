/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:11:49 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 16:18:46 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stop_game_loop(t_game *game)
{
	mlx_loop_end(game->mlx->ptr);
	return (SUCCESS);
}

void	start_game_loop(t_game *game)
{
	mlx_hook(game->mlx->window->ptr, 2, (1L << 0), key_press_event, game);
	mlx_hook(game->mlx->window->ptr, 4, (1L << 17), stop_game_loop, game);
	mlx_loop(game->mlx->ptr);
}
