/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:36:28 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/13 10:56:21 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	t_list	*g;

	b = 200;
	d = 31;
	e = 3;
	c = ft_lstnew(&b);
	f = ft_lstnew(&e);
	node = ft_lstnew(&d);
	ft_lstadd_front(&node, c);
	ft_lstadd_front(&node, f);
	tmp = node;
	printf("Contenu de node: ");
	while(tmp)
	{
		printf("%zu ,", *(size_t *)tmp->content);
		tmp = tmp->next;
	}
	g = ft_lstlast(node);
	printf("\n");
	printf("dernier node: %zu", *(size_t *)g -> content);
}
*/