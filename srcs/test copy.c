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

/*int	protect_float(union_ldouble *num)
{
	if ( *num->bits.mantissa(or exponent) all 0*) || ( *num->bits.mantissa(or exponent) all 1*)  //its NaN
		return (1)
	return (0);
}*/

int make_exponent(union_ldouble *num)
{
	int exp;
	
	exp = (int)num->bits.exponent - 16383;
	return (exp);
}
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

void	brut_shit(int *masse, uint64_t mantis)
{
	int	flag;
	int	i;

	flag = 1;
	i = 1;
	while (flag)
	{
		if (mantis / 10 > 0)
		{
			masse[i] = mantis % 10;
			mantis /= 10;
		}
		else
		{
			masse[i] = mantis;
			flag = 0;
		}
		i++;
	}
	masse[0] = i - 1;
}

void	masse_sum_one(int *masse, int num)
{
	int	i;
	int buff;

	i = 1;
	buff = num;
	while (buff != 0)
	{
		if (i == masse[0] + 1)
			masse[0]++;
		buff += masse[i];
		masse[i] = buff % 10;
		buff /= 10;
		i++;
	}
}

void	masse_summation(int *masse, int *add_mass)
{
	int	i;
	int	j;

	i = 1;
	while (i < add_mass[0] + 1)
	{
		masse_sum_one(masse, add_mass[i] * ft_pow(10, i));
		i++;
	}
}

void	masse_multiply(int *masse, uint64_t num)
{
	int	masse_2[5000];
	int	i;

	i = 0;
	while (i < masse[0] + 1)
	{
		masse_2[i] = masse[i];
		i++;
	}
	masse_2[0] = masse[0];
	while (num - 1)
	{
		masse_summation(masse, masse_2);
		num--;
	}
}

uint64_t	*mul_s(uint64_t *buf, unsigned dig)
{
	uint64_t	c;
	unsigned	i;

	c = 0;
	i = 1;
	while (i <= buf[0])
	{
		c = buf[i] * dig + c;
		buf[i] = c % 10; //BASE
		c = c / 10; //BASE
		if (i == buf[0] && c != 0)
		{
			buf[0]++;
			buf[buf[0]] = c;
			break ;
		}
		i++;
	}
	return (buf);
}

void make_float_great_again(long double num)		//ldouble to str
{
	union_ldouble	*number;
	int				masse[5000];
	int				add_mass[5000];
	int				i;
	uint64_t		m;

	number = ft_memalloc(sizeof(union_ldouble));
	
	number->d = num;
	
	//brut_shit(masse, number->bits.mantissa);
	brut_shit(masse, number->bits.mantissa);
	
	/*if (number->bits.exponent - 16383 - 63 < 0)
	{
		m = ft_pow(5, 16383 + 63 - number->bits.exponent);
		masse_multiply(masse, m);
	}
	else if (number->bits.exponent - 16383 - 63 > 0)
	{
		m = ft_pow(2, number->bits.exponent - 16383 - 63);
		masse_multiply(masse, m);
	}*/

	//masse_summation(masse, add_mass);
	//masse_multiply(masse, 595683);
	
	i = masse[0];
	while (i)
	{
		printf("%d", masse[i]);
		i--;
	}
	printf("   sum -> %d", masse[0]);
	printf("\n");
}

/*void make_float_great_again(long double num)
{
	union_ldouble	*number;
	int				*masse;
	int				*add_mass;
	int				i;
	uint64_t		m;

	i = 0;
	number = ft_memalloc(sizeof(union_ldouble));
	masse = ft_memalloc(5000);
	add_mass = ft_memalloc(5000);
	
	number->d = num;
	brut_shit(masse, number->bits.mantissa);
	if (number->bits.exponent - 16383 - 63 < 0)
	{
		m = ft_pow(5, 16383 + 63 - number->bits.exponent);
		masse_multiply(masse, m);
	}
	else if (number->bits.exponent - 16383 - 63 > 0)
	{
		m = ft_pow(2, number->bits.exponent - 16383 - 63);
		masse_multiply(masse, m);
	}
	while (masse[i] != -1)
	{
		printf("%d", masse[i]);
		i++;
	}
	printf("\n");
	//printf("mantiss -> %lu\n", number->bits.mantissa);
	
}*/

int	main(void)
{
	long double a;

	a = 3.14;

	make_float_great_again(a);
}