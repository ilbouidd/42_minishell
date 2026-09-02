/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:29:32 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/01 08:27:24 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int parsing_all(t_all *shell)
{
    if (shell->line == NULL || shell->line[0] == '\0')
        return (-1);
    if (parse_quote(shell) == -1)
        return (-1);
    if (parse_pipe(shell) == -1)
        return (-1);
    if (parse_redir(shell) == -1)
        return (-1);
    return (0);
}
