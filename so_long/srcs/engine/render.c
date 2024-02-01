/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:57:09 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 15:22:43 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, mlx->frame->image, 0,
		0);
	return (0);
}

void	draw_line(t_mlx *mlx, size_t start, size_t end, t_texture *texture)
{
	int	i;

	i = 0;
	(void)texture;
	while (start < end)
	{
		((int *)mlx->frame->data)[start] = ((int *)texture->data)[i];
		i++;
		start++;
	}
}

void	draw_square(t_game *game, int pos, t_texture *texture)
{
	int	i;

	i = 0;
	while (i < TILE_SIZE)
	{
		draw_line(game->mlx, pos, pos + TILE_SIZE, texture);
		pos += game->mlx->window->width;
		i++;
	}
}

void	draw_frame(t_game *game, t_frame *frame)
{
	size_t	i;
	size_t	col;
	size_t	row;
	size_t	pos;

	i = 0;
	col = 0;
	row = 0;
	while (game->map->ptr[i])
	{
		if (game->map->ptr[i] == '\n')
		{
			row++;
			col = 0;
			i++;
			continue ;
		}
		pos = (row * ((game->map->cols * TILE_SIZE) * TILE_SIZE)) + (col * TILE_SIZE);
		if (game->map->ptr[i] == EMPTY)
			draw_square(game, pos, &game->mlx->texture[0]);
		if (game->map->ptr[i] == WALL)
			draw_square(game, pos, &game->mlx->texture[1]);
		col++;
		i++;
	}
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
	draw_frame(game, frame);
	return (true);
}
