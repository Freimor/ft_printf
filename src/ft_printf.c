/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:38:52 by sskinner          #+#    #+#             */
/*   Updated: 2020/01/17 18:32:17 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf work;

	work.anker = 0;
	va_start(work.list, format);
	while (format[work.anker] != '\0')
	{
		if (format[work.anker] == '%')
		{
			write(1, format, work.anker);
			choose_specs(work);
		}
		work.anker++;
	}
}

int		choose_specs(t_printf work)
{
	char	*spec;

	ft_strncpy(spec, work.format + work.anker, 3);

	if(spec == "")
}