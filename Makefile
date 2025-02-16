CC = cc

CFLAGS = -Werror -Wextra -Wall

RM = rm -rf

NAME = push_swap

LIBFT = libft/libft.a

FILES = operations/push.c operations/re_rotate.c operations/rotate.c operations/swap.c \
 		stack/errors_checks.c stack/fill_stack_a.c utils/general_utils.c utils/stack_utils.c \
		utils/set_b_nodes.c  utils/sort_utils.c utils/get_middle_element.c \
		sorting/sort_big_stack.c sorting/sort_short.c sorting/sort.c \

SRC = push_swap.c

OBJ = $(FILES:.c=.o) $(SRC:.c=.o)

BSRC = push_swap_bonus/push_swap_bonus.c push_swap_bonus/execute_operation_bonus.c push_swap_bonus/get_next_line.c \
		push_swap_bonus/get_next_line_utils.c

BOBJ = $(FILES:.c=.o) $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(FILES) $(LIBFT) -o $(NAME)

bonus: checker

checker : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BSRC) $(FILES) $(LIBFT) -o checker

$(LIBFT) :
	make -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) checker
	make fclean -C libft

re: fclean all

.SECONDARY: $(OBJ) $(BOBJ)
