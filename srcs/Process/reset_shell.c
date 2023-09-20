/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:06:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/20 15:49:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	reset_lst(t_lstmng *lst)
{
	lst->current = NULL;
	lst->lst_head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void	reset_shell(t_shell *shell)
{
	if (!init_signals(&(shell->sact)))
		exit(0);
	if (shell->cmds->lst_head)
		ft_lstclear(&(shell->cmds->lst_head), ft_cleancmd);
	reset_lst(shell->cmds);
	if (shell->childs->lst_head)
		ft_lstclear(&(shell->childs->lst_head), ft_cleanchild);
	reset_lst(shell->childs);
}
