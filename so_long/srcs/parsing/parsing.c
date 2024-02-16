/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:58:32 by aradix            #+#    #+#             */
/*   Updated: 2024/02/10 21:25:13 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	parsing(t_game *game, int ac, char **av)
{
	short	err;

	if (ac != 2)
		return (INVALID_ARG_NUMBER);
	if (!check_extension(av[1]))
		return (INVALID_MAP_EXTENSION);
	err = read_and_store_map(game->map, open(av[1], O_RDONLY));
	if (err)
		return (err);
	err = check_map_validity(game->map, game->state);
	if (err)
		return (ft_mtrxfree(game->map->content), err);
	err = check_map_playability(game, game->map, game->state);
	if (err)
		return (ft_mtrxfree(game->map->content), err);
	return (SUCCESS);
}
