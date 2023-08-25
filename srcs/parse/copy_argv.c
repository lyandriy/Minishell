/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:14:17 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/25 18:06:19 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_end(int *c, int *size, char *input)
{
	if (input[*c + 1] == '\0')
	{
		*size += 1;
		*c += 1;
	}
	else
	{
		*size += 2;
		*c += 2;
	}
}

static void	copy_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	if (!ft_isalnum(input[*c + 1]) && input[*c + 1] != '?')
	{
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = input[*c];
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy + 1]
			= input[*c + 1];
		check_end(c, &shell->s_i.copy, input);
		while (!ft_strchr("| \t><$", input[*c]) && input[*c])
		{
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = input[*c];
			shell->s_i.copy += 1;
			*c += 1;
		}
	}
	if (input[*c] && input[*c + 1] == '?')
	{
		if (new_cmd->argv[shell->s_i.ctoken] && new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] != '\0')
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
		*c += this_is_env(shell, new_cmd, &input[*c], &shell->s_i.ctoken);
		shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
	}
	else if (input[*c])
		else_variable(shell, new_cmd, input, c);
}

int	variable_type(char *input, t_shell *shell, t_cmd *new_cmd, int *i)
{
	int	c;

	c = 0;
	if (is_34_or_39(input[c + 1]))
	{
		c++;
		c += copy_qm(shell, new_cmd->argv[*i], &input[c], &shell->s_i.copy);
	}
	else
		copy_variable(shell, new_cmd, input, &c);
	return (c);
}

void	join_str(t_cmd *new_cmd, int *i, t_shell *shell, char input)
{
	char	*ptr;
	char	a[2];

	if (new_cmd->argv[*i][shell->s_i.copy] != '\0')
		new_cmd->argv[*i][shell->s_i.copy] = '\0';
	ptr = new_cmd->argv[*i];
	a[0] = input;
	a[1] = '\0';
	new_cmd->argv[*i] = protected_ft_strjoin(ptr, a);
	free(ptr);

}


void	copy_argv(t_shell *shell, t_cmd *new_cmd, char *input)
{
	int	c;
	int	*i;

	c = 0;
	i = &shell->s_i.ctoken;
	shell->s_i.copy = 0;
	while (input[c] != ' ' && input[c] != '\t' && input[c]
		&& !is_pipe(input[c]) && !is_greater_or_smaller(input[c]))
	{
		if (is_34_or_39(input[c]))
			c += copy_qm(shell, new_cmd->argv[*i], &input[c], &shell->s_i.copy);
		if (input[c] == '$')
			c += variable_type(&input[c], shell, new_cmd, i);
		else if (input[c] != ' ' && input[c] != '\t' && input[c]
			&& !is_pipe(input[c]) && !is_greater_or_smaller(input[c])
			&& !is_34_or_39(input[c]) && input[c] != '$')
		{
			if (new_cmd->argv[*i])
				join_str(new_cmd, i, shell, input[c]);
			new_cmd->argv[*i][shell->s_i.copy] = input[c];
			c++;
			shell->s_i.copy++;
		}
	}
	check_argv(shell, new_cmd);
}
