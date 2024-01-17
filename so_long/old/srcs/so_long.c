/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:18:19 by aradix            #+#    #+#             */
/*   Updated: 2024/01/17 19:51:24 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(short err)
{
	printf("Error\n");
	if (err == 1)
		printf("(%d): Invalid number of arguments\n", err);
	else if (err == 2)
		printf("(%d): Invalid map extension\n", err);
	else if (err == 3)
		printf("(%d): Can't read the map\n", err);
	else
		printf("Unknownd err");
	return (err);
}

int	main(int ac, char **av)
{
	t_game	game;
	short	err;

	err = parsing(ac, av, &game);
	if (err)
		return (print_error(err));
	return (0);
}
