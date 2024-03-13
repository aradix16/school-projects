/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:14 by aradix            #+#    #+#             */
/*   Updated: 2024/03/13 14:04:21 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_player(t_game *game)
{
	game->graphics->sprite->is_moving = false;
}

void	move_player(t_game *game, t_coordinate step)
{
	game->graphics->sprite->is_moving = true;
	(void)step;
}
