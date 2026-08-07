/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:03:17 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/08/07 09:36:33 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../minishell.h"

// /* Ferme les deux extrémités d'un pipe */
// static void close_fd(int fd[2])
// {
//     if (fd[0] != -1)
//         close(fd[0]);
//     if (fd[1] != -1)
//         close(fd[1]);
// }

// /* Vérifie si la commande est un builtin */
// static int is_builtin_cmd(char *cmd)
// {
//     if (!cmd)
//         return (0);
//     return (
//         !ft_strcmp(cmd, "echo") ||
//         !ft_strcmp(cmd, "cd") ||
//         !ft_strcmp(cmd, "pwd") ||
//         !ft_strcmp(cmd, "env") ||
//         !ft_strcmp(cmd, "export") ||
//         !ft_strcmp(cmd, "unset") ||
//         !ft_strcmp(cmd, "exit"));
// }

// static void exec_external(char **args, char **envp)
// {
//     char *path;

//     if (!args || !args[0])
//         exit(1);
//     if (ft_strchr(args[0], '/'))
//         path = ft_strdup(args[0]);
//     else
//         path = find_path(args[0], envp);

//     if (!path)
//     {
//         ft_putstr_fd("command not found: ", 2);
//         ft_putendl_fd(args[0], 2);
//         exit(127);
//     }
//     execve(path, args, envp);
//     perror("execve");
//     free(path);  /* Toujours safe car path est un strdup ou find_path */
//     exit(1);
// }

// /* Exécute une commande dans un enfant (builtin ou externe) */
// static void child_exec(t_all *shell, t_cmd *cmd, int prev_fd, int fd[2])
// {
//     char **save_tokens;
//     int   status;

//     /* Redirections des fds */
//     if (prev_fd != -1)
//     {
//         dup2(prev_fd, STDIN_FILENO);
//         close(prev_fd);
//     }
//     if (cmd->next)
//     {
//         dup2(fd[1], STDOUT_FILENO);
//         close_fd(fd);
//     }
//     if (is_builtin_cmd(cmd->args[0]))
//     {
//         /* Pour les builtins dans un pipe, on les exécute dans l'enfant */
//         save_tokens = shell->tokens;
//         shell->tokens = cmd->args;
//         status = exec_shell(shell);
//         shell->tokens = save_tokens;
//         exit(status);
//     }
//     exec_external(cmd->args, shell->envp);
// }

// /* Exécute un pipeline de commandes */
// int exec_pipeline(t_all *shell)
// {
//     t_cmd *cmd;
//     int   fd[2];
//     int   prev_fd;
//     pid_t pid;

//     if (!shell || !shell->command)
//         return (0);
//     cmd = shell->command;
//     prev_fd = -1;
//     while (cmd)
//     {
//         fd[0] = -1;
//         fd[1] = -1;
//         if (cmd->next && pipe(fd) == -1)
//             return (1);
//         pid = fork();
//         if (pid == 0)
//             child_exec(shell, cmd, prev_fd, fd);
//         if (prev_fd != -1)
//             close(prev_fd);
//         if (cmd->next)
//             close(fd[1]);
//         prev_fd = fd[0];
//         cmd = cmd->next;
//     }
//     while (wait(NULL) > 0)
//         ;
//     return (0);
// }

#include "../../minishell.h"

static void close_fd(int fd[2])
{
    if (fd[0] != -1)
        close(fd[0]);
    if (fd[1] != -1)
        close(fd[1]);
}

static int is_builtin_cmd(char *cmd)
{
    if (!cmd)
        return (0);
    return (
        !ft_strcmp(cmd, "echo") ||
        !ft_strcmp(cmd, "cd") ||
        !ft_strcmp(cmd, "pwd") ||
        !ft_strcmp(cmd, "env") ||
        !ft_strcmp(cmd, "export") ||
        !ft_strcmp(cmd, "unset") ||
        !ft_strcmp(cmd, "exit")
    );
}

static void exec_external(char **args, char **envp)
{
    char *path;

    if (!args || !args[0])
        exit(1);

    if (ft_strchr(args[0], '/'))
        path = ft_strdup(args[0]);
    else
        path = find_path(args[0], envp);

    if (!path)
    {
        ft_putstr_fd("command not found: ", 2);
        ft_putendl_fd(args[0], 2);
        exit(127);
    }

    execve(path, args, envp);
    perror("execve");
    free(path);
    exit(1);
}

/* Applique les redirections pour une commande */
static int apply_redirections(t_files *files)
{
    t_files *tmp;
    int     fd;

    tmp = files;
    while (tmp)
    {
        fd = open(tmp->path, tmp->mode, 0644);
        if (fd == -1)
        {
            perror("open");
            return (-1);
        }

        if (tmp->mode == O_RDONLY)
            dup2(fd, STDIN_FILENO);
        else
            dup2(fd, STDOUT_FILENO);

        close(fd);
        tmp = tmp->next;
    }
    return (0);
}

static void child_exec(t_all *shell, t_cmd *cmd, int prev_fd, int fd[2])
{
    char **save_tokens;
    int   status;

    /* Appliquer les redirections */
    if (cmd->files && apply_redirections(cmd->files) == -1)
        exit(1);

    /* Redirections des fds du pipe */
    if (prev_fd != -1)
    {
        dup2(prev_fd, STDIN_FILENO);
        close(prev_fd);
    }
    if (cmd->next)
    {
        dup2(fd[1], STDOUT_FILENO);
        close_fd(fd);
    }

    if (is_builtin_cmd(cmd->args[0]))
    {
        save_tokens = shell->tokens;
        shell->tokens = cmd->args;
        status = exec_shell(shell);
        shell->tokens = save_tokens;
        exit(status);
    }

    exec_external(cmd->args, shell->envp);
}

int exec_pipeline(t_all *shell)
{
    t_cmd *cmd;
    int   fd[2];
    int   prev_fd;
    pid_t pid;

    if (!shell || !shell->command)
        return (0);

    cmd = shell->command;
    prev_fd = -1;

    while (cmd)
    {
        fd[0] = -1;
        fd[1] = -1;

        if (cmd->next && pipe(fd) == -1)
            return (1);

        pid = fork();
        if (pid == 0)
        {
            /* Enfant */
            child_exec(shell, cmd, prev_fd, fd);
        }

        /* Parent */
        if (prev_fd != -1)
            close(prev_fd);
        if (cmd->next)
            close(fd[1]);

        prev_fd = fd[0];
        cmd = cmd->next;
    }

    /* Attendre tous les enfants */
    while (wait(NULL) > 0)
        ;

    return (0);
}