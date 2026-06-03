#include "../../minishell.h"

int	parsing_all(t_all *shell)
{
	if (shell->ac == 0)
        return (1);
    if (shell->line == NULL || shell->line[0] == '\0')
        return (1);
    return (0);
}
