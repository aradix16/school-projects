/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:37:22 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 15:44:18 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* RETURN STATUS */
# define SUCCESS 0
# define MALLOC_ERROR 1
# define INVALID_ARG_NUMBERS 2
# define INVALID_MAP_EXTENSION 3
# define CANNOT_READ_MAP_FILE 4
# define MAP_NOT_CLOSED 5
# define INVALID_LINE_SIZE 6
# define INVALID_MAP_CHARACTER 7
# define DUPLICATE_EXIT 8
# define DUPLICATE_PLAYER 9
# define NO_COLLECTIBLE_FOUND 10
# define NO_EXIT_FOUND 11
# define NO_PLAYER_FOUND 12
# define UNPLAYABLE_MAP 13
# define MLX_INIT_FAILED 14
# define LOAD_TEXTURES_FAILED 15
# define MLX_WINDOW_FAILED 16
# define MLX_IMAGE_FAILED 17

/* MAP ITEMS */
# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define NB_TEXTURES 5
# define TILE_SIZE 100

/* KEYS */
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

/* TEXTURES */
# define EMPTY_TEXTURE 0
# define WALL_TEXTURE 1
# define EXIT_TEXTURE 2

/* TO REMOVE */
# define GREEN 65280;

#endif
