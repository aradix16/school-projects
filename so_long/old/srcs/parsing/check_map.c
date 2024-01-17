/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:07:12 by aradix            #+#    #+#             */
/*   Updated: 2024/01/17 20:35:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	red(void)
{
	printf("\033[1;31m");
}

void yellow(void)
{
	printf("\033[1;33m");
}

void	reset(void)
{
	printf("\033[0m");
}


short	check_map(t_game *game)
{
	size_t	i;

	i = 0;
	game->map_x = ft_strlen(game->map, '\n') + 1;
	while (game->map[i])
	{
		if (i == 0 || (i + 1) % game->map_x == 0)
		{
			printf("%c", game->map[i]);
		}

		/* if ((i % game->map_x) == 0) */
		/* { */
		/* 	red(); */
		/* 	printf("%c", game->map[i]); */
		/* } */
		/* else */
		/* { */
		/* 	yellow(); */
		/* 	printf("%c", game->map[i]); */
		/* } */
		reset();
		++i;
	}
	return (0);
}
