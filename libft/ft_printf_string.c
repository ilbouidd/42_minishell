/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:00:13 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/12/05 21:55:25 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_c(int s)
{
	return (write_pf(s, 1));
}

int	print_s(char *s)
{
	size_t	i;
	int		j;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		j = write_pf(s[i], 1);
		if (j < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	print_pourcent(void)
{
	write(1, "%", 1);
	return (1);
}

int	write_pf(char s, int fd)
{
	int	i;

	i = 0;
	i = write(fd, &s, 1);
	if (i < 0)
		return (-1);
	return (i);
}

// int	main(void)
// {
// 	printf("%d", print_s("poiii"));
// }
