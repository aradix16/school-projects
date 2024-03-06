/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:14 by aradix            #+#    #+#             */
/*   Updated: 2024/03/04 14:30:45 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_player(t_game *game)
{
	game->render->key_press = false;
}

/* void	initer(t_game *game) */
/* { */
/* 	t_coordinate	tmp; */
/* 	t_coordinate	start; */
/**/
/* 	tmp.x = get_boundaries(game->player.x, game->mlx->window->size.x, */
/* 			game->map->size.x); */
/* 	tmp.y = get_boundaries(game->player.y, game->mlx->window->size.y, */
/* 			game->map->size.y); */
/* 	start.x = (game->player.x * TILE_SIZE) - tmp.x; */
/* 	start.y = (game->player.y * TILE_SIZE) - tmp.y; */
/* 	game->render->move = start; */
/* } */

void	move_player(t_game *game, t_coordinate step)
{
	game->render->key_press = true;
	/* if (game->render->key_press == 0) */




	/* if (game->render->animation_state == 0) */
		/* initer(game); */
	(void)step;
}
