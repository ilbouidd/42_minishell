/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:01:06 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/08 14:05:17 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int exec_shell(t_all *shell)
{
    if (ft_strcmp(shell->tokens[0], "echo") == 0)
        return (printf("debut echo"),ft_echo(shell)); 
    // else if (ft_strcmp(shell->tokens[0], "cd") == 0)
    //     return (ft_cd(shell));
    // else if (ft_strcmp(shell->tokens[0], "env") == 0)
    //     return (ft_env(shell));
    // else if (ft_strcmp(shell->tokens[0], "export") == 0)
    //     return (ft_export(shell));
    // else if (ft_strcmp(shell->tokens[0], "unset") == 0)
    //     return (ft_unset(shell));
    // else if (ft_strcmp(shell->tokens[0], "pwd") == 0)
    //     return (ft_pwd(shell));
    else
        printf("Command not found: %s\n", shell->tokens[0]);
    return (1);
}