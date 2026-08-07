/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:55:25 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/10 06:35:26 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	if (!dest && !src)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (src1 < dest1)
	{
		i = n;
		while (i-- > 0)
			dest1[i] = src1[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "bonjour";
	char	dest[20] = "hello";

	ft_memmove(dest, src, 5);
	printf("dest = %s\n", dest);
	memmove(dest, src, 5);
	printf("dest = %s\n", dest);
}
*/