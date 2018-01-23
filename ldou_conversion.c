/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldou_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:42:58 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/19 16:43:17 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ldou_conversion(t_data *data, va_list ap)
{
	(data->lm)[0] = 'l';
	(data->lm)[1] = '\0';
	if (data->c == 'D')
		return (d_conversion(data, ap));
	else if (data->c == 'O')
		return (o_conversion(data, ap));
	else
		return (ux_conversion(data, ap, 10));
}
