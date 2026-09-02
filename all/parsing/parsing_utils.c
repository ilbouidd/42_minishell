/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:55:39 by ilbouidd          #+#    #+#             */  
/*   Updated: 2026/08/23 17:17:45 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int lst_size(t_all *shell)
{
	int		i;
	t_node	*tmp;

	if (!shell || !shell->stack)
		return (0);
	i = 0;
	tmp = shell->stack;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int is_redir(int type)
{
    return (type == REDIR_IN || type == REDIR_OUT
            || type == REDIR_APPEND || type == REDIR_HERE);
}