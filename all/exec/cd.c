/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:02:19 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 11:22:50 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_cd(t_all *shell)
{
    if (!shell || !shell->tokens || !shell->tokens[0])
        return (1);
    if (ft_strcmp(shell->tokens[0], "cd") != 0)
        return (1);
    return (0);
}
