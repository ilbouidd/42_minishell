/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:31:01 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 10:42:25 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_export(t_all *shell)
{
    if (!shell || !shell->tokens || !shell->tokens[0])
        return (1);
    if (ft_strcmp(shell->tokens[0], "export") != 0)
        return (1);
        
    return (0);
}