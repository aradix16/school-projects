/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:42:41 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 21:33:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_update(t_mlx *mlx)
{
	(void)mlx;
	/* char	*data; */
	/* int		bits_per_pixel; */
	/* int		size_line; */
	/* int		endian; */
	/* int		i; */
	/**/
	/* // image data */
	/* data = mlx_get_data_addr(mlx->i->ptr, &bits_per_pixel, &size_line,
			&endian); */
	/* i = 0; */
	/* while (i < mlx->w->y) */
	/* { */
	/* 	((int *)data)[i] = GREEN; */
	/* 	i++; */
	/* } */
	/* mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->i->ptr, 0, 0); */
	return (0);
}

int	on_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (stop_loop(game));
	return (0);
}
