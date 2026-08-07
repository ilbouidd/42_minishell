/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:59:49 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/11 18:59:49 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	ft_toupper2(unsigned int i, char *c)
{
    (void)i;
	if (*c >= 97 && *c <= 122)
		*c = *c - 32;
}

int main()
{
    char str[] = "bonjour je m'appelle ilyass";

    ft_striteri(str, ft_toupper2);
    printf("%s", str);
}
*/
