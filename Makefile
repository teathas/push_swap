CC = cc

CFLAGS = -Werror -Wextra -Wall -g

RM = rm -rf

NAME = push_swap

LIBFT = libft/libft.a

FILES = op/push.c op/re_rotate.c op/rotate.c op/swap.c \
          errors_checks.c fill_stack_a.c general_utils.c stack_utils.c sort_for_three.c sort.c \
		  set_b_nodes.c sort_big_stack.c sort_utils.c get_middle_element.c

SRC = push_swap.c

OBJ = $(FILES:.c=.o) $(SRC:.c=.o)

BSRC = checker/checker.c checker/execute_operation.c checker/get_next_line.c checker/get_next_line_utils.c

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(FILES) $(LIBFT) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BSRC) $(FILES) $(LIBFT) -o checker_bin

$(LIBFT) :
	make -C libft


clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) checker_bin
	make fclean -C libft

re: fclean all

.SECONDARY: $(OBJ)