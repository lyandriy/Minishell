/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:52:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 15:01:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(const char *dir, t_shell *shell)
{
	if (dir)
		change_dir(shell, (char *)dir);
	else
		ft_reset_to_default(shell);
}
