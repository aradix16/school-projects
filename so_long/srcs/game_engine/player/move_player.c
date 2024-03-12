/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:14 by aradix            #+#    #+#             */
/*   Updated: 2024/03/12 14:53:24 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_player(t_game *game)
{
	game->graphics->rendering = false;
}

void	move_player(t_game *game, t_coordinate step)
{
	game->graphics->rendering = true;
	(void)step;
}
