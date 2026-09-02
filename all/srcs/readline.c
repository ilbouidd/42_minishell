/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:22:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 10:07:07 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void readline_shell(t_all *shell)
{
	while (1)
	{
		shell->line = readline("minishell: ");
		if (!shell->line)
			break ;
		if (*shell->line)
			add_history(shell->line);
		split_line(shell);
		content_lexer(shell);
		if (parsing_all(shell) == -1)
		{
			free_all(shell);
			free(shell->line);
			shell->line = NULL;
			continue ;
		}
		build_commands(shell);
		shell->last_status = exec_pipeline(shell);
		// free_all(shell);
		free(shell->line);
		shell->line = NULL;
	}
	rl_clear_history();
}
