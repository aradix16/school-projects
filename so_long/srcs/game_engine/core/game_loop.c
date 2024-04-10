/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:55:39 by aradix            #+#    #+#             */
/*   Updated: 2024/04/10 10:11:34 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	stop_game_loop(t_game *game)
{
	mlx_loop_end(game->graphics->mlx_ptr);
	return (SUCCESS);
}

void	start_game_loop(t_game *game, t_graphics *graphics)
{
	mlx_hook(graphics->window->ptr, 2, (1L << 0), on_key_press, game);
	mlx_hook(graphics->window->ptr, 3, (1L << 1), on_key_release, game);
	mlx_hook(graphics->window->ptr, 17, (1L << 17), stop_game_loop, game);
	mlx_loop_hook(graphics->mlx_ptr, on_mlx_loop, game);
	mlx_loop(graphics->mlx_ptr);
}
