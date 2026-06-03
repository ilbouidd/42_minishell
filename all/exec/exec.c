/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:01:06 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/05/28 11:01:06 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int exec_shell(t_all *shell)
{
    if (ft_strcmp(shell->tokens[0], "echo") == 0)
        return (ft_echo(shell));
    else
        printf("Command not found: %s\n", shell->tokens[0]);
    return (1);
}