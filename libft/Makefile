# Define the target file
NAME			=	libft.a

# Define the compiler and flags
CC				=	cc
CLAGS			=	-Wall -Wextra -Werror

# Define the source files from the mandatory part
SRCS			=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	\
					ft_isascii.c	ft_isprint.c	ft_strlen.c		\
					ft_memset.c		ft_bzero.c		ft_memcpy.c		\
					ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
					ft_toupper.c	ft_tolower.c	ft_strchr.c		\
					ft_strrchr.c	ft_strncmp.c	ft_memchr.c		\
					ft_memcmp.c		ft_strnstr.c	ft_atoi.c		\
					ft_calloc.c		ft_strdup.c		ft_substr.c		\
					ft_strjoin.c	ft_strtrim.c	ft_split.c		\
					ft_itoa.c		ft_strmapi.c	ft_striteri.c	\
					ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
					ft_putnbr_fd.c	\

# Define the source files from the bonus part
SRCS_BONUS		=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c		\
					ft_lstlast.c	ft_lstadd_back.c	ft_lstadd_back.c	\
					ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c		\
					ft_lstmap.c		\

# Define the object files
OBJS			=	$(SRCS:.c=.o)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

# The default target
all: $(NAME)

# Compile the object files
%.o: %.c
	$(CC) $(CLAGS) -o $@ -c $<

# Create the target
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "Library libft.a successfully created"

# Create the target with bonus
bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	echo "Library libft.a with bonus successfully created"

# Clean up the object files
clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	echo "Object files successfully cleaned"

# Clean up the target file
fclean: clean
	rm -f $(NAME)
	echo "Target file successfully cleaned"

# Clean up and rebuild the target
re: fclean all

.PHONY: all bonus clean fclean re
