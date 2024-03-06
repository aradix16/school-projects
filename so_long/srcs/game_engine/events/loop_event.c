/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/04 15:14:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	drw(t_game *game)
{
	draw_map(game);
	draw_player(game);
	render(game);
}

int	sleep_animation(t_game *game, t_nsec current_time, int target_diff)
{
	const int	sleep_duration = 1500;

	if (target_diff < sleep_duration)
		return (0);
	game->render->animation_state = 0;
	game->render->t0 = current_time;
	draw_map(game);
	draw_player(game);
	render(game);
	return (0);
}

int move_animation(t_game *game, t_nsec current_time, int target_diff)
{
	const int	tramsition_duration = 120;

	if (target_diff < tramsition_duration)
		return (0);

	game->render->animation_state++;
	game->render->move.x -= TILE_SIZE / 2;
	game->render->t0 = current_time;
	draw_map(game);
	draw_player(game);
	render(game);




	return (0);
}

int	on_mlx_loop(t_game *game)
{
	t_nsec	current_time;
	int		target_diff;

	current_time = get_current_time();
	target_diff = get_diff_ms(current_time, game->render->t0);

	if (game->render->key_press == false)
		return (sleep_animation(game, current_time, target_diff));
	if (game->render->key_press == true)
		move_animation(game, current_time, target_diff);
	return (0);



	if (game->render->animation_state == 0)
	{
		if (game->render->key_press)
		{
			game->render->move.x -= 16;
			drw(game);
			game->render->animation_state = 1;
			game->render->t0 = get_current_time();
		}
		return (0);
	}
	current_time = get_current_time();
	target_diff = get_diff_ms(current_time, game->render->t0);
	if (target_diff < 142)
		return (0);
	/* printf("%d\n", game->render->move.x); */
	if (game->render->animation_state <= 2)
	{
		game->render->move.x -= 16;
		drw(game);
		game->render->animation_state++;
		game->render->t0 = current_time;
		return (0);
	}
	if (!game->render->key_press)
	{
		game->render->animation_state = 0;
		draw_map(game);
		/* printf("-->%d\n", game->state->animation_state); */
		/* game->render->t0 = current_time; */
		/* game->player.x--; */
	}
	else if (game->render->animation_state > 2)
	{
		game->render->animation_state = 1;
		/* game->player.x--; */
	}
	return (0);
}
