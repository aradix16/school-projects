NAME			:=	libft.a

CC				:=	cc
CLAGS			:=	-Wall -Wextra -Werror

INCLUDE			:=	include

STRING			:=	string/ft_strlen.c		\
					string/ft_strncmp.c		\
					string/ft_strchr.c		\
					string/ft_memset.c		\
					string/ft_strnew.c		\
					string/ft_mtrxfree.c	\

STDIO			:=	stdio/ft_puts.c			\

LIST			:=	list/ft_lstnew.c		\
					list/ft_lstadd_back.c	\
					list/ft_lstlast.c		\
					list/ft_lstfree.c		\

STDLIB			:=	stdlib/ft_rand.c		\

SRCS			:= $(STRING) $(STDIO) $(LIST) $(STDLIB)

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
