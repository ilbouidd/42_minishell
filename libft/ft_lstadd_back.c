/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:58:28 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/15 11:19:05 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
/*int	main(void)
{
	t_list	*node;
	size_t	b;
	t_list	*c;
	size_t	d;
	t_list	*tmp;
	size_t	e;
	t_list	*f;
	size_t	g;
	t_list	*h;

	b = 200;
	d = 31;
	e = 3;
	g = 999;
	c = ft_lstnew(&b);
	f = ft_lstnew(&e);
	h = ft_lstnew(&g);
	node = ft_lstnew(&d); //31
	ft_lstadd_front(&node, h); //999
	ft_lstadd_back(&node, c); //200
	ft_lstadd_back(&node, f); // 3
	tmp = node;
	while(tmp)
	{
		printf("Contenu de node: %zu\n", *(size_t *)tmp->content);
		tmp = tmp->next;
	}
}
*/