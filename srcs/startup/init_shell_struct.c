/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:01:43 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:42:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	init_lstmng(t_shell *local_shell)
{
	if (ft_lstmngnew(NULL, &(local_shell->childs)))
	{
		if (ft_lstmngnew(NULL, &(local_shell->cmds)))
		{
			return (true);
		}
		free(local_shell->childs);
	}
	return (false);
}

t_bool	init_shell_struct(t_shell **shell)
{
	t_shell	*local_shell;

	local_shell = (t_shell *)malloc(sizeof(t_shell));
	if (local_shell)
	{
		local_shell->self_pid = getpid();
		if (init_lstmng(local_shell))
		{
			*shell = local_shell;
			return (true);
		}
		free(local_shell);
	}
	return (false);
}
