/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:59:29 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 14:28:24 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_data_help(t_data *data, va_list ap)
{
	if (data->c == 'c')
		return (c_conversion(data, ap)); //done!!!
	else if (data->c == 'C')
		return (lc_conversion(data, ap)); //done!!!
	return (0); //remove line later if necessary!
}

int			process_data(t_data *data, va_list ap)
{
	if (data->c == 's')
		return (s_conversion(data, ap)); //done!!!
	else if (data->c == 'S')
		return (ls_conversion(data, ap)); //done!!!
	else if (data->c == 'p')
		return (p_conversion(data, ap)); //done!!!
	else if (data->c == 'i' || data->c == 'd')
		return (d_conversion(data, ap)); //done!!!
	else if (data->c == 'o')
		return (o_conversion(data, ap)); //done!!!
	else if (data->c == 'u')
		return (ux_conversion(data, ap, 10)); //done!!!
	else if (data->c == 'x')
		return (ux_conversion(data, ap, 16)); //done!!!
	else if (data->c == 'X')
		return (x_cap_conversion(data, ap)); //done!!!
	else if (data->c == 'D' || data->c == 'O' || data->c == 'U')
		return (ldou_conversion(data, ap)); //done!!!
	else if (data->c == '%')
		return (perc_conversion(data)); //CURRENT
	else
		return (process_data_help(data, ap));
}
