/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:26:50 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/13 10:34:04 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*node;
	size_t	b;
	t_list	*c;
	size_t	d;
	t_list	*tmp;
	size_t	e;
	t_list	*f;

	b = 200;
	d = 31;
	e = 3;
	c = ft_lstnew(&b);
	f = ft_lstnew(&e);
	node = ft_lstnew(&d);
	ft_lstadd_front(&node, c);
	ft_lstadd_front(&node, f);
	tmp = node;
	while(tmp)
	{
		printf("Contenu de node: %zu\n", *(size_t *)tmp->content);
		tmp = tmp->next;
	}
	printf("%d", ft_lstsize(node));
}
*/