NAME			:=	libft.a

CC				:=	cc
CLAGS			:=	-Wall -Wextra -Werror

INCLUDE			:=	include

STRING			:=	string/ft_memncpy.c	\
					string/ft_strlen.c	\
					string/ft_strncmp.c \

READ_FILE		:=	read_file/ft_read_file.c	\

SRCS			:=	$(STRING) $(READ_FILE)

OBJS_DIR		:=	objs
OBJS			:=	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
