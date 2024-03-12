/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/12 15:28:17 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	move_animation(t_game *game, int target_diff)
{
	const int	sleep_duration = 200;

	(void)game;
	if (target_diff < sleep_duration)
		return (false);



	/* game->render->animation_state = 0; */
	/* game->render->t0 = current_time; */
	/* draw_map(game); */
	/* draw_player(game); */
	/* render(game); */
	return (true);
}

int	sleep_animation(t_game *game, int target_diff)
{
	const int	sleep_duration = 2000;

	(void)game;
	if (target_diff < sleep_duration)
		return (false);
	printf("sleep\n");
	return (true);
}

int	on_mlx_loop(t_game *game)
{
	t_nsec	current_time;
	int		target_diff;

	current_time = get_current_time();
	target_diff = get_diff_ms(current_time, game->graphics->t0);
	if (!game->graphics->rendering && !sleep_animation(game, target_diff))
		return (0);
	else if (game->graphics->rendering && !move_animation(game, target_diff))
		return (0);
	game->graphics->t0 = current_time;
	return (0);
}

/**/
/**/
/* if (game->render->key_press == false) */
/* 	return (sleep_animation(game, current_time, target_diff)); */
/* if (game->render->key_press == true) */
/* 	move_animation(game, current_time, target_diff); */
/* return (0); */
/**/
/**/
/**/
/* if (game->render->animation_state == 0) */
/* { */
/* 	if (game->render->key_press) */
/* 	{ */
/* 		game->render->move.x -= 16; */
/* 		drw(game); */
/* 		game->render->animation_state = 1; */
/* 		game->render->t0 = get_current_time(); */
/* 	} */
/* 	return (0); */
/* } */
/* current_time = get_current_time(); */
/* target_diff = get_diff_ms(current_time, game->render->t0); */
/* if (target_diff < 142) */
/* 	return (0); */
/* printf("%d\n", game->render->move.x); */
/* if (game->render->animation_state <= 2) */
/* { */
/* 	game->render->move.x -= 16; */
/* 	drw(game); */
/* 	game->render->animation_state++; */
/* 	game->render->t0 = current_time; */
/* 	return (0); */
/* } */
/* if (!game->render->key_press) */
/* { */
/* 	game->render->animation_state = 0; */
/* 	draw_map(game); */
/* printf("-->%d\n", game->state->animation_state); */
/* game->render->t0 = current_time; */
/* game->player.x--; */
/* } */
/* else if (game->render->animation_state > 2) */
/* { */
/* game->render->animation_state = 1; */
/* game->player.x--; */
/* 	} */
/* 	return (0); */
/* } */
