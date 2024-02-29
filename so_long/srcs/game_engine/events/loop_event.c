/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/02/29 23:42:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drw(t_game *game)
{
	draw_map(game);
	draw_player(game);
	render(game);
}

int	on_mlx_loop(t_game *game)
{
	int		target_diff;
	t_nsec	current_time;

	if (game->render->animation_state == 0)
	{
		if (game->render->key_press)
		{
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
		game->render->t0 = current_time;
		/* game->player.x--; */
	}
	else if (game->render->animation_state > 2)
	{
		game->render->animation_state = 1;
		/* game->player.x--; */
	}
	return (0);
}
