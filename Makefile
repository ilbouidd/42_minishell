SRCS =	$(SRC_DIR)minishell.c \
		$(SRC_DIR)parsing_all.c \
		


OBJS = $(SRCS:.c=.o)

CC = cc

SRC_DIR = src

CFLAGS = -Wall -Wextra -Werror

NAME = minishell

LIB = ./libft

LIBA = $(LIB)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBA)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBA) -o $(NAME)
	@echo "TOUT EST GOOD 🤓👍🔥"

$(LIBA):
	@$(MAKE) -C $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB) clean
	@rm -f $(OBJS)
	@echo "TOUT LES FICHIERS .o 💀"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB) fclean
	@echo "Makefile 💀"

re: fclean all

.PHONY: all clean fclean re
