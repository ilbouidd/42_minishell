/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:16:51 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/11 10:09:29 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**env;
	int		infile;
	int		outfile;
	int		fd[2];
	char	**av;
}			t_pipex;

int			open_file(t_pipex *pipex);
void		close_all(t_pipex *pipex);
void		child_one(t_pipex *pipex);
void		child_two(t_pipex *pipex);
void		exec_cmd(char *strcmd, char **env);
char		*find_path(char *cmd, char **env);
char		*find_path_second(char **paths, char *cmd);
char		*get_path_env(char **env);
void		exec_cmd1(char *strcmd, char ***cmd_ptr);
void		execve_last(char *path, char **cmd, char *cmd0, char **env);

#endif
