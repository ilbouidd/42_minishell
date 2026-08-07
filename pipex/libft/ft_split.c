/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:17:25 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/12 16:21:47 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	res;
	size_t	count;
	size_t	i;

	res = 0;
	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count = 1;
		}
		if (s[i] != c && count == 1)
		{
			count = 0;
			res += 1;
		}
		i++;
	}
	return (res);
}

static char	*in_tab(const char *s, size_t start, size_t end)
{
	char	*tab;
	size_t	i;
	size_t	len;

	i = 0;
	len = end - start;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (start < end)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

static int	free_tab(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
	return (0);
}

static int	fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j] = in_tab((char *)s, start, i);
			if (!tab[j])
				return (free_tab(tab, j));
			j++;
			start = -1;
		}
		i++;
	}
	tab[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, s, c))
		return (NULL);
	return (tab);
}
/*
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		start;

	if (!s)
		return (NULL);
	start = -1;
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j] = in_tab((char *)s, start, i);
			if (!tab[j])
			{
				i = 0;
				while (i < j)
				{
					free(tab[i]);
					i++;
				}
				free(tab);
				return (NULL);
			}
			j++;
			start = -1;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
*/
/*
int	main(void)
{
	size_t	i;
	char	s[] = "bonjour je m'appelle Ilyass";
	char	**tab;

	i = 0;
	tab = ft_split(s, ' ');
	while (i < count_word(s, ' '))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	// printf("\ntaille d'un char = %lu", sizeof(char));
	// printf("\ntaille d'un char * = %lu", sizeof(char *));
	// printf("\ntaille d'un char ** = %lu", sizeof(char **));
}
*/
