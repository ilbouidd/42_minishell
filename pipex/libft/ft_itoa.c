/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:09:14 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/10 14:04:57 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	size_t	res;

	res = 0;
	if (n == 0)
		res++;
	if (n < 0)
	{
		res++;
		n = n * (-1);
	}
	while (n != 0)
	{
		n = n / 10;
		res += 1;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*tab;
	size_t	i;
	size_t	sign;

	nb = n;
	sign = 0;
	i = count_len(nb);
	tab = malloc(sizeof(char) * (count_len(nb) + 1));
	if (!tab)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * (-1);
		sign = 1;
		tab[0] = '-';
	}
	tab[i] = '\0';
	while (i > sign)
	{
		tab[i - 1] = (nb % 10 + 48);
		nb = nb / 10;
		i--;
	}
	return (tab);
}
/*
int	main(void)
{
	printf("%s",ft_itoa(2327494));
	//printf("\n%d", count_len(-2147483648));
}
*/