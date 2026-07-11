/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:25:53 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/10 14:15:52 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void printf_parse(char *s)
{
    printf("syntax error near unexpected token `%s'\n", s);
}

int	parse_pipe(t_all *shell)
{
	t_node	*tmp;

	if (!shell || !shell->stack)
		return (-1);
	tmp = shell->stack;
	if (tmp->type == PIPE)
		return (printf_parse("|"), -1);
	while (tmp->next)
	{
		if (tmp->type == PIPE && tmp->next->type == PIPE)
			return (printf_parse("|"), -1);
		tmp = tmp->next;
	}
	if (tmp->type == PIPE)
		return (printf_parse("|"), -1);
	return (0);
}

int	parse_redir(t_all *shell)
{
	t_node	*tmp;

	if (!shell || !shell->stack)
		return (-1);
	tmp = shell->stack;
	while (tmp)
	{
		if (is_redir(tmp->type))
		{
			if (!tmp->next)
				return (printf_parse("newline"), -1);
			if (tmp->next->type == PIPE)
				return (printf_parse("|"), -1);
			if (tmp->next->type == REDIR_IN)
				return (printf_parse("<"), -1);
			if (tmp->next->type == REDIR_OUT)
				return (printf_parse(">"), -1);
			if (tmp->next->type == REDIR_APPEND)
				return (printf_parse(">>"), -1);
			if (tmp->next->type == REDIR_HERE)
				return (printf_parse("<<"), -1);
		}
		tmp = tmp->next;
	}
	return (0);
}
