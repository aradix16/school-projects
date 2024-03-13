/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/13 20:05:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	move_animation(t_game *game, int target_diff)
{
	const int	step_duration = 140;

	if (target_diff < step_duration)
		return (false);
	if (game->graphics->sprite->state > 0)
		game->player->pos.x -= TILE_SIZE / 2;


	if (game->graphics->sprite->state == 1)
		game->graphics->sprite->state = 2;
	else
		game->graphics->sprite->state = 1;

	return (true);
}

bool	sleep_state(t_game *game, int target_diff)
{
	const int	sleep_duration = 2000;

	if (game->graphics->sprite->state == 0 || target_diff < sleep_duration)
		return (false);
	game->graphics->sprite->state = 0;
	draw_player(game);
	return (true);
}

int	on_mlx_loop(t_game *game)
{
	t_nsec	current_time;
	int		target_diff;

	current_time = get_current_time();
	target_diff = get_diff_ms(current_time, game->graphics->sprite->t0);
	if (!game->graphics->sprite->is_moving && !sleep_state(game, target_diff))
		return (0);
	else if (game->graphics->sprite->is_moving && !move_animation(game,
			target_diff))
		return (0);
	game->graphics->sprite->t0 = current_time;
	render(game);
	return (0);
}
