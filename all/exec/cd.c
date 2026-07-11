/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:02:19 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/07/11 03:29:52 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// #include "../../minishell.h"

// static char	*get_home_path(char **envp)
// {
// 	int		i;

// 	i = 0;
// 	while (envp && envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
// 			return (envp[i] + 5);
// 		i++;
// 	}
// 	return (NULL);
// }

// int	ft_cd(t_all *shell)
// {
// 	char	*path;

// 	if (!shell || !shell->tokens || !shell->tokens[0])
// 		return (1);
// 	if (shell->tokens[1] && shell->tokens[2])
// 	{
// 		ft_putendl_fd("cd: too many arguments", 2);
// 		return (1);
// 	}
// 	if (!shell->tokens[1])
// 		path = get_home_path(shell->envp);
// 	else
// 		path = shell->tokens[1];
// 	if (!path)
// 	{
// 		ft_putendl_fd("cd: HOME not set", 2);
// 		return (1);
// 	}
// 	if (chdir(path) == -1)
// 	{
// 		ft_putstr_fd("cd: ", 2);
// 		ft_putstr_fd(path, 2);
// 		ft_putendl_fd(": No such file or directory", 2);
// 		return (1);
// 	}
// 	return (0);
// }
