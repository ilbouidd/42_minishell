SRCS =  pipex.c \
		main.c	\
		utils.c \
		path.c  \


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

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
	@echo "pipex 💀"

re: fclean all

.PHONY: all clean fclean re