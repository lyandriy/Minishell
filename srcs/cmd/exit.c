/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:52:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/23 15:04:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		get_argv_size(char **argv);
static t_bool	is_all_number(char *s);
static void		is_first_parameter_a_char(int *exit_value, t_cmd *cmd);

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
	is_first_parameter_a_char(&exit_value, cmd);
	if (size > 2)
		ft_printf("Minishell: exit: too many arguments\n");
	if (size <= 2)
	{
		ft_cleanshell(shell);
		ft_printf("exit\n");
		exit(exit_value);
	}
}

static int	get_argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
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

static void	is_first_parameter_a_char(int *exit_value, t_cmd *cmd)
{
	if (cmd->argv[1])
	{
		if (!is_all_number(cmd->argv[1]))
		{
			ft_printf("bash: %s: numeric argument required\n",
				cmd->argv[1]);
			*exit_value = 255;
			ft_printf("exit\n");
			exit(*exit_value);
		}
		else
			with_exit_value(exit_value, cmd);
	}
}
