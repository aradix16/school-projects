NAME			:=	libft.a

CC				:=	cc
CLAGS			:=	-Wall -Wextra -Werror

INCLUDE			:=	include

SRCS			:=	ft_memncpy.c	\
					ft_strlen.c		\
					ft_strncmp.c 	\
					ft_read_file.c	\
					ft_free.c		\
					ft_strchr.c		\
					ft_strdup.c		\
					ft_strlcpy.c	\
					ft_memdup.c		\
					ft_calloc.c		\
					ft_memset.c		\

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
