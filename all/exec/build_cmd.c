/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 06:44:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 09:39:05 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

static int is_redir_type(int type)
{
	return (type == REDIR_IN || type == REDIR_OUT
		|| type == REDIR_APPEND || type == REDIR_HERE);
}

static int count_args(t_node *tmp)
{
	int	count;

	count = 0;
	while (tmp && tmp->type != PIPE)
	{
		if (is_redir_type(tmp->type))
		{
			tmp = tmp->next;
			if (tmp)
				tmp = tmp->next;
		}
		else
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}

static t_cmd *new_cmd_node(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->type = WORD;
	cmd->args = NULL;
	cmd->files = NULL;
	cmd->next = NULL;
	return (cmd);
}

static t_files *new_file_node(int type, char *path)
{
	t_files	*file;

	file = malloc(sizeof(t_files));
	if (!file)
		return (NULL);
	file->path = ft_strdup(path);
	if (!file->path)
	{
		free(file);
		return (NULL);
	}
	file->mode = type;
	file->heredoc_content = NULL;
	file->next = NULL;
	return (file);
}

static void add_file_to_cmd(t_cmd *cmd, int type, char *path)
{
	t_files	*new;
	t_files	*tmp;

	new = new_file_node(type, path);
	if (!new)
		return ;
	if (!cmd->files)
	{
		cmd->files = new;
		return ;
	}
	tmp = cmd->files;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void expand_args(t_all *shell, char **args)
{
	char	*expanded;
	char	*stripped;
	int		i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		expanded = expand_string(shell, args[i]);
		if (expanded)
		{
			free(args[i]);
			stripped = strip_outer_quotes(expanded);
			args[i] = stripped ? stripped : expanded;
		}
		i++;
	}
}

static int add_redirection(t_node **tmp, t_cmd *cmd, t_all *shell)
{
	int		type;
	char	*path;
	char	*heredoc_file;
	int		quoted;

	type = (*tmp)->type;
	*tmp = (*tmp)->next;
	if (!(*tmp))
		return (0);
	path = (*tmp)->content;
	quoted = (*tmp)->quoted;
	if (type == REDIR_HERE)
	{
		if (handle_heredoc(shell, path, quoted, &heredoc_file) != 0)
			return (0);
		add_file_to_cmd(cmd, REDIR_IN, heredoc_file);
		free(heredoc_file);
	}
	else
		add_file_to_cmd(cmd, type, path);
	*tmp = (*tmp)->next;
	return (1);
}

static void free_args(char **args, int count)
{
	while (count > 0)
		free(args[--count]);
	free(args);
}

static char **fill_args(t_node **tmp, t_cmd *cmd, t_all *shell)
{
	char	**args;
	int		i;
	int		count;

	count = count_args(*tmp);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (*tmp && (*tmp)->type != PIPE)
	{
		if (is_redir_type((*tmp)->type))
		{
			if (!add_redirection(tmp, cmd, shell))
			{
				free_args(args, i);
				return (NULL);
			}
		}
		else
		{
			args[i] = ft_strdup((*tmp)->content);
			if (!args[i])
			{
				free_args(args, i);
				return (NULL);
			}
			i++;
			*tmp = (*tmp)->next;
		}
	}
	args[i] = NULL;
	return (args);
}

static void free_cmd_list(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
				free(cmd->args[i++]);
			free(cmd->args);
		}
		if (cmd->files)
		{
			t_files	*f;
			t_files	*next_f;

			f = cmd->files;
			while (f)
			{
				next_f = f->next;
				if (f->path)
				{
					unlink(f->path);
					free(f->path);
				}
				free(f);
				f = next_f;
			}
		}
		free(cmd);
		cmd = tmp;
	}
}

int build_commands(t_all *shell)
{
	t_node	*tmp;
	t_cmd	*new;
	t_cmd	*last;

	if (!shell || !shell->stack)
		return (1);
	tmp = shell->stack;
	shell->command = NULL;
	last = NULL;
	while (tmp)
	{
		new = new_cmd_node();
		if (!new)
		{
			free_cmd_list(shell->command);
			shell->command = NULL;
			return (1);
		}
		new->args = fill_args(&tmp, new, shell);
		if (!new->args)
		{
			free(new);
			free_cmd_list(shell->command);
			shell->command = NULL;
			return (1);
		}
		expand_args(shell, new->args);
		if (!shell->command)
			shell->command = new;
		else
			last->next = new;
		last = new;
		if (tmp && tmp->type == PIPE)
			tmp = tmp->next;
	}
	return (0);
}