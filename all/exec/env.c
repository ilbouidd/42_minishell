/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:24:40 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 10:25:23 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_env(t_all *shell)
{
    int i;

    i = 0;
    if (!shell || !shell->tokens || !shell->tokens[0])
        return (1);
    if (ft_strcmp(shell->tokens[0], "env") != 0)
        return (1);
    while (shell->envp[i])
    {
        printf("%s\n", shell->envp[i]);
        i++;
    }
    return (0);
}