/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 06:38:21 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 07:39:16 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char *create_temp_file(void)
{
	char	*tmp;
	int		fd;

	tmp = ft_strdup("/tmp/heredoc_XXXXXX");
	if (!tmp)
		return (NULL);
	fd = mkstemp(tmp);
	if (fd == -1)
	{
		free(tmp);
		return (NULL);
	}
	close(fd);
	return (tmp);
}

static int should_expand(int quoted)
{
	if (quoted)
		return (0);
	return (1);
}

static char *clean_delimiter(char *delim)
{
	int		len;
	char	*clean;

	if (!delim)
		return (NULL);
	len = ft_strlen(delim);
	if (len >= 2 && ((delim[0] == '\'' && delim[len - 1] == '\'')
		|| (delim[0] == '"' && delim[len - 1] == '"')))
	{
		clean = ft_substr(delim, 1, len - 2);
		return (clean);
	}
	return (ft_strdup(delim));
}

static char *get_env_value(char **envp, char *name)
{
	int	i;
	int	len;

	if (!envp || !name || !name[0])
		return (ft_strdup(""));
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (ft_strdup(envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

static char *expand_line(char *line, char **envp)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1]
			&& (ft_isalnum(line[i + 1]) || line[i + 1] == '_'))
		{
			char	*name;
			char	*value;
			int		start;

			i++;
			start = i;
			while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
				i++;
			name = ft_substr(line, start, i - start);
			if (!name)
				return (free(result), NULL);
			value = get_env_value(envp, name);
			free(name);
			if (!value)
				return (free(result), NULL);
			tmp = ft_strjoin(result, value);
			free(result);
			free(value);
			result = tmp;
		}
		else
		{
			tmp = ft_substr(line, i, 1);
			if (!tmp)
				return (free(result), NULL);
			tmp = ft_strjoin(result, tmp);
			free(result);
			result = tmp;
			i++;
		}
	}
	return (result);
}

int handle_heredoc(t_all *shell, char *delimiter, int quoted, char **outfile)
{
	char	*tmpfile;
	char	*line;
	char	*clean_delim;
	int		fd;
	int		expand;

	tmpfile = create_temp_file();
	if (!tmpfile)
		return (-1);
	clean_delim = clean_delimiter(delimiter);
	if (!clean_delim)
	{
		free(tmpfile);
		return (-1);
	}
	expand = should_expand(quoted);
	fd = open(tmpfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		free(tmpfile);
		free(clean_delim);
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, clean_delim) == 0)
		{
			free(line);
			break ;
		}
		if (expand && ft_strchr(line, '$'))
		{
			char	*expanded;

			expanded = expand_line(line, shell->envp);
			if (expanded)
			{
				free(line);
				line = expanded;
			}
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	free(clean_delim);
	*outfile = tmpfile;
	return (0);
}