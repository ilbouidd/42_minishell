/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:06:02 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/01/23 03:40:46 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	fin;
	char	*str;

	i = 0;
	fin = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[fin - 1]))
		fin--;
	str = ft_substr(s1, i, fin - i);
	return (str);
}

// int main()
// {
//     char    str[] = "iiiaaiiaaiiiii";
//     char    set[] = "i";
//     printf("%s", ft_strtrim(str, set));
// }