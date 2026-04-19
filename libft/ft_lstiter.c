/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:05:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/15 11:42:54 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void del(void *content)
{
    free(content);
}

int main(void)
{
    t_list *node;
    int *value;
	
    *value = 42;

    node = ft_lstnew(value);
	ft_lstiter(node, del);
	free(node);

    return 0;
}
*/