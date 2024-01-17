/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:44 by aradix            #+#    #+#             */
/*   Updated: 2024/01/18 20:55:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_file_extension_valid(char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath, '\0');
	return (len > 4 && ft_strncmp(filepath + (len - 4), ".ber", 4) == 0);
}

short	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!is_file_extension_valid(av[1]))
		return (2);
	return (parse_map(game, ft_read_file(av[1])));
}
