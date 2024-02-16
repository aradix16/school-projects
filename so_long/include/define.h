/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:43:08 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 17:15:39 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SUCCESS 0
# define MALLOC_ERROR 1
# define INVALID_ARG_NUMBER 2
# define INVALID_MAP_EXTENSION 3
# define CANNOT_OPEN_MAP 4
# define READ_ERROR 5
# define INVALID_MAP_CONTENT 6
# define DUPLICATE_PLAYER 7
# define DUPLICATE_EXIT 8
# define CANNOT_READ_MAP 5
# define UNPLAYABLE_MAP 9
# define MLX_INIT_FAILED 10
# define LOAD_TEXTURES_FAILED 11
# define MLX_WINDOW_FAILED 12
# define MLX_IMAGE_FAILED 13

/* # define MAP_NOT_RECTANGLE 9 */
/* # define INVALID_MAP_SIZE 6 */

/* # define RAND_MAX_CUSTOM 32767 // Maximum value of the PRNG */
/* # define RAND_SEED 1234 */

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define TILE_SIZE 50
# define NB_TEXTURES 15
# define EMPTY_ID 0
# define WALL_ID 1
# define EXIT_ID 2
# define PLAYER_ID 3
# define COLLECTIBLE_ID 4

/* TEXTURE */
# define GRASS0_ID 0
# define GRASS0 "assets/grass/grass0.xpm"
# define GRASS1_ID 1
# define GRASS1 "assets/grass/grass1.xpm"
# define GRASS2_ID 2
# define GRASS2 "assets/grass/grass2.xpm"
# define GRASS3_ID 3
# define GRASS3 "assets/grass/grass3.xpm"
# define GRASS4_ID 4
# define GRASS4 "assets/grass/grass4.xpm"
# define GRASS5_ID 5
# define GRASS5 "assets/grass/grass5.xpm"

# define OBSTACLE0_ID 6
# define OBSTACLE0 "assets/obstacle/obstacle0.xpm"
# define OBSTACLE1_ID 7
# define OBSTACLE1 "assets/obstacle/obstacle1.xpm"
# define OBSTACLE2_ID 8
# define OBSTACLE2 "assets/obstacle/obstacle2.xpm"

# define FLOWER0_ID 9
# define FLOWER0 "assets/flower/flower0.xpm"
# define FLOWER1_ID 10
# define FLOWER1 "assets/flower/flower1.xpm"
# define FLOWER2_ID 11
# define FLOWER2 "assets/flower/flower2.xpm"

# define PLAYER0_ID 12
# define PLAYER0 "assets/fox/fox0.xpm"
# define PLAYER1_ID 13
# define PLAYER1 "assets/fox/fox1.xpm"
# define PLAYER2_ID 14
# define PLAYER3 "assets/fox/fox2.xpm"

/* # define MUSH_ID 12 */
/* # define MUSH "assets/mush/mush.xpm" */


/* KEYS */
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

#endif
