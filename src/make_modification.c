/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_modification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:38:40 by sskinner          #+#    #+#             */
/*   Updated: 2020/01/23 13:40:04 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		detect_modification(t_printf work)
{
	t_modlayer mod;

	while (work.format[work.anker] != '\0'
		|| work.format[work.anker] != 'c'
		|| work.format[work.anker] != 's'
		|| work.format[work.anker] != 'p'
		|| work.format[work.anker] != 'd'
		|| work.format[work.anker] != 'i'
		|| work.format[work.anker] != 'o'
		|| work.format[work.anker] != 'u'
		|| work.format[work.anker] != 'x'
		|| work.format[work.anker] != 'X'
		|| work.format[work.anker] != 'f')
		work.anker++;
	if (work.format[work.anker] != '\0')
	{
		mod.type = work.format[work.anker];
		work.currentmod = mod;
	}
	else
		return (-1);
	return (0);
}

int		mod_update(t_printf work)
{
	//проверить на допустимые формату спецификаторы
}