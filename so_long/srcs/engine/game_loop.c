/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:22:55 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 13:30:51 by aradix           ###   ########.fr       */
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

int	on_update(int n)
{
	(void)n;
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx, t_window *window)
{
	t_image	image;

	(void)game;
	(void)window;


	// check return value
	image.ptr = mlx_new_image(mlx->ptr, window->y, window->x);

	/* char *data; */
	/* int bits_per_pixel; */
	/* int size_line; */
	/* int endian; */

	/* data = mlx_get_data_addr(image.ptr, &bits_per_pixel, &size_line, &endian); */
	/* if (!data) */
		/* return ; */
	/* printf(">%d<\n", bits_per_pixel); */
	/* printf("%d\n", size_line); */

	mlx_put_image_to_window(mlx->ptr, mlx->window, image.ptr, 0, 0);
	mlx_hook(mlx->window, 2, (1L << 0), on_key_press, NULL);
	mlx_hook(mlx->window, 3, (1L << 1), on_key_release, NULL);
	mlx_hook(mlx->window, 17, (1L << 17), close_window, NULL);
	mlx_loop_hook(mlx->ptr, on_update, NULL);
	mlx_loop(mlx->ptr);
}
