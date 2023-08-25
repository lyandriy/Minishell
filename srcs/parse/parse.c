/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:51:33 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/23 19:32:52 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	parse(t_shell *shell, char *input)
{
	if (!check_pipes(shell, input))
	{
		shell->child_status = 258;
		return (false);
	}
	separation(shell, input);
	return (true);
}
