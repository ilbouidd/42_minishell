/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 05:17:33 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/31 05:39:00 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export_is_valid_name(const char *name)
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

char	*export_get_value(char **envp, const char *name)
{
	int	i;
	int	len;

	if (!envp || !name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0
			&& envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

static char	*make_var_string(const char *name, const char *value)
{
	char	*res;
	char	*tmp;

	res = ft_strjoin(name, "=");
	if (!res || !value)
		return (res);
	tmp = res;
	res = ft_strjoin(tmp, value);
	free(tmp);
	return (res);
}

static int	update_existing(t_all *shell, const char *name, const char *value)
{
	char	*new_var;
	int		i;
	int		len;

	len = ft_strlen(name);
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], name, len) == 0
			&& shell->envp[i][len] == '=')
		{
			new_var = make_var_string(name, value);
			if (!new_var)
				return (1);
			free(shell->envp[i]);
			shell->envp[i] = new_var;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	add_new_var(t_all *shell, const char *name, const char *value)
{
	char	*new_var;
	char	**new_envp;
	int		i;

	new_var = make_var_string(name, value);
	if (!new_var)
		return (1);
	i = 0;
	while (shell->envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
	{
		free(new_var);
		return (1);
	}
	i = 0;
	while (shell->envp[i])
	{
		new_envp[i] = shell->envp[i];
		i++;
	}
	new_envp[i] = new_var;
	new_envp[i + 1] = NULL;
	shell->envp = new_envp;
	return (0);
}

int	export_add_or_update(t_all *shell, const char *name, const char *value)
{
	if (!shell || !shell->envp || !name)
		return (1);
	if (update_existing(shell, name, value) == 0)
		return (0);
	return (add_new_var(shell, name, value));
}