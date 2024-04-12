/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:20:59 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 13:36:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	player_animation(t_game *game)
{
	const int	anim_timeout = 90;

	if (!timeout(game->graphics->sprite->p0, anim_timeout))
		return (false);
	++game->graphics->sprite->state;
	if (game->graphics->sprite->state > 2)
		game->graphics->sprite->state = 1;
	game->graphics->sprite->p0 = get_current_time();
    return (true);
}
