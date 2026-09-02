/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 05:43:34 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 08:33:41 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char *get_var_value(t_all *shell, char *name)
{
	int	i;
	int	len;

	if (!name || !name[0])
		return (ft_strdup(""));
	if (name[0] == '?')
		return (ft_itoa(shell->last_status));
	len = ft_strlen(name);
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], name, len) == 0
			&& shell->envp[i][len] == '=')
			return (ft_strdup(shell->envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

// static char *get_var_value(t_all *shell, char *name)
// {
// 	int	i;
// 	int	len;

// 	if (!name || !name[0])
// 		return (ft_strdup(""));
// 	if (name[0] == '?')
// 		return (ft_itoa(0));
// 	len = ft_strlen(name);
// 	i = 0;
// 	while (shell->envp[i])
// 	{
// 		if (ft_strncmp(shell->envp[i], name, len) == 0
// 			&& shell->envp[i][len] == '=')
// 			return (ft_strdup(shell->envp[i] + len + 1));
// 		i++;
// 	}
// 	return (ft_strdup(""));
// }

static char *expand_var(t_all *shell, char *str, int *i, int in_single_quote)
{
	char	*name;
	char	*value;
	int		start;

	(void)in_single_quote;
	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (get_var_value(shell, "?"));
	}
	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	name = ft_substr(str, start, *i - start);
	if (!name)
		return (NULL);
	value = get_var_value(shell, name);
	free(name);
	return (value);
}

static int append_char(char **result, char c)
{
	char	*tmp;
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	tmp = ft_strjoin(*result, buf);
	if (!tmp)
		return (0);
	free(*result);
	*result = tmp;
	return (1);
}

static int append_var(t_all *shell, char **result, char *str, int *i, int in_single_quote)
{
	char	*value;
	char	*tmp;

	value = expand_var(shell, str, i, in_single_quote);
	if (!value)
		return (0);
	tmp = ft_strjoin(*result, value);
	free(value);
	if (!tmp)
		return (0);
	free(*result);
	*result = tmp;
	return (1);
}

char *strip_outer_quotes(char *str)
{
	int		len;
	char	*res;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len >= 2
		&& ((str[0] == '\'' && str[len - 1] == '\'')
		|| (str[0] == '"' && str[len - 1] == '"')))
	{
		res = ft_substr(str, 1, len - 2);
		free(str);
		return (res);
	}
	return (str);
}

char *expand_string(t_all *shell, char *str)
{
	char	*result;
	char	quote;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	quote = 0;
	i = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
		{
			quote = str[i];
			i++;
		}
		else if (quote && str[i] == quote)
		{
			quote = 0;
			i++;
		}
		else if (str[i] == '$' && quote != '\''
			&& str[i + 1]
			&& (ft_isalnum(str[i + 1])
			|| str[i + 1] == '_' || str[i + 1] == '?'))
		{
			if (!append_var(shell, &result, str, &i, 0))
				return (free(result), NULL);
		}
		else
		{
			if (!append_char(&result, str[i]))
				return (free(result), NULL);
			i++;
		}
	}
	return (result);
}

// char *expand_string(t_all *shell, char *str)
// {
// 	char	*result;
// 	char	quote;
// 	int		i;

// 	result = ft_strdup("");
// 	if (!result)
// 		return (NULL);
// 	quote = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!quote && (str[i] == '\'' || str[i] == '"'))
// 		{
// 			quote = str[i];
// 			if (!append_char(&result, str[i]))
// 				return (free(result), NULL);
// 			i++;
// 		}
// 		else if (quote && str[i] == quote)
// 		{
// 			quote = 0;
// 			if (!append_char(&result, str[i]))
// 				return (free(result), NULL);
// 			i++;
// 		}
// 		else if (str[i] == '$' && quote != '\''
// 			&& str[i + 1]
// 			&& (ft_isalnum(str[i + 1])
// 			|| str[i + 1] == '_' || str[i + 1] == '?'))
// 		{
// 			if (!append_var(shell, &result, str, &i, 0))
// 				return (free(result), NULL);
// 		}
// 		else
// 		{
// 			if (!append_char(&result, str[i]))
// 				return (free(result), NULL);
// 			i++;
// 		}
// 	}
// 	return (result);
// }

void expand_all_tokens(t_all *shell)
{
	char	*expanded;
	int		i;

	if (!shell || !shell->tokens)
		return ;
	i = 0;
	while (shell->tokens[i])
	{
		expanded = expand_string(shell, shell->tokens[i]);
		if (expanded)
		{
			free(shell->tokens[i]);
			shell->tokens[i] = expanded;
		}
		i++;
	}
}
