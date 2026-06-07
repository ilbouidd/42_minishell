/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:04:34 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/07 10:11:23 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_all	shell;
	if (ac == 0)
		return (1);
	(void)av;
	shell.envp = envp;
	readline_shell(&shell);
	
	return (0);
}
