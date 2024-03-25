/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/25 15:41:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sleep_anim(t_game *game, t_nsec current_time)
{
	int	target_diff;

	if (game->graphics->sprite->state == 0)
		return (0);
	target_diff = get_diff_ms(current_time, game->graphics->sprite->t0);
	if (target_diff < 1000)
		return (0);
	game->graphics->sprite->state = 0;
	render(game);
	return (0);
}

bool	player_move(t_game *game, t_nsec current_time)
{
	int	target_diff;
	int	pixels_to_move;

	target_diff = get_diff_ms(current_time, game->graphics->sprite->p0);
	if (target_diff < 30)
		return (false);
	game->graphics->sprite->p0 = current_time;


	pixels_to_move = 5;
	if (game->graphics->sprite->step.x != 0)
	{
		pixels_to_move *= game->graphics->sprite->step.x;
		game->player->pos.x += pixels_to_move;
	}
	else if (game->graphics->sprite->step.y != 0)
	{
		pixels_to_move *= game->graphics->sprite->step.y;
		game->player->pos.y += pixels_to_move;
	}
	return (true);
}

bool	sprite_anim(t_game *game, t_nsec current_time)
{
	int	target_diff;

	target_diff = get_diff_ms(current_time, game->graphics->sprite->t0);
	if (target_diff < 130)
		return (false);
	game->graphics->sprite->t0 = current_time;
	game->graphics->sprite->state++;
	if (game->graphics->sprite->state == 3)
		game->graphics->sprite->state = 1;
	return (true);
}

int	on_mlx_loop(t_game *game)
{
	t_nsec	current_time;

	current_time = get_current_time();
	if (!game->graphics->sprite->is_moving)
		return (sleep_anim(game, current_time));
	if (sprite_anim(game, current_time) || player_move(game, current_time))
		render(game);
	return (0);
}
