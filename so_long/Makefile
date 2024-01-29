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

INCLUDE			:=		include

SRCS			:=		srcs/so_long.c							\
						srcs/error.c							\
						srcs/parsing/parsing.c					\
						srcs/parsing/map/extension_checker.c	\
						srcs/parsing/map/validity_checker.c		\
						srcs/parsing/map/playability_checker.c	\
						srcs/engine/start.c						\
						srcs/engine/window.c					\
						srcs/engine/graphics.c					\

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
