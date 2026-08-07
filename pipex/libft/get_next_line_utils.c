/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:17:16 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/12/09 03:43:01 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen_gnl(s1)
				+ ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc(sizeof(char) * ft_strlen_gnl(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens;

	lens = ft_strlen_gnl(s);
	if (!s)
		return (ft_strdup_gnl(""));
	if (len > lens - start)
		len = lens - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < lens && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

void	*ft_free_stock(char **str, int copy_line)
{
	char	*line;

	if (!*str)
	{
		return (NULL);
	}
	if (copy_line == 0)
	{
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
		return (NULL);
	}
	else if (copy_line == 1)
	{
		line = ft_strdup_gnl(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	return (NULL);
}
