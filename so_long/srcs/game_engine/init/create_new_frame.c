/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:00:30 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 14:37:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	create_new_frame(t_mlx *mlx, t_mlx_img *frame, t_window *window)
{
	mlx->frame = frame;
	frame->image = mlx_new_image(mlx->ptr, window->size.x, window->size.y);
	if (!frame->image)
		return (false);
	frame->data = (int *)mlx_get_data_addr(frame->image, &frame->bits_per_pixel,
			&frame->size_line, &frame->endian);
	if (!frame->data)
	{
		mlx_destroy_image(mlx->ptr, frame->image);
		return (false);
	}
	return (true);
}
