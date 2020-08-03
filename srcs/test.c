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

#define	BASE	1000		//колво разрядов в ячейке
#define	SIZE	5000	//размер массива

int 	*init_masse()
{
	return(ft_memalloc(SIZE));
}

void	bigint_firstcut(int *masse, uint64_t num)	//первое наполнение массива
{
	int	i;

	i = 0;
	while (num != 0 && i < SIZE)
	{
		masse[i] = num % BASE;
		num /= BASE;
		i++;
	}
}

void	bigint_sum(int *masse, int *othermasse)
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
	}
}

int	main(void)
{
	long double num = 3.14;


	union_ldouble	*number;
	int				*masse;
	int				*othermasse;

	number = ft_memalloc(sizeof(union_ldouble));
	masse = init_masse();
	othermasse = init_masse();

	number->d = num;

	bigint_firstcut(masse, 900501);
	bigint_firstcut(othermasse, 500);
	bigint_sum(masse, othermasse);

	int i = 0;
	while (masse[i] != 0)	//плохой вывод
	{
		printf("%d ", masse[i]);
		i++;
	}
	printf ("\nnumber-> %d\n", 900500);
	return (0);
}
