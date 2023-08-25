/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/23 19:11:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	f_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return (1);
		n--;
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
	}
	return (0);
}

static int	strncmp_export(const char *t, const char *e)
{
	int	i;

	i = 0;
	while (t[i] && e[i])
	{
		if (t[i] == '=' && e[i] == '\0' && !f_strncmp(t, e, ft_strlen(e)))
			return (0);
		else if (t[i] == '\0' && e[i] == '=' && !f_strncmp(t, e, ft_strlen(e)))
			return (1);
		else if (t[i] == '\0' && e[i] == '\0' && !f_strncmp(t, e, ft_strlen(e)))
			return (1);
		else if (t[i] == '=' && e[i] == '=' && !f_strncmp(t, e, ft_strlen(e)))
			return (0);
		i++;
	}
	if (t[i] == '=' && e[i] == '\0' && !f_strncmp(t, e, ft_strlen(e)))
		return (0);
	else if (t[i] == '\0' && e[i] == '=' && !f_strncmp(t, e, ft_strlen(e)))
		return (1);
	else if (t[i] == '\0' && e[i] == '\0' && !f_strncmp(t, e, ft_strlen(e)))
		return (1);
	else if (t[i] == '=' && e[i] == '=' && !f_strncmp(t, e, ft_strlen(e)))
		return (0);
	return (-1);
}

static int	find_string_export(char **env, char *target)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (env)
	{
		while (env[i])
		{
			if (strncmp_export(target, env[i]) == 0)
			{
				a = i;
				break ;
			}
			if (strncmp_export(target, env[i]) == 1)
			{
				a = -2;
				break ;
			}
			i++;
		}
		if (!env[i])
			return (FT_INVALID_POS);
	}
	return (a);
}

static char	*load_target(char *s)
{
	char	*target;
	int		i;

	if (!check_name(s))
		return (NULL);
	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	target = NULL;
	target = (char *)malloc(sizeof(char) * (i + 2));
	if (!target)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
	{
		target[i] = s[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

int	ft_export(t_shell *shell, char *s)
{
	int		i;
	int		size_env;
	char	*target;

	target = NULL;
	target = load_target(s);
	if (!target)
		return (1);
	size_env = 0;
	while (shell->env[size_env])
		size_env++;
	i = 0;
	i = find_string_export(shell->env, s);
	if (i == FT_INVALID_POS)
		make_new_env(shell, s, size_env);
	else if (i == -2)
	{
		free(target);
		return (1);
	}
	else
		else_export(shell, s, i);
	free(target);
	return (0);
}
