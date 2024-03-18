/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/18 23:01:42 by aradix           ###   ########.fr       */
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

void sprite_anim(t_game *game, t_nsec current_time)
{
    int target_diff;

    target_diff = get_diff_ms(current_time, game->graphics->sprite->t0);
    if (target_diff < 130) // Adjusted for smoother animation
        return;
    game->graphics->sprite->t0 = current_time;
    game->graphics->sprite->state++;
    if (game->graphics->sprite->state == 3)
        game->graphics->sprite->state = 1;
}

void player_move(t_game *game, t_nsec current_time)
{
    int target_diff;
    int pixels_to_move;

    target_diff = get_diff_ms(current_time, game->graphics->sprite->p0);
    if (target_diff < 30) // Adjusted for frame-rate independent movement
        return;
    game->graphics->sprite->p0 = current_time;
    pixels_to_move = 5;
    game->player->pos.x -= pixels_to_move;
}



int on_mlx_loop(t_game *game)
{
    t_nsec current_time;

    current_time = get_current_time();
    if (!game->graphics->sprite->is_moving)
        return (sleep_anim(game, current_time));
    sprite_anim(game, current_time); // Smooth animation
    player_move(game, current_time); // Frame-rate independent movement
    render(game);
    return (0);
}
