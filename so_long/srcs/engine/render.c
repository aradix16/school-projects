/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:57:09 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 19:28:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, mlx->frame->image, 0,
		0);
	return (0);
}

void	draw_frame(t_game *game, t_frame *frame)
{
	size_t	i;
	int		j;
	int		x;

	i = 0;
	while (game->map->ptr[i])
	{
		if (game->map->ptr[i] == WALL)
		{
			j = 0;
			x = 0;
			int frame_width = game->mlx->window->width;
			while (j < (TILE_SIZE * TILE_SIZE))
			{
				frame->data[x] = game->mlx->texture[0].data[j];
				x++;
				if (x % TILE_SIZE == 0)
				{
					x += (frame_width - TILE_SIZE);
				}
				j++;
			}
			return ;
		}
		return ;
		i++;
	}
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
	draw_frame(game, frame);
	return (true);
}
