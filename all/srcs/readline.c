/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:22:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 06:57:37 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    readline_shell(t_all *shell)
{

    while (1)
    {
        shell->line = readline("Ilyshell: ");
        if (!shell->line)
            break;
        if (*shell->line)
            add_history(shell->line); 
        split_line(shell);
        close_shell(shell);
        exec_shell(shell);
        free (shell->line);
    }
    rl_clear_history();
}