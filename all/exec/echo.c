/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:00:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/07/11 02:14:39 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_echo(t_all *shell)
{
    int i;
    int if_n;

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
        printf(shell->tokens[i]);
        if (shell->tokens[i + 1])
            printf(" ");
        i++;
    } 
    if (if_n)
        printf("\n");
    return (0);
}

// static void ft_echo_second(t_all *shell)
// {
// 	if (ft_strcmp(shell->tokens[1], "-n") == 0)
// 	{
// 		i = 2;
// 		while (shell->tokens[i])
// 		{
// 			printf("%s", shell->tokens[i]);
// 			if (shell->tokens[i + 1])
// 				printf(" ");
// 			i++;
// 		} 
// 	}
// 	else
// 	{
// 		while (shell->tokens[i])
// 		{
// 			printf("%s", shell->tokens[i]);
// 			if (shell->tokens[i + 1])
// 				printf(" ");
// 			i++;
// 		}
// 		printf("\n");
// 	}
// }



// int	ft_echo(t_all *shell)
// {
// 	int	i;

// 	printf("debut echo");
// 	if (!shell || !shell->tokens || !shell->tokens[0])
// 		return (1);
// 	printf("debut echo");
// 	if (ft_strcmp(shell->tokens[0], "echo") != 0)
// 		return (1);
// 	i = 1;
	
// 	printf("debut echo");
	
// 	ft_echo_second(shell, i);
// 	return (0);
// }