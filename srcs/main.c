/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/23 19:42:44 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;

	(void) argc;
	(void) argv;
	if (start(&shell, env))
	{
		g_shell = shell;
		while (true)
		{
			input = readline(PROMPT);
			if (input)
			{
				add_history(input);
				if (parse(shell, input))
					process_executer(shell);
				free(input);
				input = NULL;
			}
			else
				sig_d(shell);
		}
	}
}
