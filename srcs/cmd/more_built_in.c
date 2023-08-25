/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:16:01 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/23 17:13:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	do_unset(t_cmd *cmd, t_shell *shell)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (cmd->argv[i])
	{
		ret = ft_unset(shell, cmd->argv[i]);
		i++;
	}
	return (ret);
}

int	do_export(t_cmd *cmd, t_shell *shell)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	if (cmd->argv[i] == NULL)
		sort_export(shell);
	else
	{
		while (cmd->argv[i])
		{
			if (cmd->argv[i][0] != '=')
			{
				if (ret == 0)
					ret = ft_export(shell, cmd->argv[i]);
				else if (ret == 1)
					ft_export(shell, cmd->argv[i]);
			}
			i++;
		}
	}
	return (ret);
}
