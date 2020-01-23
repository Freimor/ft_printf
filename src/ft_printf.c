/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:38:52 by sskinner          #+#    #+#             */
/*   Updated: 2020/01/23 13:40:14 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		choose_specs(t_printf work)
{
	char		*spec;
	char		arg;

	if (detect_modification(work) != -1)
		mod_update(work.currentmod);
	else
		return (-1);
	work.anker++;
	if (work.format[work.anker] == 'c')
		c_type(work.currentmod, work);
	if (work.format[work.anker] == '*')
	{
		arg = va_arg(work.list, int);
		work.anker++;
	}
	return (work.anker);
}

int		ft_printf(const char *format, ...)
{
	t_printf work;

	work.anker = 0;
	work.format = (char *)format;
	va_start(work.list, format);
	while (work.format[work.anker] != '\0')
	{
		if (work.format[work.anker] == '%')
		{
			if (work.format[work.anker + 1] == '%')
			{
				ft_putchar('%');
				break ;
			}
			work.anker = choose_specs(work);
		}
		ft_putchar(format[work.anker]);
		work.anker++;
	}
	return (0);
}

int		main()
{
	char a = 'g';
	printf("saske %c", a);
	ft_printf(" saske %c", a);
	return (0);
}
