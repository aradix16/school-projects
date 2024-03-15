/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/13 22:41:02 by aradix           ###   ########.fr       */
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

/* bool	move_animation(t_game *game, int target_diff) */
/* { */
/* 	const int	step_duration = 140; */
/* 	t_nsec		t0; */
/* 	int			slp; */
/* 	t_nsec		time; */
/* 	int			i; */
/**/
/* 	if (target_diff < step_duration) */
/* 		return (false); */
/* 	if (game->graphics->sprite->state == 0) */
/* 	{ */
/* 		game->graphics->sprite->state = 1; */
/* 		return (true); */
/* 	} */
/**/
/**/
/* 	if (game->graphics->sprite->state == 1) */
/* 		game->graphics->sprite->state = 2; */
/* 	else */
/* 		game->graphics->sprite->state = 1; */
/**/
/**/
/* 	t0 = get_current_time(); */
/* 	slp = 1; */
/* 	i = 0; */
/**/
/* 	t_coordinate start; */
/**/
/* 	get_boundaries(game, game->graphics); */
/**/
/* 	start.x = game->player->pos.x - game->graphics->window->boundaries.x; */
/* 	start.y = game->player->pos.y - game->graphics->window->boundaries.y; */
/* 	while (1) */
/* 	{ */
/* 		time = get_current_time(); */
/* 		target_diff = get_diff_ms(time, t0); */
/* 		if (target_diff < slp) */
/* 		{ */
/* 			game->player->pos.x -= 1; */
/* 			i++; */
/* 			get_boundaries(game, game->graphics); */
/* 			draw_texture_tile(game, start, game->graphics->textures->ground[0].data); */
/* 			draw_player(game); */
/* 			mlx_put_image_to_window(game->graphics->mlx_ptr, */
/* 					game->graphics->window->ptr, game->graphics->frame->image, 0, */
/* 					0); */
/* 			t0 = time; */
/* 			printf("ici"); */
/* 		} */
/* 		if (i == 15) */
/* 			break ; */
/* 	} */
/* 	return (true); */
/* } */


/* bool	move_animation(t_game *game, int target_diff) */
/* { */
/**/
/* 	const int	anim_duration = 140; */
/* 	const int	step_duration = 140; */
/**/
/* 	if (target_diff < anim_duration) */
/* 		return (false); */
/* 	if (game->graphics->sprite->state == 0) */
/* 	{ */
/* 		game->graphics->sprite->state = 1; */
/* 		render(game); */
/* 		return (true); */
/* 	} */
/**/
/* 	game->graphics->sprite->state++; */
/* 	if (game->graphics->sprite->state == 3) */
/* 	{ */
/* 		game->graphics->sprite->state = 1; */
/* 		game->player->pos.x -= 15; */
/* 	} */
/**/
/* 	render(game); */
/**/
/**/
/**/
/* 	printf("ici"); */
/* 	return (true); */
/* } */


bool  sleep_state(t_game *game, int target_diff)
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

	current_time = get_current_time();
	game->graphics->sprite->t0 = current_time;
	render(game);
	return (0);
}
