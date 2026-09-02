/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:03:17 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 09:38:35 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

static void close_fd(int fd[2])
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
}

int is_builtin_cmd(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "exit"));
}

static void exec_external(char **args, char **envp)
{
	char	*path;

	if (!args || !args[0])
		exit(1);
	if (ft_strchr(args[0], '/'))
		path = ft_strdup(args[0]);
	else
		path = find_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	exit(126);
}



static int apply_redirections(t_files *files)
{
	t_files	*tmp;
	int		fd;

	tmp = files;
	while (tmp)
	{
		if (tmp->mode == REDIR_IN)
			fd = open(tmp->path, O_RDONLY);
		else if (tmp->mode == REDIR_OUT)
			fd = open(tmp->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (tmp->mode == REDIR_APPEND)
			fd = open(tmp->path, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
		{
			tmp = tmp->next;
			continue ;
		}
		if (fd == -1)
		{
			perror(tmp->path);
			return (-1);
		}
		if (tmp->mode == REDIR_IN)
		{
			if (dup2(fd, STDIN_FILENO) == -1)
			{
				close(fd);
				return (-1);
			}
		}
		else
		{
			if (dup2(fd, STDOUT_FILENO) == -1)
			{
				close(fd);
				return (-1);
			}
		}
		close(fd);
		tmp = tmp->next;
	}
	return (0);
}

static int exec_builtin(t_all *shell, char **args)
{
	char	**save_tokens;
	int		status;

	save_tokens = shell->tokens;
	shell->tokens = args;
	status = exec_shell(shell);
	shell->tokens = save_tokens;
	return (status);
}

static void child_exec(t_all *shell, t_cmd *cmd, int prev_fd, int fd[2])
{
	if (prev_fd != -1)
	{
		if (dup2(prev_fd, STDIN_FILENO) == -1)
			exit(1);
		close(prev_fd);
	}
	if (cmd->next)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit(1);
		close(fd[1]);
	}
	if (fd[0] != -1)
		close(fd[0]);
	if (cmd->files && apply_redirections(cmd->files) == -1)
		exit(1);
	if (is_builtin_cmd(cmd->args[0]))
		exit(exec_builtin(shell, cmd->args));
	exec_external(cmd->args, shell->envp);
}

static int exec_one_builtin(t_all *shell, t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (cmd->files && apply_redirections(cmd->files) == -1)
			exit(1);
		status = exec_builtin(shell, cmd->args);
		exit(status);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int exec_pipeline(t_all *shell)
{
	t_cmd	*cmd;
	int		fd[2];
	int		prev_fd;
	int		status;
	pid_t	pid;

	if (!shell || !shell->command || !shell->command->args
		|| !shell->command->args[0])
		return (0);

	// Si commande unique et que c'est "exit", on l’exécute directement
	if (!shell->command->next
		&& ft_strcmp(shell->command->args[0], "exit") == 0)
	{
		free_all(shell);
		exit(0);
	}

	if (!shell->command->next
		&& is_builtin_cmd(shell->command->args[0]))
		return (exec_one_builtin(shell, shell->command));

	cmd = shell->command;
	prev_fd = -1;
	status = 0;
	while (cmd)
	{
		fd[0] = -1;
		fd[1] = -1;
		if (cmd->next && pipe(fd) == -1)
		{
			if (prev_fd != -1)
				close(prev_fd);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			if (prev_fd != -1)
				close(prev_fd);
			close_fd(fd);
			return (1);
		}
		if (pid == 0)
			child_exec(shell, cmd, prev_fd, fd);
		if (prev_fd != -1)
			close(prev_fd);
		if (cmd->next)
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
		else
			prev_fd = -1;
		cmd = cmd->next;
	}
	if (prev_fd != -1)
		close(prev_fd);
	status = 0;
	cmd = shell->command;
	while (cmd)
	{
		waitpid(-1, &status, 0);
		cmd = cmd->next;
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}