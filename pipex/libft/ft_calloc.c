/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:13:08 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/06 10:47:34 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = malloc(nmemb * n);
	if (!tab)
		return (NULL);
	while (i < nmemb * n)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
/*
int main()
{
    size_t  i;
    unsigned char *s;

    i = 0;
    s = ft_calloc(1, 5);
    s[1 * 5] = 6;
    while (i < 6)
    {
        printf("%d", s[i]);
        i++;
    }
}
*/
