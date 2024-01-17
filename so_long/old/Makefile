NAME			:=		so_long

CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror

MLX_FLAGS		:=		-Lmlx -lmlx -L/usr/lib/x11	-lXext -lX11
MLX_INCLUDE		:=		-I/opt/X11/include -Imlx

LIBFT_PATH		:=		libft
LIBFT_INCLUDE	:=		$(LIBFT_PATH)/include
LIBFT			:=		$(LIBFT_PATH)/libft.a

INCLUDE			:=		include
SRCS			:=		srcs/so_long.c	\
						srcs/parsing/parsing.c	\
						srcs/parsing/check_map.c \

OBJS_DIR		:=		objs
OBJS			:=       $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)

$(OBJS_DIR)/%.o: %.c $(LIBFT)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_INCLUDE) -I$(MLX_INCLUDE) -o $@ -c $< 

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
