/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:40:41 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/07/11 03:24:24 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_all *shell)
{
	char	cwd[4096];

	if (!shell || !shell->tokens || !shell->tokens[0])
		return (1);
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		return (1);
	return (0);
}