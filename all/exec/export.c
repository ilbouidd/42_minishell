/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:31:01 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/31 05:18:35 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	process_no_eq(t_all *shell, char *arg)
{
	if (export_is_valid_name(arg))
		export_add_or_update(shell, arg, NULL);
}

static void	process_with_eq(t_all *shell, char *arg, char *eq)
{
	char	*name;
	char	*value;

	name = ft_substr(arg, 0, eq - arg);
	if (!name)
		return ;
	if (!export_is_valid_name(name))
	{
		free(name);
		return ;
	}
	value = eq + 1;
	export_add_or_update(shell, name, value);
	free(name);
}

static void	process_arg(t_all *shell, char *arg)
{
	char	*eq;

	eq = ft_strchr(arg, '=');
	if (!eq)
		process_no_eq(shell, arg);
	else
		process_with_eq(shell, arg, eq);
}

int	ft_export(t_all *shell)
{
	int	i;

	if (!shell || !shell->tokens || !shell->tokens[0])
		return (1);
	if (ft_strcmp(shell->tokens[0], "export") != 0)
		return (1);
	i = 1;
	if (!shell->tokens[i])
	{
		export_print(shell->envp);
		return (0);
	}
	while (shell->tokens[i])
	{
		process_arg(shell, shell->tokens[i]);
		i++;
	}
	return (0);
}