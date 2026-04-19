/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 07:48:45 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/09 14:33:05 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;
	size_t	j;

	len_dst = ft_strlen(dst);
	i = len_dst;
	j = 0;
	while (src[j] && ((i + j + 1) < size))
	{
		dst[j + i] = src[j];
		j++;
	}
	if (i < size)
		dst[j + i] = '\0';
	if (size < len_dst)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + len_dst);
}
/*
int	main(void)
{
	char	s1[20] = "bonjour";
	char	s2[] = "hello";

	printf("%ld\n", ft_strlcat(s1, s2, 5));
	printf("%ld\n", strlcat(s1, s2, 5));
}
*/