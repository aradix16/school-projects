/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:49:12 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 14:06:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coordinate
{
	int				x;
	int				y;
}					t_coordinate;

typedef struct s_area
{
	t_coordinate	start;
	t_coordinate	stop;
}					t_area;

typedef struct s_window
{
	void			*ptr;
	t_coordinate	size;
}					t_window;

typedef struct s_mlx_img
{
	void			*image;
	int				*data;
	t_coordinate	size;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx_img;

typedef struct s_textures
{
	t_mlx_img		ground[N_GROUND];
	t_mlx_img		obstacle[N_OBSTACLE];
}					t_textures;

typedef struct s_mlx
{
	void			*ptr;
	t_textures		*textures;
	t_window		*window;
	t_mlx_img		*frame;
}					t_mlx;

typedef struct s_map
{
	char			**content;
	t_coordinate	size;
}					t_map;

typedef struct s_game
{
	t_coordinate	player;
	int				n_collectibles;
	bool			exit;
	t_map			*map;
	t_mlx			*mlx;
}					t_game;

#endif
