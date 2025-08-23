
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PATH = ./libft
LIBFT  = $(LIBFT_PATH)/libft.a


SRCS =  pipex.c\
		pipex_checks.c\
		pipex_path.c\
		pipex_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re