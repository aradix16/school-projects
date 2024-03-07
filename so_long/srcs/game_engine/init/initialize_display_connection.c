/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_display_connection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:32:54 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 22:43:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	initialize_display_connection(t_graphics *graphics)
{
	graphics->mlx_ptr = mlx_init();
	return (graphics->mlx_ptr);
}
