/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   none_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:39:05 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 18:42:56 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		none_conversion(t_data *data)
{
	int		i;
	char	c;

	if ((data->fw)[0] == 0)
		return (0);
	i = 0;
	c = ' ';
	if (flag_check(data->f, '0') == 1)
		c = '0';
	while (i < (data->fw)[1] - 1)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}
