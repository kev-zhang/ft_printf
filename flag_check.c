/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:39:40 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/16 15:41:02 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_check(char *flags, char flag)
{
	int	i;

	i = 0;
	while (i < 5 && flags[i])
	{
		if (flags[i] == flag)
			return (1);
		i++;
	}
	return (0);
}
