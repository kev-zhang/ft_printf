/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:18:45 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 14:28:14 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(t_data *data)
{
	int	i;

	i = 1;
	if (flag_check(data->f, '-') == 1)
	{
		ft_putchar('%');
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
	}
	else if (flag_check(data->f, '0') == 1)
	{
		while ((data->fw)[1] > i++)
			ft_putchar('0');
		ft_putchar('%');
	}
	else
	{
		while ((data->fw)[1] > i++)
			ft_putchar (' ');
		ft_putchar('%');
	}
	return ((data->fw)[1]);
}

int			perc_conversion(t_data *data)
{
	if ((data->fw)[0] == 1 && (data->fw)[1] > 1)
		return (helper(data));
	ft_putchar('%');
	return (1);
}
