/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:42 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 15:24:10 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	parsing(t_game *game, int ac, char **av)
{
	short	err;

	if (ac != 2)
		return (INVALID_ARG_NUMBER);
	if (!check_map_extension(av[1]))
		return (INVALID_MAP_EXTENSION);
	err = read_and_store_map(game->map, open(av[1], O_RDONLY));
	if (err)
		return (err);
	err = check_map_validity(game, game->map);
	if (err)
		return (ft_mtrxfree(game->map->content), err);
	err = check_map_playability(game, game->map);
	if (err)
		return (ft_mtrxfree(game->map->content), err);
	return (SUCCESS);
}
