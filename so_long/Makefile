NAME				:=		so_long

CC					:=		cc
CFLAGS			:=		-Wall -Wextra -Werror

LIBFT_PATH		:=		libft
LIBFT_INCLUDE	:=		$(LIBFT_PATH)/include
LIBFT			:=		$(LIBFT_PATH)/libft.a

MLX_PATH		:= 		minilibx-linux
MLX_FLAGS		:=		-lbsd -lXext -lX11
MLX_INCLUDE		:=		$(MLX_PATH)
MLX				:=		$(MLX_PATH)/libmlx.a

INCLUDE			:=		include

SRCS			:=		srcs/so_long.c											\
						srcs/error/print_error.c 								\
						srcs/parsing/parsing.c 									\
						srcs/parsing/check_map_extension.c						\
						srcs/parsing/read_and_store_map.c						\
						srcs/parsing/check_map_validity.c						\
						srcs/parsing/check_map_playability.c					\
						srcs/game_engine/core/start_game_engine.c				\
						srcs/game_engine/core/game_loop.c						\
						srcs/game_engine/init/initialize_display_connection.c 	\
						srcs/game_engine/init/load_textures.c					\
						srcs/game_engine/init/create_new_window.c				\
						srcs/game_engine/init/create_new_frame_buffer.c			\
						srcs/game_engine/cleanup/clean_mlx.c					\
						srcs/game_engine/cleanup/clean_textures.c				\
						srcs/game_engine/graphics/render.c						\
						srcs/game_engine/events/key_event.c						\
						srcs/game_engine/events/loop_event.c					\
						srcs/game_engine/graphics/utils/get_boundaries.c		\
						srcs/game_engine/graphics/draw_map.c					\
						srcs/game_engine/graphics/draw_player.c					\
						srcs/game_engine/graphics/utils/draw_texture_tile.c		\
						srcs/game_engine/graphics/utils/time.c					\
						# srcs/game_engine/graphics/render.c					\

OBJS_DIR		:=		objs
OBJS			:=		$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(MLX_FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_INCLUDE) -I$(MLX_INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

