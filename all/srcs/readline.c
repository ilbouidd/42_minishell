/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:22:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/04/25 23:14:29 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    readline_shell(void)
{
    char *line;

    while (1)
    {
        line = readline("Ilyshell: ");
        if (!line)
        {
            printf("error: line\n");
            break;
        }
        if (*line)
            add_history(line);
        printf("%s\n", line); //test
        free (line);
    }
    rl_clear_history();
}