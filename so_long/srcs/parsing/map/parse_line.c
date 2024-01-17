/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:29:40 by aradix            #+#    #+#             */
/*   Updated: 2024/01/24 13:11:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_boundary_line_valid(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i] && game->map[i] != '\n')
	{
		if (game->map[i] != '1')
			return (false);
		++i;
	}
	if (game->map_x == 0)
		game->map_x = i;
	else if (game->map_x != i)
		return (false);
	return (true);
}

bool	is_inner_line_valid(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->map[0] != '1')
		return (false);
	while (game->map[i] && game->map[i] != '\n')
	{
		// check is c un char valide 
		//
		// is c un P ou un C ou un E save pos avec une fonction save()

		i++;
	}
	return (i == game->map_x && game->map[i - 1] == '1');
}

// check last line
/* parse_line();  */
/**/
/* if (game->map[i] == '\n') */
/* { */
/* 	if (game->map[i + 1] == '\0') */
/* 		break ; */
/* 	if ((i + 1) % (game->map_x + 1) != 0) */
/* 		return (1); */
/* 	++game->map_y; */
/* } */
/* i++; */
/* printf("%s\n", &game->map[i]); */
