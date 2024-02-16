/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:49:12 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 17:19:56 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_frame
{
	void			*image;
	char			*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_frame;

typedef struct s_window
{
	void			*ptr;
	int				width;
	int				height;
}					t_window;

typedef struct s_texture
{
	void			*image;
	char			*data;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_texture;

typedef struct s_mlx
{
	void			*ptr;
	t_texture		*texture;
	t_window		*window;
	t_frame			*frame;
}					t_mlx;

typedef struct s_pos
{
	int				x;
	int				y;

}					t_pos;

typedef struct s_state
{
	t_pos			player;
	bool			exit;
	unsigned int	collectibles_count;

}					t_state;

typedef struct s_map
{
	char			**content;
	size_t			width;
	size_t			height;
}					t_map;

typedef struct s_game
{
	t_map			*map;
	t_state			*state;
	t_mlx			*mlx;
	unsigned int 	*seed;
}					t_game;

#endif
