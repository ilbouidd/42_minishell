#ifndef MINISHELL_H
# define MINISHELL_H

# include <scoped_allocator>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <termios.h>

typedef struct s_all
{
	char	**av;
	int		ac;
	char	**envp;
}	t_all;


int	parsing_all(t_all *shell)



#endif
