/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:19:49 by rick              #+#    #+#             */
/*   Updated: 2020/06/03 19:29:21 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_bits(size_t size, void *ptr, unsigned char space)
{
	unsigned char *b;
	unsigned char byte;
	int i;
	int j;

	b = (unsigned char*)ptr;
	i = size - 1;
	j = 7;
	while (i >= 0)
	{
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar(byte + '0');
			j--;
		}
		if (space == 1)
			ft_putchar(' ');
		j = 7;
		i--;
	}
	ft_putchar('\n');
}