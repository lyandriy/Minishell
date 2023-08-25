/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:33:32 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/23 18:51:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_argv(t_shell *shell, t_cmd *new_cmd)
{
	if (shell->s_i.copy == 0)
	{
		if (new_cmd->argv[shell->s_i.ctoken][0] == '\0')
			return ;
		if (new_cmd->argv[shell->s_i.ctoken])
			free(new_cmd->argv[shell->s_i.ctoken]);
		new_cmd->argv[shell->s_i.ctoken] = NULL;
	}
	else if (new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] != '\0')
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
}
