/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:42:14 by aradix            #+#    #+#             */
/*   Updated: 2024/01/24 13:07:27 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* bool is_map_playable(char *map) */
/* { */
/**/
/* } */

/* { */
/* 	size_t	i; */
/**/
/* 	i = 0; */
/* 	while (map[i]) */
/* 	{ */
/* 	} */
/* } */

bool	is_map_content_valid(t_game *game)
{
	size_t	i;

	if (!is_boundary_line_valid(game))
		return (false);
	i = game->map_x;
	while (game->map[i] == '\n' && game->map[i + 1])
	{
		if (!is_inner_line_valid(game))
			return (false);
		i += game->map_x + 1;
	}
	if (!is_boundary_line_valid(game))
		return (false);
	return (true);
}

short	parse_map(t_game *game, char *map)
{
	if (!map)
		return (3);
	game->map = map;
	if (!is_map_content_valid(game))
		return (4);
	// parse_map_validity
	return (0);
}
