/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:57:09 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 14:29:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game, t_frame *frame)
{
	(void)game;
	(void)frame;
}

bool	new_frame(t_game *game, t_mlx *mlx, t_frame *frame, t_window *window)
{
	mlx->frame = frame;
	frame->image = mlx_new_image(mlx->ptr, window->width, window->height);
	if (!frame->image)
		return (false);
	frame->data = mlx_get_data_addr(frame->image, &frame->bits_per_pixel,
			&frame->size_line, &frame->endian);
	if (!frame->data)
	{
		mlx_destroy_image(mlx->ptr, frame->image);
		return (false);
	}
	render(game, frame);
	return (true);
}