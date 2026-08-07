/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 06:44:43 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/07 09:44:33 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/* Compte le nombre de WORD jusqu'au prochain PIPE ou fin de liste */
static int count_args(t_node *tmp)
{
    int count;

    count = 0;
    while (tmp && tmp->type != PIPE)
    {
        if (tmp->type == WORD)
            count++;
        tmp = tmp->next;
    }
    return (count);
}

/* Crée un nouveau nœud de commande vide */
static t_cmd *new_cmd_node(void)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    cmd->type = WORD;
    cmd->args = NULL;
    cmd->files = NULL;
    cmd->next = NULL;
    return (cmd);
}

/* Remplit le tableau d'arguments pour une commande (entre deux pipes) */
static char **fill_args(t_node **tmp)
{
    char    **args;
    int     i;
    int     count;

    count = count_args(*tmp);
    args = malloc(sizeof(char *) * (count + 1));
    if (!args)
        return (NULL);
    i = 0;
    while (*tmp && (*tmp)->type != PIPE)
    {
        if ((*tmp)->type == WORD)
        {
            args[i] = ft_strdup((*tmp)->content);
            if (!args[i])
            {
                /* Cleanup en cas d'échec de ft_strdup */
                while (i > 0)
                    free(args[--i]);
                free(args);
                return (NULL);
            }
            i++;
        }
        *tmp = (*tmp)->next;
    }
    args[i] = NULL;
    return (args);
}

/* Libère une liste de commandes (utilitaire local) */
static void free_cmd_list(t_cmd *cmd)
{
    t_cmd *tmp;

    while (cmd)
    {
        tmp = cmd->next;
        if (cmd->args)
        {
            int i = 0;
            while (cmd->args[i])
                free(cmd->args[i++]);
            free(cmd->args);
        }
        free(cmd);
        cmd = tmp;
    }
}

/* Construit shell->command à partir de shell->stack */
int build_commands(t_all *shell)
{
    t_node  *tmp;
    t_cmd   *new;
    t_cmd   *last;

    if (!shell || !shell->stack)
        return (1);

    tmp = shell->stack;
    shell->command = NULL;
    last = NULL;

    while (tmp)
    {
        new = new_cmd_node();
        if (!new)
        {
            free_cmd_list(shell->command);
            shell->command = NULL;
            return (1);
        }

        new->args = fill_args(&tmp);
        if (!new->args)
        {
            free(new);
            free_cmd_list(shell->command);
            shell->command = NULL;
            return (1);
        }

        if (!shell->command)
            shell->command = new;
        else
            last->next = new;
        last = new;

        /* Si on est sur un PIPE, on avance d'un cran pour le sauter */
        if (tmp && tmp->type == PIPE)
            tmp = tmp->next;
    }
    return (0);
}
