/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:44:50 by sskinner          #+#    #+#             */
/*   Updated: 2020/01/23 13:05:27 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_type(t_modlayer mod, t_printf work)
{
	unsigned char	arg;
	int				len;

	//len = mod.field_len;
	mod.orientation = 0;
	len = 1;
	arg = va_arg(work.list, int);

	if (mod.orientation)
		write(1, &arg, 1);
	if (mod.zeromod)
	{
		while (len - 1 != 0)
			ft_putchar('0');
	}
	else
	{
		while (len - 1 != 0)
			ft_putchar(' ');
	}
	if (!mod.orientation)
		write(1, &arg, 1);
	return (1);
}