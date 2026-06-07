/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:02:09 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 11:13:37 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_shell(t_all *shell)
{
    if (ft_strcmp(shell->tokens[0], "exit") == 0)
    {
        free_all(shell);
        exit(0);
    }
}