/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:20:49 by pzhang            #+#    #+#             */
/*   Updated: 2018/01/12 11:54:11 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_count(int num)
{
	int digit;

	if (num == -2147483648)
		return (10);
	digit = 1;
	if (num < 0)
		num *= -1;
	while (num >= 10)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}