/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:02:19 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/23 14:45:41 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*get_home_path(char **envp)
{
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	ft_cd(t_all *shell)
{
	char	*path;

	if (!shell || !shell->tokens || !shell->tokens[0])
		return (1);
	if (shell->tokens[1] && shell->tokens[2])
	{
		printf("cd: too many arguments\n");
		return (1);
	}
	if (!shell->tokens[1])
		path = get_home_path(shell->envp);
	else
		path = shell->tokens[1];
	if (!path)
		return (printf("cd: HOME not set"), 1);
	if (chdir(path) == -1)
	{
		printf("cd: ");
		printf("%s",path);
		printf(": No such file or directory");
		return (1);
	}
	return (0);
}
