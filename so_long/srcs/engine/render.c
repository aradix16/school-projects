
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:57:09 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 17:44:44 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, mlx->frame->image, 0,
		0);
	return (0);
}

void	draw_tile(t_game *game, size_t x, size_t y, t_texture *texture)
{
	size_t	i;
	size_t	j;
	size_t	pos;
	int		pxl_color;

	i = 0;
	pos = ((x * TILE_SIZE) * game->map->width + y) * TILE_SIZE;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			pxl_color = ((int *)texture->data)[(i * TILE_SIZE) + j];
			if (pxl_color != 0)
				((int *)game->mlx->frame->data)[pos] = pxl_color;
			j++;
			pos++;
		}
		pos += game->mlx->window->width - TILE_SIZE;
		i++;
	}
}

void	draw_tile_player(t_game *game, float x, float y, t_texture *texture)
{
	size_t	i;
	size_t	j;
	int		pos;
	int		pxl_color;

	i = 0;
	pos = ((x * TILE_SIZE) * game->map->width + y) * TILE_SIZE;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			pxl_color = ((int *)texture->data)[(i * TILE_SIZE) + j];
			if (pxl_color != 0)
				((int *)game->mlx->frame->data)[pos] = pxl_color;
			j++;
			pos++;
		}
		pos += game->mlx->window->width - TILE_SIZE;
		i++;
	}
}

void	draw_frame(t_game *game, t_frame *frame)
{
	size_t			x;
	size_t			y;
	int				texture_index;
	unsigned int	seed;

	seed = 0;
	x = 0;
	while (game->map->content[x])
	{
		y = 0;
		while (game->map->content[x][y])
		{
			texture_index = ft_rand(&seed) % 6;
			draw_tile(game, x, y, &game->mlx->texture[0]);
			if (game->map->content[x][y] == WALL)
			{
				if (x == 0 || x == (game->map->height - 1))
					texture_index = (ft_rand(&seed) % 3) + 6;
				else
					texture_index = (ft_rand(&seed) % 2) + 6;
				draw_tile(game, x, y, &game->mlx->texture[texture_index]);
			}
			else if (game->map->content[x][y] == COLLECTIBLE)
			{
				texture_index = (ft_rand(&seed) % 3) + 9;
				draw_tile(game, x, y, &game->mlx->texture[texture_index]);
			}
			y++;
		}
		x++;
	}
	(void)frame;

	// render player
	float xx = game->state->player.x;
	float yy = game->state->player.y;

	/* printf("%c\n", game->map->content[xx][yy]); */
	draw_tile_player(game, xx, yy, &game->mlx->texture[PLAYER0_ID]);
	
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
