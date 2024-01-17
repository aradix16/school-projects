/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:24:58 by aradix            #+#    #+#             */
/*   Updated: 2024/01/17 20:19:58 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_game
{
	char			*map;
	unsigned int	map_x;
}					t_game;

short				parsing(int ac, char **av, t_game *game);
short				check_map(t_game *game);

#endif
