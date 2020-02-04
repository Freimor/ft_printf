/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:26:29 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/04 14:51:28 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_structure(t_printf work, char *format)
{
    work.stroke = format;
    work.anker = 0;
    work.mod.flag = ft_strnew(5);
}