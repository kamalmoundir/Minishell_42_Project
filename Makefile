CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIE

NAME = minishell

LIBFT = libraries/libft/libft.a
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE = -I./include/

SRCS = main.c utils.c error_handler.c tokenization.c handle_signals.c \
		builtins/ft_echo.c builtins/ft_pwd.c builtins/ft_env.c builtins/ft_exit.c \
		builtins/ft_cd.c  printbanner.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME) $(INCLUDE) $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@make -C libraries/libft/

clean:
	$(RM) $(OBJ_DIR)
	@make clean -C libraries/libft/

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libraries/libft/

re: fclean all

.PHONY: all clean fclean re