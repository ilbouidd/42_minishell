/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:54:17 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:37 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*str;

	if (start >= ft_strlen(s))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return ((char *)str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, (s + start), len);
	str[len] = '\0';
	return ((char *)str);
}

// int	main(void)
// {
// 	char	s[30  ] = "ABCD";

// 	printf("%s", ft_substr(s, 2, 5));
// }