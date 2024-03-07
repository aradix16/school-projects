/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_frame_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:00:30 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 20:20:07 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	create_new_frame_buffer(t_graphics *graphics, t_mlx_img *frame,
		t_coordinate window_size)
{
	graphics->frame = frame;
	frame->image = mlx_new_image(graphics->mlx_ptr, window_size.x,
			window_size.y);
	if (!frame->image)
		return (false);
	frame->data = (int *)mlx_get_data_addr(frame->image, &frame->bits_per_pixel,
			&frame->size_line, &frame->endian);
	if (!frame->data)
	{
		mlx_destroy_image(graphics->mlx_ptr, frame->image);
		return (false);
	}
	return (true);
}
