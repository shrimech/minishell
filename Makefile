CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ./parsing/env/env_cpy.c ./parsing/env/env_utils.c ./parsing/env/gestion_env.c ./minishell.c ./execution/builtins/env.c
OBJS = $(FUNCTIONS:.c=.o)
NAME = minishell
LIBFT = libft/libft.a
all: $(NAME)
%.o: %.c
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $< -o $@ 


clean:
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)

re: fclean all