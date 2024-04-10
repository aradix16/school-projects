NAME			:=		so_long

CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror

LIBFT_PATH		:=		libft
LIBFT_INCLUDE	:=		$(LIBFT_PATH)/include
LIBFT			:=		$(LIBFT_PATH)/libft.a

MLX_PATH		:= 		minilibx-linux
MLX_FLAGS		:=		-lbsd -lXext -lX11
MLX_INCLUDE		:=		$(MLX_PATH)
MLX				:=		$(MLX_PATH)/libmlx.a
MLX_URL			:=		git@github.com:42Paris/minilibx-linux.git 

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
						srcs/game_engine/core/events.c							\
						srcs/game_engine/init/display_connection.c				\
						srcs/game_engine/init/window.c							\
						srcs/game_engine/init/textures.c						\
						srcs/game_engine/init/frame_buffer.c					\
						srcs/game_engine/cleanup/clean_mlx.c					\
						srcs/game_engine/cleanup/clean_textures.c				\
						srcs/game_engine/movement/player_movement.c				\
						srcs/game_engine/utils/time.c							\


OBJS_DIR		:=		objs
OBJS			:=		$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(MLX_FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_INCLUDE) -I$(MLX_INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone $(MLX_URL) $(MLX_PATH); \
	fi
	make -C $(MLX_PATH)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)

re: fclean all
