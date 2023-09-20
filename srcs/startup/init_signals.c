/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:01:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/20 15:38:01 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	set_sig(struct sigaction *sact, int signal);

t_bool	init_signals(struct sigaction *sact)
{
	if (sigemptyset(&sact->sa_mask))
	{
		ft_printf("ERROR: sigemptyset fail\n");
		return (false);
	}
	sact->sa_flags = 0;
	sact->sa_handler = &sig_handler;
	if (!set_sig(sact, SIGINT))
		return (false);
	signal(SIGQUIT, SIG_IGN);
	return (true);
}

static int	set_sig(struct sigaction *sact, int signal)
{
	if (sigaddset(&sact->sa_mask, signal) == -1)
	{
		ft_printf("ERROR: sigaddset fail");
		return (0);
	}
	if (sigaction(signal, sact, NULL) == -1)
	{
		ft_printf("ERROR: sigaction fail");
		return (0);
	}
	return (5555);
}
