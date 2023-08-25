/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_oculto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:55:44 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/23 18:52:39 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	error(void)
{
	perror("cd");
	return (1);
}

int	ft_cd(const char *dir, t_shell *shell)
{
	int	pos;

	if (!dir)
	{
		pos = find_string(shell->env, "HOME");
		if (pos >= 0)
		{
			if (chdir(&shell->env[pos][5]))
				return (error());
		}
		else
		{
			ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
	{
		if (chdir(dir))
			return (error());
	}
	return (0);
}
