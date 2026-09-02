/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 05:15:50 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/09/02 07:41:45 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void swap_vars(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void sort_env(char **envp)
{
	int	i;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (envp[i + 1])
		{
			if (ft_strcmp(envp[i], envp[i + 1]) > 0)
			{
				swap_vars(&envp[i], &envp[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}

static void print_one_var(char *var)
{
	int	j;

	printf("declare -x ");
	j = 0;
	while (var[j] && var[j] != '=')
	{
		putchar(var[j]);
		j++;
	}
	if (var[j] == '=')
	{
		if (ft_strlen(var + j + 1) > 0)
			printf("=\"%s\"", var + j + 1);
	}
	printf("\n");
}

static int count_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static char **copy_env(char **envp, int count)
{
	char	**sorted;
	int		i;

	sorted = malloc(sizeof(char *) * (count + 1));
	if (!sorted)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		sorted[i] = envp[i];
		i++;
	}
	sorted[i] = NULL;
	return (sorted);
}

void export_print(char **envp)
{
	char	**sorted;
	int		count;
	int		i;

	if (!envp)
		return ;
	count = count_env(envp);
	sorted = copy_env(envp, count);
	if (!sorted)
		return ;
	sort_env(sorted);
	i = 0;
	while (sorted[i])
	{
		print_one_var(sorted[i]);
		i++;
	}
	free(sorted);
}