/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:33 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/23 18:51:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) || ft_isdigit(s[i]))
		{
			ft_printf("%s: %s: '%s': %s\n",
				"Minishel",
				"export",
				s,
				"not a valid identifier");
			return (false);
		}
		i++;
	}
	return (true);
}

void	else_export(t_shell *shell, char *s, int i)
{
	free(shell->env[i]);
	shell->env[i] = ft_strdup(s);
	if (!shell->env[i])
		ft_error(shell, errno);
}
