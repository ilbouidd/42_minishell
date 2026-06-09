/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:29:32 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/09 12:36:19 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parsing_all(t_all *shell)
{
    if (shell->line == NULL || shell->line[0] == '\0')
        return (1);
    if (shell->tokens)
        return (1);
    // if (init_nodes(shell))
    //     return (1);
    content_lexer(shell);
    return (0);
}
