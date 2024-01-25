/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:44 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 19:11:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


short	parsing(t_game *game, int ac, char **av)
{
	short	err;

	if (ac != 2)
		return (INVALID_ARG_NUMBERS);
	if (!check_file_extension(av[1]))
		return (INVALID_FILE_EXTENSION);
	err = check_map_validity(&game->m, ft_read_file(av[1]));
	if (err)
		return (err);
	err = check_map_playability(&game->m);
	if (err)
		return (err);
	return (0);
}
