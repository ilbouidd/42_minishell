/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:59:10 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 07:40:33 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int parse_quote(t_all *shell)
{
	int	i;
	int	count_quote;
	int	count_double_quote;

	i = 0;
	count_quote = 0;
	count_double_quote = 0;
	while (shell->line[i])
	{
		if (shell->line[i] == '\'')
			count_quote++;
		else if (shell->line[i] == '"')
			count_double_quote++;
		i++;
	}
	if (count_quote % 2 != 0)
	{
		printf("syntax error near unexpected token `newline'\n");
		return (-1);
	}
	else if (count_double_quote % 2 != 0)
	{
		printf("syntax error near unexpected token `newline'\n");
		return (-1);
	}
	return (0);
}
