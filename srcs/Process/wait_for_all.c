/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:06:21 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/25 18:32:10 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_for_all(t_shell *shell)
{
	t_child	*child;
	int		status;

	shell->childs->current = shell->childs->lst_head;
	while (shell->childs->current)
	{
		child = shell->childs->current->content;
		waitpid(child->pid, &status, 0);
		if (child->is_limit_end)
		{
			shell->child_status = WEXITSTATUS(status);
			if (WIFSIGNALED(status))
				shell->child_status = WIFSIGNALED(status);
		}
		shell->childs->current = shell->childs->current->next;
	}
}
