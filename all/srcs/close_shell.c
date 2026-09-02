/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:02:09 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 07:38:33 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int close_shell(t_all *shell)
{
	if (!shell || !shell->tokens || !shell->tokens[0])
		return (0);
	if (ft_strcmp(shell->tokens[0], "exit") == 0)
		return (1);
	return (0);
}
