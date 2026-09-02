/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:38:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 08:24:32 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
#include "pipex/pipex.h"
# include <stdlib.h>
# include <stdio.h>
#include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

#define WORD 0
#define PIPE 1
#define REDIR_IN 2
#define REDIR_OUT 3
#define REDIR_APPEND 4
#define REDIR_HERE 5

typedef struct s_node
{
	char			*content;
	int				type;
	int				id;
	int				quoted;
	struct s_node	*next;
}					t_node;

typedef struct s_files
{
	char						*path;
	int							mode;
	char						**heredoc_content;
	struct s_files				*next;
}								t_files;

typedef struct s_cmd
{
	int							type;
	char						**args;
	t_files						*files;
	struct s_cmd				*next;
}								t_cmd;

typedef struct s_all
{
	char	**envp;
	char	*line;
	char	**tokens;
	t_node	*stack;
	t_files	*files;
	t_cmd	*command;
	int		last_status;
}	t_all;

int	parsing_all(t_all *shell);
int is_sep(char c);
int is_operator(char c);
void    readline_shell(t_all *shell);
void	split_line(t_all *shell);
int exec_shell(t_all *shell);
int ft_echo(t_all *shell);
void	free_all(t_all *shell);
int	close_shell(t_all *shell);
int	is_quote(char c);
void	free_tokens_tab(char **tokens, int j);
int	ft_cd(t_all *shell);
int ft_env(t_all *shell);
int ft_export(t_all *shell);
int ft_unset(t_all *shell);
int ft_pwd(t_all *shell);
void    content_lexer(t_all *shell);
void    print_stack(t_node *stack);
int lst_size(t_all *shell);
int parse_pipe(t_all *shell);
int parse_redir(t_all *shell);
int is_redir(int type);
int parse_quote(t_all *shell);
int build_commands(t_all *shell);
int exec_pipeline(t_all *shell);
int is_builtin_cmd(char *cmd);
int	export_is_valid_name(const char *name);
char	*export_get_value(char **envp, const char *name);
int	export_add_or_update(t_all *shell, const char *name, const char *value);
void	export_print(char **envp);
int	ft_export(t_all *shell);
void	expand_all_tokens(t_all *shell);
void	init_signals(void);
int	handle_heredoc(t_all *shell, char *delimiter, int quoted, char **outfile);
char    *expand_string(t_all *shell, char *str);
char *strip_outer_quotes(char *str);

# endif