NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c op_push.c op_swap.c op_rotate.c op_rrotate.c \
	sort.c quicksort.c utils.c split.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
