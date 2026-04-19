#include "../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_all *shell;

	shell->ac = ac;
	shell->av = av;
	shell->envp = envp;
}
