/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:21:47 by aradix            #+#    #+#             */
/*   Updated: 2024/01/17 23:38:14 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	get_map(t_game *game, char *filename)
{
	/* return (game->map = ft_read_file(filename)); */

}

bool	is_file_extension_valid(char *filename)
{
	size_t	len;

	len = ft_strlen(filename, '\0');
	return (len > 4 && ft_strncmp(filename + (len - 4), ".ber", 4) == 0);
}

short	parsing(int ac, char **av, t_game *game)
{
	if (ac != 2)
		return (1);
	if (!is_file_extension_valid(av[1]))
		return (2);
	if (!get_map(game, av[1]))
		return (3);
	return (check_map(game));
}

