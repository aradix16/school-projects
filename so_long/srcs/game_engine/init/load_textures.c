/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:15 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 14:36:50 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define GROUND_PATH "assets/ground/ground_"
#define OBSTACLE_PATH "assets/obstacle/obstacle_"

bool	get_texture_data(t_mlx_img *texture)
{
	texture->data = (int *)mlx_get_data_addr(texture->image, &texture->bits_per_pixel,
			&texture->size_line, &texture->endian);
	return (texture->data);
}

bool	get_texture_image(t_mlx *mlx, t_mlx_img *texture, char *texture_path)
{
	texture->image = mlx_xpm_file_to_image(mlx->ptr, texture_path,
			&texture->size.x, &texture->size.y);
	return (texture->image);
}

bool	get_texture_image_data(t_mlx *mlx, t_mlx_img *texture, int n, char *dir)
{
	char	texture_path[50];
	int		dir_len;

	dir_len = ft_strlen(dir);
	ft_strlcpy(texture_path, dir, dir_len + 1);
	ft_strlcpy(texture_path + dir_len + 1, ".xpm", 5);
	while (--n >= 0)
	{
		texture_path[dir_len] = n + '0';
		if (!get_texture_image(mlx, texture, texture_path)
			|| !get_texture_data(texture))
			return (false);
	}
	return (true);
}

void	init_texture_image(t_mlx_img *texture, int n)
{
	while (--n >= 0)
		texture[n].image = NULL;
}

bool	load_textures(t_mlx *mlx, t_textures *textures)
{
	mlx->textures = textures;
	init_texture_image(textures->ground, N_GROUND);
	init_texture_image(textures->obstacle, N_OBSTACLE);
	if (!get_texture_image_data(mlx, textures->ground, N_GROUND, GROUND_PATH)
		|| !get_texture_image_data(mlx, textures->obstacle, N_OBSTACLE,
			OBSTACLE_PATH))
		return (false);
	return (true);
}
