/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 10:02:36 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/07 11:01:46 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	skip_quoted(const char *s, int *i)
{
	char	quote;

	quote = s[*i];
	(*i)++;
	while (s[*i] && s[*i] != quote)
		(*i)++;
	if (s[*i] == quote)
		(*i)++;
}

static int	word_len(const char *s, int i)
{
	int		len;
	char	quote;

	len = 0;
	while (s[i] && !is_sep(s[i]) && !is_operator(s[i]))
	{
		if (is_quote(s[i]))
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
			{
				len++;
				i++;
			}
			if (s[i] == quote)
				i++;
		}
		else
			len += (i++, 1);
	}
	return (len);
}

static char	*fill_word(const char *s, int start, int end, char *word)
{
	int		j;
	char	quote;

	j = 0;
	while (start < end)
	{
		if (is_quote(s[start]))
		{
			quote = s[start++];
			while (start < end && s[start] != quote)
				word[j++] = s[start++];
			if (start < end && s[start] == quote)
				start++;
		}
		else
			word[j++] = s[start++];
	}
	word[j] = '\0';
	return (word);
}

static char	*dup_word(const char *s, int *i)
{
	int		start;
	int		len;
	char	*word;

	start = *i;
	while (s[*i] && !is_sep(s[*i]) && !is_operator(s[*i]))
	{
		if (is_quote(s[*i]))
			skip_quoted(s, i);
		else
			(*i)++;
	}
	len = word_len(s, start);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	return (fill_word(s, start, *i, word));
}

static char	*dup_operator(const char *s, int *i)
{
	if ((s[*i] == '<' && s[*i + 1] == '<')
		|| (s[*i] == '>' && s[*i + 1] == '>'))
	{
		*i += 2;
		return (ft_substr(s, *i - 2, 2));
	}
	(*i)++;
	return (ft_substr(s, *i - 1, 1));
}

static int	count_tokens(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i]))
			i++;
		if (!s[i])
			break ;
		count++;
		if ((s[i] == '<' && s[i + 1] == '<')
			|| (s[i] == '>' && s[i + 1] == '>'))
			i += 2;
		else if (is_operator(s[i]))
			i++;
		else
			while (s[i] && !is_sep(s[i]) && !is_operator(s[i]))
				if (is_quote(s[i]))
					skip_quoted(s, &i);
				else
					i++;
	}
	return (count);
}

static char	**split_tokens(const char *s)
{
	char	**tokens;
	int		i;
	int		j;

	tokens = malloc(sizeof(char *) * (count_tokens(s) + 1));
	if (!tokens || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i]))
			i++;
		if (!s[i])
			break ;
		if (is_operator(s[i]))
			tokens[j] = dup_operator(s, &i);
		else
			tokens[j] = dup_word(s, &i);
		if (!tokens[j])
			return (free_tokens_tab(tokens, j), NULL);
		j++;
	}
	tokens[j] = NULL;
	return (tokens);
}

void	split_line(t_all *shell)
{
	if (!shell || !shell->line)
		return ;
	shell->tokens = split_tokens(shell->line);
}