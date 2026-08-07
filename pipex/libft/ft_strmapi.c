/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:55:40 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/11 19:48:31 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	ft_toupper2(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char str1[] = "aaaaaaaaaaa";
	char str2[] = "bbbbbbbbbbb";
	char *res;

	printf("str1 (avant mapi) : %s\n", str1);
	res = ft_strmapi(str1, ft_toupper2);
	if (res)
		printf("str1 (après mapi) : %s\n", res);
	printf("str2 (avant mapi) : %s\n", str2);
	res = ft_strmapi(str2, ft_toupper2);
	if (res)
		printf("str2 (après mapi) : %s\n", res);
	return (0);
}
*/
