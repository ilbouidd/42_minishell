/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:00:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 09:57:17 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


static void ft_echo_second(t_all *shell, int i)
{
	if (ft_strcmp(shell->tokens[1], "-n") == 0)
	{
		i = 2;
		while (shell->tokens[i])
		{
			printf("%s", shell->tokens[i]);
			if (shell->tokens[i + 1])
				printf(" ");
			i++;
		}
	}
	else
	{
		while (shell->tokens[i])
		{
			printf("%s", shell->tokens[i]);
			if (shell->tokens[i + 1])
				printf(" ");
			i++;
		}
		printf("\n");
	}
}

int	ft_echo(t_all *shell)
{
	int	i;

	if (!shell || !shell->tokens || !shell->tokens[0])
		return (1);
	if (ft_strcmp(shell->tokens[0], "echo") != 0)
		return (1);
	i = 1;
	ft_echo_second(shell, i);
	return (0);
}