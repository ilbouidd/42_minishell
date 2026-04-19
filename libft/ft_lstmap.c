/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:32:50 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/15 11:43:52 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	lst1 = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst1, del);
			return (NULL);
		}
		ft_lstadd_back(&lst1, node);
		lst = lst->next;
	}
	return (lst1);
}
