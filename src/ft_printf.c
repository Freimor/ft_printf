/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:38:52 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/04 15:23:20 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_type(t_printf work)
{
	while (ft_strchr("-+ 0#", work.format[work.anker]))
	{
		
	}
	
}

int		prec_scan(t_printf work)
{
	work.mod.remove_0 = 1;
	if (work.format[work.anker] == '*')
	{
		work.mod.precision = va_arg(work.list, int);
		work.anker++;
	}
	else if (work.format[work.anker] >= '0' && work.format[work.anker] <= '9')
	{
		if (ft_atoi(work.format[work.anker] == 0))
			work.mod.precision_zero = 1;
		else
			work.mod.precision = ft_atoi(work.format[work.anker] == 0);
		while (work.format[work.anker] >= '0' && work.format[work.anker] <= '9')
			work.anker++;
	}
	else
		work.mod.precision_zero = 1;
}

int		parse(t_printf work)
{
	char		*spec;
	char		arg;

	work.anker++;
	if (work.format[work.anker] == ft_strchr("-+ 0#", work.format[work.anker]))
		flag_scan(work);
	width_scan(work);
	if (work.format[work.anker] == '.')
		prec_scan(work);
	if (ft_strchr("lLhzjt", work.format))
		size_scan(work);
	if (ft_strchr("diouxXfcsp", work.format))
		type_scan(work);
	return (work.anker);
}

int		ft_printf(const char *format, ...)
{
	t_printf work;

	init_structure(work, (char *)format);
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
			parse(work);
		}
		//ft_putchar(format[work.anker]);
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
