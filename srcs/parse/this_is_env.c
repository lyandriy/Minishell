/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_is_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:29:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/25 18:05:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*protected_ft_strjoin(char *s1, char *s2)
{
	char	*r;

	r = NULL;
	r = ft_strjoin(s1, s2);
	if (!r)
		exit(1);
	return (r);
}

void	copy_ev(char *environment_variabl, t_cmd *new_cmd, int *count_t)
{
	char	*ptr;

	if (new_cmd->argv[*count_t])
	{
		ptr = new_cmd->argv[*count_t];
		new_cmd->argv[*count_t] = protected_ft_strjoin(ptr,
				environment_variabl);
		free(ptr);
	}
	else
	{
		free(new_cmd->argv[*count_t]);
		new_cmd->argv[*count_t] = environment_variabl;
	}
	free(environment_variabl);
}

int	this_is_env(t_shell *shell, t_cmd *new_cmd, char *input, int *count_t)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (input[count] == '?')
	{
		environment_variabl = ft_itoa(shell->child_status);
		if (environment_variabl)
			copy_ev(environment_variabl, new_cmd, count_t);
		count++;
	}
	return (count);
}
