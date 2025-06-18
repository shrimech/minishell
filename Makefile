CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = ./parsing/env/env_cpy.c ./parsing/env/env_utils.c \
	./parsing/env/gestion_env.c ./minishell.c \
	./execution/builtins/env.c ./signals.c ./execution/builtins/exit.c \
	./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c
OBJS = $(FUNCTIONS:.c=.o)
NAME = minishell
LIBFT = libft/libft.a -lreadline
all: $(NAME)
%.o: %.c
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $< -o $@ 


clean:
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)

re: fclean all