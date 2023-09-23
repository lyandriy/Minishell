/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_env_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:19:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/23 16:29:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		get_leght_of_env(char **env);
static char		**selective_clone(char **env, char **local_env);

t_bool	clone_env_init(char **env, t_shell *shell)
{
	char	**local_env;
	int		size;

	local_env = NULL;
	size = get_leght_of_env(env);
	local_env = (char **)malloc(sizeof(char *) * (size + 1));
	if (!local_env)
		return (false);
	local_env = selective_clone(env, local_env);
	if (!local_env)
		return (false);
	shell->env = local_env;
	if (!update_shell_lvl(shell))
		return (false);
	return (true);
}

static int	get_leght_of_env(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (should_be_env(env[i + j]))
			i++;
		else
			j++;
	}
	return (i);
}

static char	**selective_clone(char **env, char **local_env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i + j])
	{
		if (should_be_env(env[i + j]))
		{
			local_env[i] = NULL;
			local_env[i] = ft_strdup(env[i + j]);
			if (!local_env[i])
			{
				free_clone_env(local_env);
				return (NULL);
			}
			i++;
		}
		else
			j++;
	}
	local_env[i] = NULL;
	return (local_env);
}
