/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:15:38 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/22 16:05:43 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_data
{
	char		c; //conversion
	char		f[5]; //flag(s)
	int			fw[2]; //min field-width, [0] is checker, [1] is value
	int			p[2]; //precision, [0] is checker, [1] is value
	char		lm[2]; //length modifier
}				t_data;

int				ft_printf(const char *str, ...);
int				checker(char c);
int				set_flag(t_data *data, char c);
int				set_modifier(t_data *data, char *f);
int				process_data(t_data *data, va_list ap);
int				flag_check(char *flags, char flag);
int				putnbr_base(unsigned long long n, int *p, int base);
int				putnbr_base_cap(unsigned long long n, int *p, int base);
void			putwchar(wchar_t c);
int				zero_prec(t_data *data);
int				empty_str(t_data *data, char *n);

int				s_conversion(t_data *data, va_list ap);
int				ls_conversion(t_data *data, va_list ap);
int				d_conversion(t_data *data, va_list ap);
void			d_conversion_helper(t_data *data, long long n);
int				ux_conversion(t_data *data, va_list ap, int base);
int				o_conversion(t_data *data, va_list ap);
int				x_cap_conversion(t_data *data, va_list ap);
int				ldou_conversion(t_data *data, va_list ap);
int				c_conversion(t_data *data, va_list ap);
int				lc_conversion(t_data *data, va_list ap);
int				p_conversion(t_data *data, va_list ap);
int				perc_conversion(t_data *data);

#endif
