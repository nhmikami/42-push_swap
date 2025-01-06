NAME			=	push_swap
BONUS_NAME		=	checker
RM				=	rm -f
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

SRC_PATH		=	./src
BONUS_PATH		=	./src_bonus
INC_PATH		=	./include
LIB_PATH		=	./libft

SRC				=	push_swap.c \
					get_args.c \
					init_stack.c \
					commands.c \
					operations.c \
					cost.c \
					push_to_a.c \
					push_to_b.c \
					sort_utils.c

BONUS_SRC		=	checker.c \
					get_args_bonus.c \
					init_stack_bonus.c \
					operations_bonus.c \
					checker_utils.c

OBJ				=	$(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
BONUS_OBJ		=	$(addprefix $(BONUS_PATH)/, $(BONUS_SRC:.c=.o))

INC				=	-I$(INC_PATH)

LIBFT			=	$(LIB_PATH)/libft.a

all:				$(NAME)

$(LIBFT):
					make -C $(LIB_PATH) -s

$(NAME):			$(LIBFT) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -L$(LIB_PATH) -lft -o $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus:				$(BONUS_NAME)

$(BONUS_NAME):		$(LIBFT) $(BONUS_OBJ)
						$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIB_PATH) -lft -o $(BONUS_NAME)

$(BONUS_PATH)%.o: $(BONUS_PATH)%.c $(INC_PATH)/checker.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
					$(RM) $(OBJ) $(BONUS_OBJ)
					make clean -C $(LIB_PATH) -s

fclean:				clean
					$(RM) $(NAME) $(BONUS_NAME)
					make fclean -C $(LIB_PATH) -s

re:					fclean all

.PHONY:		all bonus clean fclean re