/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 02:20:45 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/01 07:48:51 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

char *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    char    *full_path;
    int     i;

    if (!cmd || !envp)
        return (NULL);

    /* Si la commande contient '/', on vérifie directement */
    if (ft_strchr(cmd, '/'))
    {
        if (access(cmd, F_OK | X_OK) == 0)
            return (ft_strdup(cmd));
        return (NULL);
    }

    /* Récupérer PATH depuis envp */
    paths = NULL;
    while (*envp)
    {
        if (ft_strnstr(*envp, "PATH=", 5) == *envp)
        {
            path = *envp + 5;
            paths = ft_split(path, ':');
            break;
        }
        envp++;
    }

    if (!paths)
        return (NULL);

    /* Tester chaque chemin */
    i = 0;
    while (paths[i])
    {
        full_path = ft_strjoin(paths[i], "/");
        if (!full_path)
        {
            free_split(paths);
            return (NULL);
        }
        path = ft_strjoin(full_path, cmd);
        free(full_path);
        if (!path)
        {
            free_split(paths);
            return (NULL);
        }
        if (access(path, F_OK | X_OK) == 0)
        {
            free_split(paths);
            return (path);
        }
        free(path);
        i++;
    }

    free_split(paths);
    return (NULL);
}