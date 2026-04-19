/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:10:05 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/13 13:29:55 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	new->next = tmp;
	*lst = new;
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
}
*/