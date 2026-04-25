NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

LIB = ./libft
LIBA = $(LIB)/libft.a

SRC_DIR = all/srcs/
PARSE_DIR = all/parsing/
EXEC_DIR = all/exec/

SRCS =	$(SRC_DIR)minishell.c \
		$(PARSE_DIR)parsing_all.c \
		$(SRC_DIR)readline.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBA)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBA) $(LDFLAGS) -o $(NAME)
	@echo "TOUT EST GOOD 🤓👍🔥"

$(LIBA):
	@$(MAKE) -C $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB) clean
	@rm -f $(OBJS)
	@echo "TOUS LES FICHIERS .o 💀"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB) fclean
	@echo "Makefile 💀"

re: fclean all

.PHONY: all clean fclean re