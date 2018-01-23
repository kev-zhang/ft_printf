/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:42:01 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 18:06:06 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlen_w(wchar_t *str, int *p)
{
	int	i;

	i = 0;
	if (p[0] == 1)
	{
		while (str[i] != L'\0' && i < p[1])
			i++;
	}
	else
	{
		while (str[i] != L'\0')
			i++;
	}
	return (i);
}

static int	print_str(wchar_t *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		putwchar(str[i]);
		i++;
	}
	return (len);
}

static int	helper(t_data *data, wchar_t *str, int i)
{
	int	temp;

	temp = i;
	if (flag_check(data->f, '-') == 1)
	{
		print_str(str, temp);
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
	}
	else if (flag_check(data->f, '0') == 1)
	{
		while ((data->fw)[1] > i++)
			ft_putchar('0');
		print_str(str, temp);
	}
	else
	{
		while ((data->fw)[1] > i++)
			ft_putchar(' ');
		print_str(str, temp);
	}
	return ((data->fw)[1]);
}

int			ls_conversion(t_data *data, va_list ap)
{
	wchar_t	*str;
	int		i;

	str = va_arg(ap, wchar_t*);
	i = strlen_w(str, data->p);
	if ((data->fw)[0] == 1 && (data->fw)[1] > i)
		return (helper(data, str, i));
	else
		return (print_str(str, strlen_w(str, data->p)));
}
