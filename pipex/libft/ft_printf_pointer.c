/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:41:17 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/12/05 21:55:19 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putptr(size_t n)
{
	if (n >= 16)
	{
		putptr(n / 16);
		putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			write_pf((n + 48), 1);
		else
		{
			write_pf((n - 10 + 'a'), 1);
		}
	}
}

static int	lenptr(size_t n)
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

int	print_p(void *ptr)
{
	int		i;
	size_t	ptr1;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 0;
	ptr1 = (size_t)ptr;
	i += write(1, "0x", 2);
	if (ptr1 == 0)
		i += write(1, "0", 1);
	else
	{
		putptr(ptr1);
		i += lenptr(ptr1);
	}
	return (i);
}

// int	main(void)
// {
// 	// char    *i;
// 	// int     *p;
// 	// void    *t;

// 	printf("%p\n", 0);
// 	// printf("%p\n", p);
// 	// printf("%p\n", t);
// }