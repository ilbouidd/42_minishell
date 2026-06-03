/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:38:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/03 06:59:49 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_all
{
	char	**av;
	int		ac;
	char	**envp;
	char	*line;
	char	**tokens;
}	t_all;


int	parsing_all(t_all *shell);
int is_sep(char c);
int is_operator(char c);
void    readline_shell(t_all *shell);
void	split_line(t_all *shell);
int exec_shell(t_all *shell);
int ft_echo(t_all *shell);
void	free_all(t_all *shell);
void	close_shell(t_all *shell);
int	is_quote(char c);
void	free_tokens_tab(char **tokens, int j);

#endif
