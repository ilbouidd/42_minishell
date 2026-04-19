/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:40:19 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/15 11:25:11 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
void	del(void *content)
{
	free (content);	
}

int	main(void)
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
	ft_lstdelone(tmp->content, del);
	while(tmp)
	{
		printf("Contenu de node: %zu\n", *(size_t *)tmp->content);
		ft_lstdelone(tmp, del);
		tmp = tmp->next;
	}
}
*/