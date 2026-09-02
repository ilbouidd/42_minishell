/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:54:17 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/01 08:26:36 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_quoted_token(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 2)
		return (0);
	if ((str[0] == '\'' && str[len - 1] == '\'')
		|| (str[0] == '"' && str[len - 1] == '"'))
		return (1);
	return (0);
}

t_node	*new_node(char *content, int type, int id, int quoted)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->type = type;
	new->id = id;
	new->quoted = quoted;
	new->next = NULL;
	return (new);
}
int create_stack(t_all *shell, char *content, int type, int id, int quoted)
{
    t_node  *node;
    t_node  *last;

    if (!shell)
        return (-1);
    node = new_node(content, type, id, quoted);
    if (!node)
        return (-1);
    if (!shell->stack)
    {
        shell->stack = node;
        return (0);
    }
    last = shell->stack;
    while (last->next)
        last = last->next;
    last->next = node;
    return (0);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("id = %d type = %d content = %s quoted = %d\n",
			stack->id, stack->type, stack->content, stack->quoted);
		stack = stack->next;
	}
}

int	find_type_node(char *tokens)
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
		return (0);
}

void    content_lexer(t_all *shell)
{
    int i;
    int type;
    int quoted;

    if (!shell || !shell->tokens)
        return ;
    i = 0;
    shell->stack = NULL;
    while (shell->tokens[i])
    {
        type = find_type_node(shell->tokens[i]);
        quoted = is_quoted_token(shell->tokens[i]);
        if (create_stack(shell, shell->tokens[i], type, i, quoted))
            return ;
        i++;
    }
}