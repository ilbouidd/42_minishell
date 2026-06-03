/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:00:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/05/30 08:44:09 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(t_all *shell)
{
	int	i;

	if (!shell || !shell->tokens || !shell->tokens[0])
		return (1);
	if (ft_strcmp(shell->tokens[0], "echo") != 0)
		return (1);
	i = 1;
	while (shell->tokens[i])
	{
		printf("%s", shell->tokens[i]);
		// if (shell->tokens[i + 1])
		// 	printf("\n");
		i++;
	}
	printf("\n");
	return (0);
}