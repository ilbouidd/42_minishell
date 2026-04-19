/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:16:50 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/12/09 03:42:10 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy_et_stocker(char *stock, char *buffer)
{
	char	*res;

	res = 0;
	if (!stock && buffer)
	{
		res = ft_strdup_gnl(buffer);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin_gnl(stock, buffer);
	ft_free_stock(&stock, 0);
	return (res);
}

static int	ft_newline(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_extrait_line(char *stock)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		line[j] = stock[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_recreate_line(char *stock)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i] || stock[i + 1] == '\0')
		return (ft_free_stock(&stock, 0));
	res = ft_substr_gnl(stock, i + 1, ft_strlen(stock) - i - 1);
	ft_free_stock(&stock, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			buf_read;
	static char	*stock = NULL;
	char		*line;

	line = NULL;
	buf_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stock(&stock, 0));
	while (buf_read > 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read == -1 || (buf_read == 0 && stock == NULL))
			return (ft_free_stock(&stock, 0));
		buffer[buf_read] = '\0';
		stock = ft_copy_et_stocker(stock, buffer);
		if (ft_newline(stock))
		{
			line = ft_extrait_line(stock);
			if (!line)
				return (ft_free_stock(&stock, 0));
			return (stock = ft_recreate_line(stock), line);
		}
	}
	return (ft_free_stock(&stock, 1));
}

// int main(void)
// {
// int fd;
// char *str;

// fd = open ("test.txt", O_RDONLY);
// str = get_next_line(fd);
// while (str)
// {
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	return (0);
// }