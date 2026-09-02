/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:00:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 09:01:25 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_echo(t_all *shell)
{
	int	i;
	int	if_n;

	if (!shell || !shell->tokens)
		return (1);
	i = 1;
	if_n = 1;
	if (shell->tokens[i] && !ft_strcmp(shell->tokens[i], "-n"))
	{
		if_n = 0;
		i++;
	}
	while (shell->tokens[i])
	{
		write(STDOUT_FILENO, shell->tokens[i], ft_strlen(shell->tokens[i]));
		if (shell->tokens[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (if_n)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

// int ft_echo(t_all *shell)
// {
// 	int	i;
// 	int	if_n;

// 	if (!shell || !shell->tokens)
// 		return (1);
// 	i = 1;
// 	if_n = 1;
// 	if (shell->tokens[i] && !ft_strcmp(shell->tokens[i], "-n"))
// 	{
// 		if_n = 0;
// 		i++;
// 	}
// 	while (shell->tokens[i])
// 	{
// 		printf("%s", shell->tokens[i]);
// 		if (shell->tokens[i + 1])
// 			printf(" ");
// 		i++;
// 	}
// 	if (if_n)
// 		printf("\n");
// 	return (0);
// }