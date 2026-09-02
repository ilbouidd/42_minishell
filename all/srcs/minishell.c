/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:04:34 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 08:24:56 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_all	shell;

	if (ac == 0)
		return (1);
	(void)av;
	shell.command = NULL;
	shell.files = NULL;
	shell.line = NULL;
	shell.stack = NULL;
	shell.tokens = NULL;
	shell.envp = envp;
	shell.last_status = 0;
	init_signals();
	readline_shell(&shell);
	return (0);
}
