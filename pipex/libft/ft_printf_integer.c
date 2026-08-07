/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:00:11 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/12/05 21:55:12 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int n)
{
	long	nb;
	size_t	i;

	i = 1;
	nb = n;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (i);
}

static void	printrecursive(unsigned int n)
{
	if (n > 9)
		print_u(n / 10);
	if (n <= 9)
	{
		write_pf((n + 48), 1);
		return ;
	}
	write_pf((n % 10) + 48, 1);
}

int	print_u(unsigned int n)
{
	unsigned int	i;

	printrecursive(n);
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
