/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:26:31 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 15:35:40 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_conversion_helper(t_data *data, long long n)
{
	if (flag_check(data->f, '0') == 1)
	{
		if (n < 0)
			ft_putchar('-');
		else if (flag_check(data->f, '+'))
			ft_putchar('+');
		else if (flag_check(data->f, ' '))
			ft_putchar(' ');
	}
}
