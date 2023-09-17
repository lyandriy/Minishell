/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:28:33 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/17 17:39:17 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(t_shell *shell, errno_t error_code)
{
	t_child	*child;

	if (error_code && shell)
	{
		child = shell->childs->current->content;
		perror(child->cmd->argv[0]);
	}
	exit(error_code);
}
