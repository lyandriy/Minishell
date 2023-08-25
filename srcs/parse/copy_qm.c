/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_qm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:33:59 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/23 18:50:35 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	else_copy(char *argv, int *count_copy, char *my_input, int *count)
{
	argv[*count_copy] = my_input[*count];
	*count += 1;
	*count_copy += 1;
}

int	copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy)
{
	char	skip;
	int		count;

	count = 1;
	skip = my_input[0];
	while (my_input[count] != skip && my_input[count] != '\0')
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
		{
			if (!ft_isalnum(my_input[count + 1]) && my_input[count + 1] != '?'
				&& my_input[count] != skip)
				argv_alnum(argv, count_copy, &count);
			else
				count += exp_var_qm(shell, &my_input[count], argv, count_copy);
		}
		else
			else_copy(argv, count_copy, my_input, &count);
	}
	if (count == 1)
		argv[*count_copy] = '\0';
	if (my_input[count] == skip)
		count++;
	return (count);
}
