/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:34:04 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/10 10:09:59 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		status;
	int		process_one;
	int		process_two;
	t_pipex	pipex;

	if (ac != 5)
		return (ft_putstr_fd("Error :No good argument\n", 2), 1);
	pipex.env = envp;
	pipex.av = av;
	if (open_file(&pipex) == 1)
		return (ft_putstr_fd("Error: file\n", 2), 1);
	if (pipe(pipex.fd) == -1)
		return (ft_putstr_fd("Error: pipe\n", 2), 1);
	process_one = fork();
	if (process_one == 0)
		child_one(&pipex);
	process_two = fork();
	if (process_two == 0)
		child_two(&pipex);
	close_all(&pipex);
	waitpid(process_one, NULL, 0);
	waitpid(process_two, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

// int	main(int ac, char **av, char **envp)
// {
// 	int	i = 0;

// 	while (envp[i])
// 	{
// 		ft_printf("%s\n", envp[i]);
// 		i++;
// 	}
// 	return (0);
// }