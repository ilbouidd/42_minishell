/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:52:47 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/01/23 03:40:30 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format(va_list s, int logo)
{
	int	count;

	count = 0;
	if (logo == 'c')
		count += print_c(va_arg(s, int));
	else if (logo == 's')
		count += print_s(va_arg(s, char *));
	else if (logo == 'd' || logo == 'i')
		count += print_int(va_arg(s, int));
	else if (logo == 'u')
		count += print_u(va_arg(s, unsigned int));
	else if (logo == '%')
		count += print_pourcent();
	else if (logo == 'x' || logo == 'X')
		count += print_x(va_arg(s, unsigned int), logo);
	else if (logo == 'p')
		count += print_p(va_arg(s, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	s;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	va_start(s, str);
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (i == ft_strlen(str) - 1)
				return (-1);
			count += format(s, str[i + 1]);
			i++;
		}
		else
			count += print_c(str[i]);
		i++;
	}
	va_end(s);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("char: %c\n", 'd');
// 	ft_printf("chaine: %s\n", "ilyass");
// 	ft_printf("int: %d / %i\n", 111, 2222);
// 	ft_printf("unsigned int: %u\n", 2148473649);
// 	ft_printf("%%\n");
// 	ft_printf("hexa: %x, %X\n", 11, 11);
// 	ft_printf("pointeur: %p\n", 11);
// }
