CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIE
NAME = minishell

LIBFT = libraries/libft/libft.a

SRCS = main.c utils.c error_handler.c parser.c handle_signals.c \
		builtins/echo.c builtins/pwd.c 

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), $(SRCS))
INCLUDE = -I./include/
OBJS = $(SRC:.c=.o) 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME) $(INCLUDE) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(LIBFT):
	@make -C libraries/libft/

clean:
	$(RM) $(OBJS)
	@make clean -C libraries/libft/

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libraries/libft/

re: fclean all

.PHONY: all clean fclean re