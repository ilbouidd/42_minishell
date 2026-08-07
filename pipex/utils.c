/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 01:49:55 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/10 09:36:40 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(t_pipex *pipex)
{
	pipex->infile = open(pipex->av[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		ft_putstr_fd("Error: open infile\n", 2);
		return (1);
	}
	pipex->outfile = open(pipex->av[4], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		ft_putstr_fd("Error: open outfile\n", 2);
		return (1);
	}
	return (0);
}

void	close_all(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}
