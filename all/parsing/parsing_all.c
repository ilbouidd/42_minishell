#include "../../minishell.h"

int	parsing_all(t_all *shell)
{
    if (shell->line == NULL || shell->line[0] == '\0')
        return (1);
    fill_lexer(shell);
    return (0);
}
