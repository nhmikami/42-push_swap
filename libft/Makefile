NAME		=	libft.a
LIB			=	ar rcs
RM			=	rm -f
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_atoi.c \
			ft_memmove.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			get_next_line.c

OBJS		=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

all:		$(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re