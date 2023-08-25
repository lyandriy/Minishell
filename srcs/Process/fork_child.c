/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:44:09 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/25 18:29:01 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fork_child(t_shell *shell)
{
	t_child	*child;
	pid_t	pid;

	child = shell->childs->current->content;
	pid = fork();
	if (!pid)
		ft_child(shell, child);
	else
		child->pid = pid;
}
