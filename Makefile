NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

LIB = ./libft
LIBA = $(LIB)/libft.a

SRC_DIR = all/srcs/
PARSE_DIR = all/parsing/
EXEC_DIR = all/exec/

SRCS = $(SRC_DIR)minishell.c \
       $(PARSE_DIR)parsing_all.c \
       $(SRC_DIR)readline.c \
       $(EXEC_DIR)exec.c \
       $(EXEC_DIR)echo.c \
       $(SRC_DIR)split/ft_split_minishell.c \
       $(SRC_DIR)split/ft_split_utils.c	\
       $(SRC_DIR)free_all.c		\
	   $(SRC_DIR)close_shell.c		\
	   $(EXEC_DIR)cd.c			\
	   $(EXEC_DIR)env.c			\
	   $(EXEC_DIR)export.c		\
	   $(EXEC_DIR)unset.c		\
	   $(EXEC_DIR)pwd.c			\
	   $(PARSE_DIR)lexer.c		\
	   $(PARSE_DIR)lexer_parsing.c		\
	   $(PARSE_DIR)parsing_utils.c		\
	   $(PARSE_DIR)handle_quote.c		\
	   $(EXEC_DIR)path.c				\
	   $(EXEC_DIR)build_cmd.c			\
	   $(EXEC_DIR)exec_pipe.c			\
	   $(EXEC_DIR)export_utils.c		\
	   $(EXEC_DIR)export_second.c		\
	   $(PARSE_DIR)expands.c			\
	   $(SRC_DIR)signals.c				\
	   $(SRC_DIR)heredoc.c				\

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