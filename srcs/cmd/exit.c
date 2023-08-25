/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:52:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/19 17:12:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		get_argv_size(char **argv);
static t_bool	is_all_number(char *s);

static void	with_exit_value(int *exit_value, t_cmd *cmd)
{
	*exit_value = ft_atoi(cmd->argv[1]);
	if (*exit_value < 0 || *exit_value > 256)
		*exit_value = (*exit_value % 256);
}

void	ft_exit(t_shell *shell, t_cmd *cmd)
{
	int		exit_value;
	int		size;

	exit_value = 0;
	size = get_argv_size(cmd->argv);
	if (size == FT_INVALID_POS)
	{
		ft_printf("Minishell: exit: too many arguments\n");
		g_shell->child_status = 1;
		return ;
	}
	if (cmd->argv[1])
	{
		if (!is_all_number(cmd->argv[1]))
		{
			ft_printf("bash: %s: numeric argument required\n",
				cmd->argv[1]);
			exit_value = 255;
		}
		else
			with_exit_value(&exit_value, cmd);
	}
	ft_cleanshell(shell);
	exit(exit_value);
}

static int	get_argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
		return (FT_INVALID_POS);
	return (i);
}

static t_bool	is_all_number(char *s)
{
	int		i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}
