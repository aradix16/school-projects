/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:22:55 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 14:19:48 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
	void *param) */

int	on_key_press(int key)
{
	if (key == ESC)
		return (close_window());
	return (0);
}

int	on_key_release(int key)
{
	(void)key;
	return (0);
}

int	on_update(t_mlx *mlx)
{
	char *data;
	int bits_per_pixel;
	int size_line;
	int endian;

	// image data
	data = mlx_get_data_addr(mlx->i->ptr, &bits_per_pixel, &size_line, &endian);
	int i = 0;
	while (i < mlx->w->y)
	{
		((int *)data)[i] = GREEN;
		i++;
	}

	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->i->ptr, 0, 0);
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx, t_window *window)
{
	(void)game;
	t_image	image;


	mlx->w = window;
	mlx->i = &image;

	image.ptr = mlx_new_image(mlx->ptr, mlx->w->y, mlx->w->x);

	// check return value
	mlx_hook(mlx->window, 2, (1L << 0), on_key_press, NULL);
	mlx_hook(mlx->window, 3, (1L << 1), on_key_release, NULL);
	mlx_hook(mlx->window, 17, (1L << 17), close_window, NULL);
	mlx_loop_hook(mlx->ptr, on_update, mlx);
	mlx_loop(mlx->ptr);
}
