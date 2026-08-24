NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
OBJS_DIR	= objs
INC_DIR		= includes

vpath %.c srcs

SRCS = main.c main_flags.c stack_utils.c parsing.c parsing_utils.c ft_utils.c ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c sort_simple.c sort_medium.c sort_medium_utils.c sort_complex.c sort_complex_utils.c disorder.c sort_adaptive.c bench.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
