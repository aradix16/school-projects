/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:44 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 16:24:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!is_file_extension_valid(av[1]))
		return (2);
	game->map = ft_read_file(av[1]);
	if (!game->map)
		return (3);
	if (!is_map_valid(game))
		return (4);
	/* if (!is_map_playable(game)) */
	/* 	return (5); */
	printf("%zu\n", game->c_counter);
	return (0);
}
