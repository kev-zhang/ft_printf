/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:55:06 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 16:41:51 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_str_help(char *str, t_data *data, int len, int check)
{
	int	i;
	int	pad;

	i = 0;
	pad = (data->fw)[1] - len;
	if (pad < 0)
		pad = 0;
	while (i < pad)
	{
		if (check == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
	free(str);
	return(i + len);
}

static int		print_str(char *str, t_data *data, int i, int len)
{
	if ((data->fw)[0] == 0)
	{
		ft_putstr(str);
		free(str);
		return(len);
	}
	if (flag_check(data->f, '-') == 1)
	{
		while (i < len)
			ft_putchar(str[i++]);
		while (i < (data->fw)[1])
		{
			ft_putchar(' ');
			i++;
		}
		free(str);
		return (i);
	}
	return (print_str_help(str, data, len, flag_check(data->f, '0')));
}

static void		process_precision(char *str, int p)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	while (str[i] && i < p)
		i++;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

int				s_conversion(t_data *data, va_list ap)
{
	char	*str;
	char	*orig_str;
	char	str_null[7];

	if ((data->lm)[0] == 'l' && (data->lm)[1] == '\0')
		return (ls_conversion(data, ap));
	orig_str = va_arg(ap, char*);
	if (orig_str == NULL)
	{
		str_null[0] = '(';
		str_null[1] = 'n';
		str_null[2] = 'u';
		str_null[3] = 'l';
		str_null[4] = 'l';
		str_null[5] = ')';
		str_null[6] = '\0';
		return (empty_str(data, str_null));
	}
	str = ft_strdup(orig_str);
	if ((data->p)[0] == 1)
		process_precision(str, (data->p)[1]);
	return (print_str(str, data, 0, (int)ft_strlen(str)));
}
