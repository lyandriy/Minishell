/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/20 16:33:54 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	do_build_in(t_cmd *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd->argv[0], "echo"))
		shell->child_status = echo(cmd);
	if (ft_strcmp(cmd->argv[0], "cd"))
		shell->child_status = ft_cd(cmd->argv[1], shell);
	if (ft_strcmp(cmd->argv[0], "pwd"))
		shell->child_status = ft_pwd(shell->env);
	if (ft_strcmp(cmd->argv[0], "export"))
		do_export(cmd, shell);
	if (ft_strcmp(cmd->argv[0], "unset"))
		do_unset(cmd, shell);
	if (ft_strcmp(cmd->argv[0], "env"))
		shell->child_status = ft_env(shell->env);
	if (ft_strcmp(cmd->argv[0], "exit"))
		ft_exit(shell, cmd);
	return (shell->child_status);
}
