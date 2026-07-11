/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:55:39 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/10 14:31:18 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int lst_size(t_all *shell)
{
    int i;

    i = 0;
    while (shell->stack->next != NULL)
    {
        i++;
        shell->stack = shell->stack->next;
    }
    return (i);
}

int is_redir(int type)
{
    return (type == REDIR_IN || type == REDIR_OUT
            || type == REDIR_APPEND || type == REDIR_HERE);
}