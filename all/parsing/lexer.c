/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:54:17 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/09 14:57:04 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node  *new_node(char *content, int type, int id)
{
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->content = content;
    new->type = type;
    new->id = id;
    new->next = NULL;
    return (new);
}

int create_stack(t_all *shell, char *content, int type, int id)
{
    t_node  *node;

    node = new_node(content, type, id);
    if (!node)
        return (-1);
    node->next = shell->stack;
    shell->stack = node;
    return (0);
}

void    print_stack(t_node *stack)
{
    while(stack)
    {
        printf("id = %d   type = %d  content = %s\n", stack->id, stack->type, stack->content);
        stack = stack->next;
    }
}

int    find_type_node(char *tokens)
{
    if (ft_strcmp(tokens, "|") == 0)
        return (PIPE);
    else if (ft_strcmp(tokens, ">") == 0)
        return (REDIR_OUT);
    else if (ft_strcmp(tokens, "<") == 0)
        return (REDIR_IN);
    else if (ft_strcmp(tokens, ">>") == 0)
        return (REDIR_APPEND);
    else if (ft_strcmp(tokens, "<<") == 0)
        return (REDIR_HERE);
    else
        return 0;
        
}

void    content_lexer(t_all *shell)
{
    int i;
    int type;

    if (!shell || !shell->tokens)
        return;
    i = 0;
    shell->stack = NULL;
    while (shell->tokens[i])
    {
        type = find_type_node(shell->tokens[i]);
        if (create_stack(shell, shell->tokens[i], type, i))
            return ;
        i++;
    }
    print_stack(shell->stack);
}