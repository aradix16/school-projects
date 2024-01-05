NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	main.c \
					srcs/ft_printf.c				\
					srcs/buffer/buffer.c			\
					srcs/parsing/parsing.c			\
					srcs/handlers/number_handler.c	\
					srcs/handlers/string_handler.c	\

OBJS			=	$(SRCS:.c=.o)
OBJS_FOLDER		=	objs

HEADERS_FOLDER	= 	headers

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I $(HEADERS_FOLDER) $(SRCS)
	@./a.out
	@rm -rf a.out
