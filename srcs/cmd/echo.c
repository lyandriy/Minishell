/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:43:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/25 16:59:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_n(t_cmd *cmd)
{
	int	count;
	int	i;

	count = 1;
	while (cmd->argv[count])
	{
		i = 0;
		if (cmd->argv[count][i] == '-')
		{
			i++;
			while (cmd->argv[count][i] == 'n')
				i++;
			if (cmd->argv[count][i] != '\0')
				break ;
		}
		else
			break ;
		count++;
	}
	return (count);
}

static void	print_echo(t_cmd *cmd, int i)
{
	while (cmd->argv[i])
	{
		printf("%s", cmd->argv[i]);
		i++;
		if (cmd->argv[i])
			printf(" ");
	}
}

int	echo(t_cmd *cmd)
{
	int	count;

	count = check_n(cmd);
	if (cmd->argv && cmd->argv[1] && count > 1)
		print_echo(cmd, count);
	else
	{
		print_echo(cmd, 1);
		printf("\n");
	}
	return (0);
}
