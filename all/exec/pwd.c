/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:40:41 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 10:48:31 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_pwd(t_all *shell)
{
    if (!shell || !shell->tokens || !shell->tokens[0])
        return (1);
    if (ft_strcmp(shell->tokens[0], "pwd") != 0)
        return (1);
    return (0);
}