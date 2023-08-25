/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:01:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/23 17:26:08 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(char	**env)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (env[i])
	{
		ret = should_be_env(env[i]);
		if (ret)
			printf("%s\n", env[i]);
		i++;
	}
	if (ret)
		return (0);
	return (1);
}
