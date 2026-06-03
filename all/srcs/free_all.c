/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 09:43:14 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/05/30 09:45:11 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_all(t_all *shell)
{
    int	i;

    if (shell->tokens)
    {
        i = 0;
        while (shell->tokens[i])
        {
            free(shell->tokens[i]);
            i++;
        }
        free(shell->tokens);
        shell->tokens = NULL;
    }
}