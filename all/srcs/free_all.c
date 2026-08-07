/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 09:43:14 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/07 06:02:14 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../minishell.h"

// void	free_tokens(char **tokens)
// {
// 	int	i;

// 	if (!tokens)
// 		return ;
// 	i = 0;
// 	while (tokens[i])
// 	{
// 		free(tokens[i]);
// 		i++;
// 	}
// 	free(tokens);
// }

// void	free_stack(t_node *stack)
// {
// 	t_node	*tmp;

// 	while (stack)
// 	{
// 		tmp = stack->next;
// 		free(stack);
// 		stack = tmp;
// 	}
// }

// void free_commands(t_cmd *cmd)
// {
//     t_cmd *tmp;
//     int i;

//     while (cmd)
//     {
//         tmp = cmd->next;
//         if (cmd->args)
//         {
//             i = 0;
//             while (cmd->args[i])
//                 free(cmd->args[i++]);
//             free(cmd->args);
//         }
//         free(cmd);
//         cmd = tmp;
//     }
// }

// void	free_all(t_all *shell)
// {
// 	if (!shell)
// 		return ;
// 	if (shell->tokens)
// 	{
// 		free_tokens_tab(shell->tokens, 0);
// 		shell->tokens = NULL;
// 	}
// 	if (shell->stack)
// 	{
// 		free_stack(shell->stack);
// 		shell->stack = NULL;
// 	}
// 	if (shell->command)
// 	{
// 		free_commands(shell->command);
// 		shell->command = NULL;
// 	}
// }

#include "../../minishell.h"

void free_tokens(char **tokens)
{
    int i;

    if (!tokens)
        return;
    i = 0;
    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
}

void free_stack(t_node *stack)
{
    t_node *tmp;

    while (stack)
    {
        tmp = stack->next;
        free(stack->content);
        free(stack);
        stack = tmp;
    }
}

void free_commands(t_cmd *cmd)
{
    t_cmd *tmp;
    int i;

    while (cmd)
    {
        tmp = cmd->next;
        if (cmd->args)
        {
            i = 0;
            while (cmd->args[i])
                free(cmd->args[i++]);
            free(cmd->args);
        }
        free(cmd);
        cmd = tmp;
    }
}

void free_all(t_all *shell)
{
    if (!shell)
        return;
    if (shell->tokens)
    {
        free_tokens(shell->tokens);
        shell->tokens = NULL;
    }
    if (shell->stack)
    {
        free_stack(shell->stack);
        shell->stack = NULL;
    }
    if (shell->command)
    {
        free_commands(shell->command);
        shell->command = NULL;
    }
}