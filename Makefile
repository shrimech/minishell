NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lreadline ./libft/libft.a

SRCS = ./src/main.c \
	./src/parsing/cmd_param.c ./src/parsing/quote.c ./src/parsing/dollar_env.c ./src/parsing/dollar_replace.c \
	./src/parsing/create_token.c ./src/parsing/create_cmd.c ./src/parsing/cmd_fd.c \
	./src/utils/debug.c ./src/utils/signals2.c ./src/utils/list_utils.c ./src/utils/signals.c ./src/utils/list_cmd.c \
	./src/utils/list_token.c ./src/utils/ms_utils.c ./src/utils/free.c ./src/utils/array_utils.c \
	./src/builtin/ft_unset.c ./src/builtin/ft_pwd.c ./src/builtin/ft_env.c ./src/builtin/ft_export.c \
	./src/builtin/ft_cd.c ./src/builtin/ft_echo.c ./src/builtin/ft_exit.c \
	./src/exec/here_doc.c ./src/exec/exec.c ./src/exec/launch_builtin.c ./src/exec/find_cmd.c ./src/exec/exec2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re






# minishell> | << P
# > PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPpp
# > P
