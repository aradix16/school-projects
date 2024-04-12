/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:21:36 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 13:36:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	player_sleep(t_game *game)
{
	const int	sleep_timeout = 1000;

	if (game->graphics->sprite->state == 0
		|| !timeout(game->graphics->sprite->t0, sleep_timeout))
		return (false);
	game->graphics->sprite->state = 0;
	game->graphics->sprite->t0 = get_current_time();
    return (true);
}
