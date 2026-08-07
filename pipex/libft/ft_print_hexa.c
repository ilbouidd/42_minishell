/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:51:00 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/12/05 21:55:06 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenhexa(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	puthexa(unsigned int n, const char logo)
{
	if (n >= 16)
	{
		puthexa(n / 16, logo);
		puthexa(n % 16, logo);
	}
	else
	{
		if (n <= 9)
			write_pf((n + 48), 1);
		else
		{
			if (logo == 'x')
				write_pf((n - 10 + 'a'), 1);
			if (logo == 'X')
				write_pf((n - 10 + 'A'), 1);
		}
	}
}

int	print_x(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		puthexa(n, format);
	return (lenhexa(n));
}
