NAME		=	libftprintf.a

CC			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror

HEADERS		= 	headers

SRCS		=	srcs/ft_printf.c					\
				srcs/parsing/parsing.c				\
				srcs/buffer/buffer.c				\
				srcs/handlers/char_handler.c		\
				srcs/handlers/string_handler.c		\
				srcs/handlers/ptr_handler.c			\
				srcs/handlers/signed_handler.c		\
				srcs/handlers/unsigned_handler.c	\

OBJS_DIR	= 	objs
OBJS		=	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
 
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $<

clean: 
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
