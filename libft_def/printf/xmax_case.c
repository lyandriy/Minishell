/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmax_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:06:26 by vicgarci          #+#    #+#             */
/*   Updated: 2023/09/23 16:22:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	calc_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	xmax_case(unsigned int hexa)
{
	int					i;

	i = 0;
	if (hexa == 0)
		i += write(2, "0", 1);
	else
	{
		i = calc_hexa_len(hexa);
		ft_putuhexa_fd(hexa, 2, 1);
	}
	return (i);
}
