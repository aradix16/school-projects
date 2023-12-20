NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	srcs/ft_printf.c

OBJS			=	$(SRCS:.c=.o)
OBJS_FOLDER		=	objs

HEADERS_FOLDER	= 	headers

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I $(HEADERS_FOLDER) $(SRCS)
	@./a.out
	@rm -rf a.out
