/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:40:21 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/31 05:33:39 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	unset_is_valid_name(const char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	count_env_vars(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static char	**alloc_new_env(int count)
{
	return (malloc(sizeof(char *) * (count + 1)));
}

static void	copy_env_except(char **new_envp, char **old_envp, int skip_idx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old_envp[i])
	{
		if (i == skip_idx)
			free(old_envp[i]);
		else
			new_envp[j++] = old_envp[i];
		i++;
	}
	new_envp[j] = NULL;
}

static void	unset_remove_var(t_all *shell, const char *name)
{
	int		i;
	int		len;
	int		count;
	char	**new_envp;

	if (!shell || !shell->envp || !name)
		return ;
	len = ft_strlen(name);
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], name, len) == 0
			&& shell->envp[i][len] == '=')
		{
			count = count_env_vars(shell->envp);
			new_envp = alloc_new_env(count - 1);
			if (!new_envp)
				return ;
			copy_env_except(new_envp, shell->envp, i);
			free(shell->envp);
			shell->envp = new_envp;
			return ;
		}
		i++;
	}
}

int	ft_unset(t_all *shell)
{
	int	i;

	if (!shell || !shell->tokens || !shell->tokens[0])
		return (1);
	if (ft_strcmp(shell->tokens[0], "unset") != 0)
		return (1);
	i = 1;
	while (shell->tokens[i])
	{
		if (unset_is_valid_name(shell->tokens[i]))
			unset_remove_var(shell, shell->tokens[i]);
		i++;
	}
	return (0);
}