/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:24:10 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/11 10:11:37 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(t_pipex *pipex)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close_all(pipex);
	exec_cmd(pipex->av[2], pipex->env);
	ft_putstr_fd("exec failed child_one\n", 2);
	exit(1);
}

void	child_two(t_pipex *pipex)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close_all(pipex);
	exec_cmd(pipex->av[3], pipex->env);
	ft_putstr_fd("exec failed child_two\n", 2);
	exit(1);
}

void	exec_cmd1(char *strcmd, char ***cmd_ptr)
{
	*cmd_ptr = ft_split(strcmd, 32);
	if (!*cmd_ptr || !(*cmd_ptr)[0])
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(strcmd, 2);
		ft_putchar_fd('\n', 2);
		if (*cmd_ptr)
			free_split(*cmd_ptr);
		exit(1);
	}
}

void	exec_cmd(char *strcmd, char **env)
{
	char	**cmd;
	char	*path;
	char	*cmd0;

	exec_cmd1(strcmd, &cmd);
	cmd0 = cmd[0];
	if (ft_strchr(cmd0, '/'))
		path = cmd0;
	else
		path = find_path(cmd0, env);
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd0, 2);
		ft_putchar_fd('\n', 2);
		free_split(cmd);
		exit(1);
	}
	execve_last(path, cmd, cmd0, env);
}

void	execve_last(char *path, char **cmd, char *cmd0, char **env)
{
	execve(path, cmd, env);
	ft_putstr_fd("Error: execv", 2);
	ft_putstr_fd(cmd0, 2);
	ft_putchar_fd('\n', 2);
	free_split(cmd);
	if (path != cmd0)
		free(path);
	exit(1);
}
