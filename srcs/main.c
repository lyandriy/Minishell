/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/20 17:37:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	leakss(void)
{
	system("leaks minishell");
}
*/

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
