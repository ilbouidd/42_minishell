/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:38:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/06/09 14:56:19 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

#define WORD 0
#define PIPE 1
#define REDIRECTION 2
#define REDIR_IN 3
#define REDIR_OUT 4
#define REDIR_APPEND 5
#define REDIR_HERE 6

typedef struct s_node
{
	int	type;
	char *content;
	int	id;
	struct s_node	*next;
}	t_node;

typedef struct s_all
{
	char	**envp;
	char	*line;
	char	**tokens;
	t_node	*stack;
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
int	ft_cd(t_all *shell);
int ft_env(t_all *shell);
int ft_export(t_all *shell);
int ft_unset(t_all *shell);
int ft_pwd(t_all *shell);
void    content_lexer(t_all *shell);
void    print_stack(t_node *stack);

#endif