#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_all
{
	char	**av;
	int		ac;
	char	**envp;
}	t_all;


int	parsing_all(t_all *shell);
void    readline_shell(void);


#endif
