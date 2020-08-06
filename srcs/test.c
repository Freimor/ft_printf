/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:17:29 by rick              #+#    #+#             */
/*   Updated: 2020/06/07 22:13:29 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define	BASE	100		//колво разрядов в ячейке
#define	SIZE	5000	//размер массива

//переписать под функции bcharity
uint64_t	ft_pow(uint64_t base, uint64_t step)
{
	uint64_t	num;

	num = 1;
	while (step - 1)
	{
		num *= base;
		step--;
	}
	return (num);
}

uint64_t 	*init_masse()
{
	return(ft_memalloc(sizeof(uint64_t) * SIZE));
}

/*void	bigint_firstcut(uint64_t *masse, uint64_t num)	//первое наполнение массива
{
	int	i;

	i = 0;
	while (num != 0 && i < SIZE)
	{
		masse[i] = num % BASE;
		num /= BASE;
		i++;
	}
}*/

void	bigint_num2longmasse(uint64_t *masse, uint64_t num)
{
	int i;

	i = 0;
	while (num != 0 && i < SIZE - 1)
	{
		masse[i + 1] = num % BASE;
		num /= BASE;
		i++;
		masse[0]++;
	}
}

uint64_t	*mul_l(uint64_t *buf1, uint64_t *buf2, uint64_t *res)
{
	unsigned long long	c;
	unsigned			i;
	unsigned			j;
	unsigned			maxlen;

	res[0] = buf1[0] + buf2[0];
	maxlen = res[0];
	i = 1;
	while (i < maxlen)
	{
		c = 0;
		j = 1;
		while (j < maxlen)
		{
			c = c + buf1[j] * buf2[i] + res[j];
			res[j] = c % BASE;
			c = c / BASE;
			j++;
		}
		i++;
	}
	return (res);
}

void	bigint_sum(uint64_t *masse, uint64_t *othermasse)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		masse[i] += othermasse[i];
		i++;
	}
	i = 0;
	while (i < SIZE - 1)
	{
		if (masse[i] >= BASE)
		{
			masse[i] -= BASE;
			masse[i + 1]++;
		}
		i++;
	}//не удалял othermasse
}

/*int		*bigint_multi(int *masse, int *othermasse)	//попробовать переписать на использование bigint_sum
{
	int	i;
	int	j;
	int	*result;

	i = 0;
	j = 0;
	result = init_masse();
	while (i < SIZE)
	{
		while (j < SIZE - 1)
		{
			result[i + j] += masse[i] * othermasse[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < SIZE - 1)
	{
		result[i + 1] += result[i] / BASE;
		result[i] %= BASE;
		i++;
	}
	return (result);
}*/

void	bigint_multi(uint64_t *masse, uint64_t num)
{
	uint64_t	c;
	int	i;

	c = 0;
	i = 0;
	while (i < SIZE)
	{
		c = masse[i] * num + c;
		masse[i] = c % BASE;
		c = c / BASE;
		if (i == masse[0] && c != 0)
		{
			masse[0]++;
			masse[masse[0]] = c;
			break ;
		}
		i++;
	}
}

int	main(void)
{
	long double num = 10;


	union_ldouble	*number;
	uint64_t		*masse;
	uint64_t		*othermasse;
	uint64_t		*resultmasse;
	//int				*result;

	number = ft_memalloc(sizeof(union_ldouble));
	masse = init_masse();
	othermasse = init_masse();
	resultmasse = init_masse();

	number->d = num;

	bigint_num2longmasse(masse, number->bits.mantissa);

	if (number->bits.exponent - 16383 - 63 < 0)
	{
		bigint_num2longmasse(othermasse, ft_pow(5, 16383 + 63 - number->bits.exponent));
		resultmasse = mul_l(masse, othermasse, resultmasse);
	}
	else if (number->bits.exponent - 16383 - 63 >= 0)
	{
		bigint_num2longmasse(othermasse, ft_pow(2, number->bits.exponent - 16383 - 63));
		resultmasse = mul_l(masse, othermasse, resultmasse);
	}
	int i = 0;
	while (i <= resultmasse[0])
	{
		printf("%llu ", resultmasse[i]);
		i++;
	}
	return (0);
}
