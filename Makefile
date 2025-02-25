CC = cc

CFLAGS = -Werror -Wextra -Wall

RM = rm -rf

NAME = push_swap

BNAME = checker

LIBFT = libft/libft.a

FILES = push_swap_mandatory/push.c push_swap_mandatory/re_rotate.c push_swap_mandatory/rotate.c push_swap_mandatory/swap.c \
 		push_swap_mandatory/errors_checks.c push_swap_mandatory/fill_stack_a.c push_swap_mandatory/general_utils.c push_swap_mandatory/stack_utils.c \
		push_swap_mandatory/set_b_nodes.c  push_swap_mandatory/sort_utils.c push_swap_mandatory/get_middle_element.c \
		push_swap_mandatory/sort_big_stack.c push_swap_mandatory/sort_short.c push_swap_mandatory/sort.c \

BFILES = push_swap_bonus/push_bonus.c push_swap_bonus/re_rotate_bonus.c push_swap_bonus/rotate_bonus.c push_swap_bonus/swap_bonus.c \
		push_swap_bonus/errors_checks_bonus.c push_swap_bonus/fill_stack_a_bonus.c push_swap_bonus/general_utils_bonus.c push_swap_bonus/stack_utils_bonus.c \
		push_swap_bonus/execute_operation_bonus.c push_swap_bonus/get_next_line/get_next_line.c push_swap_bonus/get_next_line/get_next_line_utils.c \
		push_swap_bonus/read_operations_bonus.c

SRC = push_swap_mandatory/push_swap.c

OBJ = $(FILES:.c=.o) $(SRC:.c=.o)

BSRC = push_swap_bonus/push_swap_bonus.c

BOBJ = $(BFILES:.c=.o) $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(FILES) $(LIBFT) -o $(NAME)

bonus: $(BNAME)

$(BNAME) : $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BSRC) $(BFILES) $(LIBFT) -o $(BNAME)

$(LIBFT) :
	make -C libft

clean:
	$(RM) $(OBJ)
	$(RM) $(BOBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) checker
	make fclean -C libft

re: fclean all

.SECONDARY: $(OBJ) $(BOBJ)
