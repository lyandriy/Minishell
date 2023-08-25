/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:39:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/23 18:46:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_shell->child_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		g_shell->child_status = 131;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("QUIT: 3", 0);
		rl_on_new_line();
	}
}
